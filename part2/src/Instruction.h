#pragma once
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_set>

inline std::vector<std::string> split(const char* str, char c = ',')
{
	std::vector<std::string> result;
	do
	{
		const char* begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(std::string(begin, str));
		if (result.back().length() == 0) {
			result.pop_back();
		}
	} while (0 != *str++);

	return result;
}

inline bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}


enum InstructionType {
	GenericInst,
	LabelInst,
	AssignInst,
	AssignArrayInst,
	AddInst,
	SubInst,
	MultInst,
	DivInst,
	AndInst,
	OrInst,
	GotoInst,
	BreqInst,
	BrneqInst,
	BrgtInst,
	BrltInst,
	BrleqInst,
	BrgeqInst,
	ReturnProcedureInst,
	ReturnFunctionInst,
	CallProcedureInst,
	CallFunctionInst,
	CallStoreArrayInst,
	CallLoadArrayInst

};
class Instruction
{
protected:
	static int extraCounter;
	std::vector<std::string> _vars;
	std::map<std::string, std::string> _varRegMap;
	std::string _genericInstruction;
	std::unordered_set<int> _excludeIndices;
	InstructionType _instructionType;
	Instruction(InstructionType instType, std::vector<std::string> vars = {}) : _instructionType(instType) ,_vars(vars), _varRegMap(), _excludeIndices() {
		_genericInstruction = "";
	};
public:
	Instruction(std::string genericInstruction, std::vector<std::string> vars = {}) :_instructionType(GenericInst), _vars(vars), _varRegMap(), _genericInstruction(genericInstruction) {
	};

	InstructionType getInstructionType() {
		return _instructionType;
	}

	//instruction factory
	static Instruction* parse(std::string instStr);

	virtual std::string debug(){
		return "";
	}

	virtual std::string getMIPSInstruction() {
		return _genericInstruction+ "\n";
	}

	std::vector<std::string> getUsedVars() {
		std::vector<std::string> vars;
		for (unsigned int i = 0; i < _vars.size();i++) {
			auto v = _vars[i];
			if (!isInteger(v) && _excludeIndices.find(i) == _excludeIndices.end()) {
				vars.push_back(v);
			}
		}
		return vars;
	}


	void addToVarRegisterMap(std::string var, std::string reg) {
		_varRegMap[var] = reg;
	}

	std::string getRegFromVar(std::string var) {
		return _varRegMap[var];
	}

};

class LabelInstruction : public Instruction {
	std::string _name;
public:
	LabelInstruction(std::string name) : _name(name), Instruction(LabelInst) {

	}

	std::string getMIPSInstruction() override {
		return _name+":"+"\n";
	}
};

class AssignInstruction : public Instruction
{
public:
	AssignInstruction(std::vector<std::string> vars) : Instruction(AssignInst,vars) {

	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		if (isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[0]] << "," << _vars[1];
		}
		else {
			stringStream << "move " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]];

		}

		return stringStream.str() + "\n";
	}

};

class AssignArrayInstruction : public Instruction
{
public:
	AssignArrayInstruction(std::vector<std::string> vars) : Instruction(AssignArrayInst,vars) {
		//we need an extra register so we can store values in arrays
		_vars.push_back("__compilerGeneratedTemp"+std::to_string(extraCounter++));
	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		stringStream << "li " << _varRegMap[_vars[3]] << "," << _vars[2] << std::endl;
		for (int i = 0; i < std::stoi(_vars[1]); i++) {
			std::string offset = std::to_string(4 * i);
			stringStream << "sw " << _varRegMap[_vars[3]] << ", " << offset << "(" << _varRegMap[_vars[0]] << ")" <<std::endl;
		}

		return stringStream.str() + "\n";
	}

};

class AddInstruction : public Instruction
{
public:
	AddInstruction(std::vector<std::string> vars) : Instruction(AddInst, vars) {

	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[2]] << "," << (std::stoi(_vars[0]) + std::stoi(_vars[1]));
		}
		else if(isInteger(_vars[0])){
			stringStream << "addi " << _varRegMap[_vars[2]] <<"," <<_varRegMap[_vars[1]] << "," << _vars[0];
		}
		else if (isInteger(_vars[1])) {
			stringStream << "addi " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[0]] << "," << _vars[1];
		}
		else {
			stringStream << "add " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[1]] << "," << _varRegMap[_vars[0]];
		}

		return stringStream.str() + "\n";
	}

};

