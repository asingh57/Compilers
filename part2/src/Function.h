#pragma once
#include "Instruction.h"
#include <list>
class Function
{
	std::list<Instruction*> _instructions;
public:
	Function(std::string functionDefinition, std::string intlist) : _instructions(){
		//todo parse definition
	}

	void addInstruction(Instruction* inst) {
		_instructions.push_back(inst);
	}
};

