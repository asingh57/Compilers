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
	IntList _globalIntList;

	// helpers
	std::list<std::string> readFile(std::string filePath);

public:
	FunctionReader(std::string filePath);



};