class SubInstruction : public Instruction
{
public:
	SubInstruction(std::vector<std::string> vars) : Instruction(SubInst, vars) {
		if (isInteger(_vars[0]) || isInteger(_vars[1])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[2]] << "," << (std::stoi(_vars[0]) - std::stoi(_vars[1]));
		}		
		else if (isInteger(_vars[0])) {
			stringStream << "li " << _varRegMap[_vars[3]] << "," << (std::stoi(_vars[0])) << std::endl;
			stringStream << "sub " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]];
		}
		
		else if (isInteger(_vars[1])) {
			stringStream << "addi " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[0]] << ",-" << _vars[1];
		}
		else {
			stringStream << "sub " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]];
		}

		return stringStream.str() + "\n";
	}

};

class MultInstruction : public Instruction
{
public:
	MultInstruction(std::vector<std::string> vars) : Instruction(MultInst, vars) {
		if (isInteger(_vars[0]) || isInteger(_vars[1])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[2]] << "," << (std::stoi(_vars[0])*std::stoi(_vars[1]));
		}
		else if (isInteger(_vars[0])) {
			stringStream << "li " << _varRegMap[_vars[3]] << "," << (std::stoi(_vars[0])) << std::endl;
			stringStream << "mult "<< _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << std::endl;
			stringStream << "mflo " << _varRegMap[_vars[2]];
		}

		else if (isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[3]] << "," << (std::stoi(_vars[1])) << std::endl;
			stringStream << "mult " << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[0]] << std::endl;
			stringStream << "mflo " << _varRegMap[_vars[2]];
		}
		else {
			stringStream << "mult " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]] << std::endl;
			stringStream << "mflo " << _varRegMap[_vars[2]];
		}

		return stringStream.str() + "\n";
	}

};


class DivInstruction : public Instruction
{
public:
	DivInstruction(std::vector<std::string> vars) : Instruction(DivInst, vars) {

		if (isInteger(_vars[0]) || isInteger(_vars[1])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[2]] << "," << (std::stoi(_vars[0]) / std::stoi(_vars[1]));
		}
		else if (isInteger(_vars[0])) {
			stringStream << "li " << _varRegMap[_vars[3]] << "," << (std::stoi(_vars[0])) << std::endl;
			stringStream << "div " << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << std::endl;
			stringStream << "mflo " << _varRegMap[_vars[2]];
		}

		else if (isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[3]] << "," << (std::stoi(_vars[1])) << std::endl;
			stringStream << "div " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[3]] << std::endl;
			stringStream << "mflo " << _varRegMap[_vars[2]];
		}
		else {
			stringStream << "div " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]] << std::endl;
			stringStream << "mflo " << _varRegMap[_vars[2]];
		}

		return stringStream.str() + "\n";
	}

};

class AndInstruction : public Instruction
{
public:
	AndInstruction(std::vector<std::string> vars) : Instruction(AndInst, vars) {

	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[2]] << "," << (std::stoi(_vars[0]) & std::stoi(_vars[1]));
		}
		else if (isInteger(_vars[0])) {
			stringStream << "andi " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[1]] << "," << _vars[0];
		}
		else if (isInteger(_vars[1])) {
			stringStream << "andi " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[0]] << "," << _vars[1];
		}
		else {
			stringStream << "and " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[1]] << "," << _varRegMap[_vars[0]];
		}

		return stringStream.str() + "\n";
	}
};

class OrInstruction : public Instruction
{
public:
	OrInstruction(std::vector<std::string> vars) : Instruction(OrInst, vars) {

	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			stringStream << "li " << _varRegMap[_vars[2]] << "," << (std::stoi(_vars[0]) | std::stoi(_vars[1]));
		}
		else if (isInteger(_vars[0])) {
			stringStream << "ori " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[1]] << "," << _vars[0];
		}
		else if (isInteger(_vars[1])) {
			stringStream << "ori " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[0]] << "," << _vars[1];
		}
		else {
			stringStream << "or " << _varRegMap[_vars[2]] << "," << _varRegMap[_vars[1]] << "," << _varRegMap[_vars[0]];
		}

		return stringStream.str() + "\n";
	}

};


