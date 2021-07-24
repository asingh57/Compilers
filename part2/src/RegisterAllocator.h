#pragma once
#include <vector>
#include <string>
class RegisterAllocator
{
public:
	RegisterAllocator() {};
	virtual std::vector<std::string> getFinalOpList() {
		return {};
	}
};

