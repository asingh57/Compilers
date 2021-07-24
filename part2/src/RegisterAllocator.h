#pragma once
#include <vector>
#include <string>
class RegisterAllocator
{
protected:
	static std::vector<std::string> usableRegisters;
public:
	RegisterAllocator() {};
	virtual std::string getFinalOpList() {
		return "";
	}
};