class GotoInstruction : public Instruction
{
public:
	GotoInstruction(std::vector<std::string> vars) : Instruction(GotoInst, vars) {

	}

	std::string getMIPSInstruction() override {
		std::ostringstream stringStream;
		stringStream << "j " << _vars[0];
		
		return stringStream.str() + "\n";
	}

};


class BreqInstruction : public Instruction
{
public:
	BreqInstruction(std::vector<std::string> vars) : Instruction(BreqInst, vars) {

		_excludeIndices.insert(vars.size() - 1);

		if (isInteger(_vars[0]) || isInteger(_vars[1])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
	}

	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			if (std::stoi(_vars[0]) == std::stoi(_vars[1])) {

				stringStream << "j " << _vars[2];
			}
		}
		else if (isInteger(_vars[0])) {
			stringStream << "li " << _varRegMap[_vars[3]] << "," << _vars[0] << std::endl;

			stringStream << "beq " << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _vars[2];
		}
		else if (isInteger(_vars[1])) {

			stringStream << "li " << _varRegMap[_vars[3]] << "," << _vars[1] << std::endl;

			stringStream << "beq " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[3]] << "," << _vars[2];
		}
		else {
			stringStream << "beq " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]] << "," << _vars[2];
		}

		return stringStream.str() + "\n";
	}

};


class BrneqInstruction : public Instruction
{
public:
	BrneqInstruction(std::vector<std::string> vars) : Instruction(BrneqInst, vars) {
		_excludeIndices.insert(vars.size() - 1);
		if (isInteger(_vars[0]) || isInteger(_vars[1])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
	}

	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			if (std::stoi(_vars[0]) != std::stoi(_vars[1])) {

				stringStream << "j " << _vars[2];
			}
		}
		else if (isInteger(_vars[0])) {
			stringStream << "li " << _varRegMap[_vars[3]] << "," << _vars[0] << std::endl;

			stringStream << "bne " << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _vars[2];
		}
		else if (isInteger(_vars[1])) {

			stringStream << "li " << _varRegMap[_vars[3]] << "," << _vars[1] << std::endl;

			stringStream << "bne " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[3]] << "," << _vars[2] ;
		}
		else {
			stringStream << "bne " << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]] << "," << _vars[2];
		}

		return stringStream.str() + "\n";
	
	}

};


class BrgtInstruction : public Instruction
{
public:
	BrgtInstruction(std::vector<std::string> vars) : Instruction(BrgtInst, vars) {
		_excludeIndices.insert(vars.size() - 1);
		//we will need an extra register
		_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
	}

	//https://www2.engr.arizona.edu/~ece369/Resources/spim/QtSPIM_examples.pdf
	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			if (std::stoi(_vars[0]) > std::stoi(_vars[1])) {

				stringStream << "j " << _vars[2];
			}
		}
		else if (isInteger(_vars[0])) {

			stringStream << "slti" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _vars[0] << std::endl;
			stringStream << "bne " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}
		else if (isInteger(_vars[1])) {

			stringStream << "slti" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[0]] << "," << _vars[1] << std::endl;
			stringStream << "beq " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}
		else {
			stringStream << "slt" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _varRegMap[_vars[0]] << std::endl;
			stringStream << "bne " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}

		return stringStream.str() + "\n";
	}

};


class BrltInstruction : public Instruction
{
public:
	BrltInstruction(std::vector<std::string> vars) : Instruction(BrltInst, vars) {
		_excludeIndices.insert(vars.size() - 1);
		//we will need an extra register
		_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
	}
	std::string getMIPSInstruction() override {


		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			if (std::stoi(_vars[0]) < std::stoi(_vars[1])) {

				stringStream << "j " << _vars[2];
			}
		}
		else if (isInteger(_vars[0])) {
			//brgeq of the inverse
			stringStream << "slti" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _vars[0] << std::endl;
			stringStream << "beq " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];

		}
		else if (isInteger(_vars[1])) {

			stringStream << "slti" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[0]] << "," << _vars[1] << std::endl;
			stringStream << "bne " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}
		else {
			stringStream << "slt" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]] << std::endl;
			stringStream << "bne " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}

		return stringStream.str() + "\n";

	}
};



