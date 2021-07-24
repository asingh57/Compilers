#pragma once
#include "Instruction.h"
#include <list>

class IntList {
	static IntList* globalIntList;

	std::vector<std::string> _vars; //vars to be initialised in function scope
	bool _isStatic;
	std::map<std::string, int> _stackOffsets;//stack offsets for each var declared in scope relative to $sp
public:
	IntList() {}
	IntList(std::string intList) : _vars(), _isStatic(false), _stackOffsets(){
		auto ls = split(intList.c_str(), ':');
		_isStatic = (ls[0] == "static-int-list");

		auto varString = ls[1];
		_vars = split(varString.c_str());

		globalIntList = this;
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
				stackIncrementSz += 4 * sz;
			}
			else {
				_stackOffsets[var] = stackIncrementSz;
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
public:
	Function(std::string functionDefinition, IntList intlist) : _instructions(), _intlist(intlist), _argRegMap(){
		//todo parse definition
		//this will be useful to indicate which vars are function params and therefore dont need special register allocations
		auto varString = split(functionDefinition.c_str(), '(')[1];
		varString = split(varString.c_str(), ')')[0];
		auto vars = split(varString.c_str());
		std::vector<std::string>varNames;
		for (auto v: vars) {
			varNames.push_back(split(v.c_str())[1]);
		}
		//for each relevant instruction, add to its mapping of vars->registers, the special registers
		for (int i = 0; i < varNames.size();i++) {
			_argRegMap[varNames[i]] = "$a"+std::to_string(i);
		}
	}

	void addInstruction(Instruction* inst) {
		_instructions.push_back(inst);
	}

	void processVarDeclarationInstructions() {
		_intlist.processVarDeclarationInstructions(_instructions);
	}

};

