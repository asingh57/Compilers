#pragma once
#include "Instruction.h"
#include <list>

class IntList {

	std::vector<std::string> _vars; //vars to be initialised in function scope
	bool _isStatic;
	std::vector<std::string> _varNames;
	std::map<std::string, int> _stackOffsets;//stack offsets for each var declared in scope relative to $sp
public:
	static IntList* globalIntList;
	IntList() {}
	IntList(std::string intList) : _vars(), _isStatic(false), _stackOffsets(), _varNames(){
		auto ls = split(intList.c_str(), ':');
		_isStatic = (ls[0] == "static-int-list");

		if (ls.size()>1) {
			auto varString = ls[1];
			_vars = split(varString.c_str());
		}

		globalIntList = this;
	}

	std::vector<std::string> getVarNames(){
		return _varNames;
	}

	std::string getLoadInstruction(std::string var, std::string correspondingReg,int index) {
		std::ostringstream loadInst;

		if (_stackOffsets.count(var)) { //contained in function scope
			int toLoad = _stackOffsets[var] + 4 * index;
			loadInst << "lw " << correspondingReg << "," << toLoad << "($sp)";
		}
		else {
			//contained in global scope
			int toLoad = globalIntList->_stackOffsets[var] + 4 * index;
			loadInst << "lw " << correspondingReg << "," << toLoad << "($v1)";
		}

		return loadInst.str();
	}

	std::string getStoreInstruction(std::string var, std::string correspondingReg, int index) {
		std::ostringstream storeInst;

		if (_stackOffsets.count(var)) { //contained in function scope
			int toStore = _stackOffsets[var] + 4 * index;
			storeInst << "sw " << correspondingReg << "," << toStore << "($sp)";
		}
		else {
			//contained in global scope
			int toStore = globalIntList->_stackOffsets[var] + 4 * index;
			storeInst << "sw " << correspondingReg << "," << toStore << "($v1)";
		}

		return storeInst.str();

	}

	std::string getLoadInstruction(std::string var, std::string correspondingReg, std::string spareRegister, std::string indexReg) {
		std::ostringstream loadInst;

		loadInst << "mov " << spareRegister << "," << indexReg <<std::endl;
		//multiply by 4
		loadInst << "sll " << spareRegister << ",2" << std::endl;


		std::string loadFrom;
		int toLoad;
		if (_stackOffsets.count(var)) { //contained in function scope
			loadFrom = "$sp";
			toLoad = _stackOffsets[var];
		}
		else {
			loadFrom = "$v1";
			toLoad = globalIntList->_stackOffsets[var];
		}

		//add base address
		loadInst << "add" << spareRegister << "," << spareRegister << "," << loadFrom << std::endl;

		loadInst << "lw " << correspondingReg << "," << toLoad << "("<< spareRegister<<")";

		return loadInst.str();
	}

	std::string getStoreInstruction(std::string var, std::string correspondingReg, std::string spareRegister, std::string indexReg) {
		std::ostringstream storeInst;

		storeInst << "mov " << spareRegister << "," << indexReg << std::endl;
		//multiply by 4
		storeInst << "sll " << spareRegister << ",2" << std::endl;


		std::string loadFrom;
		int toLoad;
		if (_stackOffsets.count(var)) { //contained in function scope
			loadFrom = "$sp";
			toLoad = _stackOffsets[var];
		}
		else {
			loadFrom = "$v1";
			toLoad = globalIntList->_stackOffsets[var];
		}

		//add base address
		storeInst << "add" << spareRegister << "," << spareRegister << "," << loadFrom << std::endl;

		storeInst << "sw " << correspondingReg << "," << toLoad << "(" << spareRegister << ")";

		return storeInst.str();

	}

	//prepends and appends instructions to the list passed here
	void processVarDeclarationInstructions(std::list<Instruction*> &_instructions) {
		if (_vars.size() == 0) {
			return;
		}
		//create pre and post instructions to declare and remove vars from stack


		std::ostringstream preInstStr;
		//pre-instructions (increment stack and note down offsets for all local vars) in _stackOffsets

		int stackIncrementSz = 0;
		std::ostringstream varInit;
		for (auto var : _vars) {
			if (var[var.length() - 1] == ']') {
				//this is an array variable
				auto splt = split(var.c_str(), '[');
				auto name = splt[0];
				auto sz = std::stoi(split(splt[1].c_str(), ']')[0]);
				_stackOffsets[name] = stackIncrementSz;
				_varNames.push_back(name);
				stackIncrementSz += 4 * sz;
			}
			else {
				_stackOffsets[var] = stackIncrementSz;
				_varNames.push_back(var);
				stackIncrementSz += 4;
			}
		}
		preInstStr << "sub $sp, $sp, " << stackIncrementSz;
		if (_isStatic) {
			//save the static stack pointer somewhere
			//lets use v1 for it since we dont use it anywhere else
			preInstStr << std::endl;
			preInstStr << "mov $v1, $sp";

		}
		auto preInst = new Instruction(preInstStr.str());
		_instructions.push_front(preInst);


		std::ostringstream postInstStr;

		//post-instructions (decrement stack)
		postInstStr << "add $sp, $sp, "<< stackIncrementSz;
		auto postInst = new Instruction(postInstStr.str());
		_instructions.push_back(postInst);

	}
};

class Function
{
	std::list<Instruction*> _instructions;
	IntList _intlist;
	std::map<std::string, std::string> _argRegMap;
	std::string _name;
public:
	Function(std::string name, std::string functionDefinition, IntList intlist) : _name(name), _instructions(), _intlist(intlist), _argRegMap(){
		//todo parse definition
		//this will be useful to indicate which vars are function params and therefore dont need special register allocations
		
		auto sp = split(functionDefinition.c_str(), '(');
		auto varString = sp[1];
		auto spl = split(varString.c_str(), ')');
		if (spl.size()) {
			varString = spl[0];
			auto vars = split(varString.c_str());
			std::vector<std::string>varNames;
			for (auto v : vars) {
				varNames.push_back(split(v.c_str())[1]);
			}
			//for each relevant instruction, add to its mapping of vars->registers, the special registers
			for (int i = 0; i < varNames.size(); i++) {
				_argRegMap[varNames[i]] = "$a" + std::to_string(i);
			}
		}
	}

	void addInstruction(Instruction* inst) {
		_instructions.push_back(inst);
	}

	void processVarDeclarationInstructions() {
		_intlist.processVarDeclarationInstructions(_instructions);

		if (_name=="main") {
			IntList::globalIntList->processVarDeclarationInstructions(_instructions);
		}
	}

	std::list<Instruction*> getInstructions() {
		return _instructions;
	}

	IntList getIntList() {
		return _intlist;
	}
};