class BrleqInstruction : public Instruction
{
public:
	BrleqInstruction(std::vector<std::string> vars) : Instruction(BrleqInst, vars) {
		_excludeIndices.insert(vars.size() - 1);
		//we will need an extra register
		_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));

	}
	std::string getMIPSInstruction() override {


		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			if (std::stoi(_vars[0]) <= std::stoi(_vars[1])) {

				stringStream << "j " << _vars[2];
			}
		}
		else if (isInteger(_vars[0])) {
			stringStream << "slti " << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _vars[0] << std::endl;
			stringStream << "beq " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];

		}
		else if (isInteger(_vars[1])) {;
			std::string ltCompare = std::to_string(std::stoi(_vars[1]) + 1);
			//brgt of inverse
			stringStream << "slti " << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[0]] << "," << ltCompare << std::endl;
			stringStream << "bne " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}
		else {
			stringStream << "slt " << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _varRegMap[_vars[0]] << std::endl;
			stringStream << "beq " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}

		return stringStream.str() + "\n";

	}

};


class BrgeqInstruction : public Instruction
{
public:
	BrgeqInstruction(std::vector<std::string> vars) : Instruction(BrgeqInst, vars) {
		_excludeIndices.insert(vars.size() - 1);

		//we will need an extra register
		_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
	}
	std::string getMIPSInstruction() override {


		std::ostringstream stringStream;
		if (isInteger(_vars[0]) && isInteger(_vars[1])) {
			if (std::stoi(_vars[0]) >= std::stoi(_vars[1])) {

				stringStream << "j " << _vars[2];
			}
		}
		else if (isInteger(_vars[0])) {
			//brlt of inverse
			stringStream << "slt" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[1]] << "," << _vars[0] << std::endl;
			stringStream << "bne " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];

		}
		else if (isInteger(_vars[1])) {
			stringStream << "slti" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[0]] << "," << _vars[1] << std::endl;
			stringStream << "beq " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}
		else {
			stringStream << "slt" << _varRegMap[_vars[3]] << "," << _varRegMap[_vars[0]] << "," << _varRegMap[_vars[1]] << std::endl;
			stringStream << "beq " << _varRegMap[_vars[3]] << "," << "$zero" << "," << _vars[2];
		}

		return stringStream.str() + "\n";

	}

};

class ReturnProcedureInstruction : public Instruction
{
public:
	ReturnProcedureInstruction() : Instruction(ReturnProcedureInst) {
	}

	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;
		//jump to return address
		stringStream << "jr $ra";
		return stringStream.str() + "\n";
	}
};


class ReturnFunctionInstruction : public Instruction
{
public:
	ReturnFunctionInstruction(std::vector<std::string> vars) : Instruction(ReturnFunctionInst, vars) {
		
	}

	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;

		//save result
		if (isInteger(_vars[0])) {
			stringStream << "li, $v0, " << _vars[0] << std::endl;
		}
		else {
			stringStream << "move, $v0, " << _varRegMap[_vars[0]] << std::endl;
		}

		//jump to return address
		stringStream << "jr $ra";
		return stringStream.str() + "\n";
	}

};


class CallProcedureInstruction : public Instruction
{
public:
	CallProcedureInstruction(std::vector<std::string> vars) : Instruction(CallProcedureInst, vars) {
		_excludeIndices.insert(0);
		/* do we need this optimisation?
		if (_vars[1] == "printi") {
			_vars.push_back("$v0");//any vars with $ signs in them are hard coded and must be allocated as such
			_vars.push_back("$a0");
		}
		*/

	}


	//before calling mips instructions on this procedure, one must back up all registers including $ra currently used in this scope
	//after calling this, restore them
	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;
		if (_vars[0] == "printi") {

			stringStream << "li $v0, 1" << std::endl;
			if (isInteger(_vars[1])) {

				stringStream << "li $a0, "<< _vars[1] << std::endl;
			}
			else{
			stringStream << "move $a0, "<< _varRegMap[_vars[1]] << std::endl;
			}
			stringStream << "syscall";


			stringStream << "\naddi $a0, $0, 0xA \n" << "addi $v0, $0, 0xB\n" << "syscall";
		}
		else {
			//load args into arg registers// Should I handle args more than 4?
			for (unsigned int i = 0; i < _vars.size()-1; i++) {
				if (isInteger(_vars[i+1]) ){
					stringStream << "li " << "$a" << i << "," << _vars[i + 1] << std::endl;
				}
				else {
					stringStream << "move " << "$a" << i << "," << _varRegMap[_vars[i + 1]] << std::endl;

				}
			}

			stringStream << "jal " << _vars[0];

		}


