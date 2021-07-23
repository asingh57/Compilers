#pragma once
#include "Instruction.h"
#include <list>

class IntList {
public:
	IntList() {}
	IntList(std::string intList) {
		//todo parse intlist
	}
};

class Function
{
	std::list<Instruction*> _instructions;
	IntList _intlist;
public:
	Function(std::string functionDefinition, IntList intlist) : _instructions(), _intlist(intlist){
		//todo parse definition, do we need it???

		//convert intlist into instructions

	}

	void addInstruction(Instruction* inst) {
		_instructions.push_back(inst);
	}
};

