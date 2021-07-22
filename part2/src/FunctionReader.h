#pragma once
#include <string>
#include <vector>
#include "Instruction.h"
class FunctionReader
{
private:


	std::vector<Instruction> _instructions;

	std::vector<Instruction> _registerAllocatedInstructions;

public:
	FunctionReader(std::string filePath) : _instructions(){
		//reads ir line by line and stores tokenized instructions

	};


	void doNaiveRegisterAllocation();

	void doIntraBlockRegisterAllocation() {}

	void doBriggsAllocation() {}

};