		return stringStream.str() + "\n";
	}

};


class CallFunctionInstruction : public Instruction
{
public:
	CallFunctionInstruction(std::vector<std::string> vars) : Instruction(CallFunctionInst, vars) {
		_excludeIndices.insert(1);
	}


	//before calling mips instructions on this function, one must back up all registers including $ra currently used in this scope
	//after calling this, restore them
	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;

		for (unsigned int i = 2; i < _vars.size(); i++) {
			if (isInteger(_vars[i])) {
				stringStream << "li " << "$a" << i << "," << _vars[i] << std::endl;
			}
			else {
				stringStream << "move " << "$a" << i << "," << _varRegMap[_vars[i]] << std::endl;

			}
		}

		stringStream << "jal " << _vars[1] << std::endl;
		//load v0 into return variable

		stringStream << "move " << _varRegMap[_vars[0]] << ",$v0";

		return stringStream.str() + "\n";
	}
};


class CallStoreArrayInstruction : public Instruction
{
public:
	CallStoreArrayInstruction(std::vector<std::string> vars) : Instruction(CallStoreArrayInst, vars) {
		if (!isInteger(_vars[1])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
		if (isInteger(_vars[2])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
	}

	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;
		auto varName = _varRegMap[_vars[0]];
		auto posRaw = _vars[1];
		std::string pos;
		std::string val;
		int tempPos = 3;

		if (isInteger(_vars[2])) {
			stringStream << "li " << _varRegMap[_vars[tempPos]]<<","<< _vars[2] << std::endl;
			val = _varRegMap[_vars[tempPos]];
			tempPos++;
		}
		else {
			val = _varRegMap[_vars[2]];
		}


		if (isInteger(posRaw)) {
			pos = std::to_string(4 * std::stoi(posRaw))+"("+ varName +")";
		}
		else {
			stringStream << "move "<< _varRegMap[_vars[tempPos]] <<"," << _varRegMap[posRaw] << std::endl;
			//multiply by 4 in place
			stringStream << "sll " << _varRegMap[_vars[tempPos]] << "," << 2 << std::endl;
			//now add base address
			stringStream << "add " << _varRegMap[_vars[tempPos]] << "," << _varRegMap[_vars[tempPos]] << "," << varName << std::endl;

			pos = "0(" + _varRegMap[_vars[tempPos]] +")";
		}

		stringStream << "sw " << val <<"," << pos;

		return stringStream.str() + "\n";
	}

};

class CallLoadArrayInstructionInstruction : public Instruction
{
public:
	CallLoadArrayInstructionInstruction(std::vector<std::string> vars) : Instruction(CallLoadArrayInst, vars) {
		if (!isInteger(_vars[2])) {
			//we will need an extra register
			_vars.push_back("__compilerGeneratedTemp" + std::to_string(extraCounter++));
		}
	}


	std::string getMIPSInstruction() override {

		std::ostringstream stringStream;
		auto varName = _varRegMap[_vars[1]];
		auto posRaw = _vars[2];
		std::string pos;
		std::string val;
		int tempPos = 3;


		val = _varRegMap[_vars[0]];


		if (isInteger(posRaw)) {
			pos = std::to_string(4 * std::stoi(posRaw)) + "(" + varName + ")";
		}
		else {
			stringStream << "move " << _varRegMap[_vars[tempPos]] << "," << _varRegMap[posRaw] << std::endl;
			//multiply by 4 in place
			stringStream << "sll " << _varRegMap[_vars[tempPos]] << "," << 2 << std::endl;
			//now add base address
			stringStream << "add " << _varRegMap[_vars[tempPos]] << "," << _varRegMap[_vars[tempPos]] << "," << varName << std::endl;

			pos = "0(" + _varRegMap[_vars[tempPos]] + ")";
		}

		stringStream << "lw " << val << "," << pos;

		return stringStream.str() + "\n";
	}

};
