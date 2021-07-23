#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "Instruction.h"
#include "Function.h"
class FunctionReader
{
private:

	std::list<Function*> _functions;


	// helpers
	std::list<std::string> readFile(std::string filePath);

public:
	FunctionReader(std::string filePath);


	void doNaiveRegisterAllocation();

	void doIntraBlockRegisterAllocation() {}

	void doBriggsAllocation() {}

};

