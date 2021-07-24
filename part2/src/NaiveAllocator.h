#pragma once
#include "RegisterAllocator.h"
#include "Function.h"
#include <list>
#include <string>
class NaiveAllocator : public RegisterAllocator
{
private:
	std::list<Function*> _functions; 
	IntList _globalIntList;
public:
	NaiveAllocator(	std::list<Function*> functions,	IntList globalIntList) : _functions(functions), _globalIntList(globalIntList) {
	
	};

	virtual std::vector<std::string> getFinalOpList() override {
		return {};
	}
};

