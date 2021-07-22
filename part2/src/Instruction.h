#pragma once
class Instruction
{
	Instruction() {};
public:
	virtual std::string debug(){
		return "";
	}

	virtual std::string getRegisterAllocatedInstruction() {
		return "";
	}
};

class AddInstruction : Instruction
{


};