#pragma once
#include "RegisterAllocator.h"
#include "Function.h"
#include <list>
#include <string>
class NaiveAllocator : public RegisterAllocator
{

private:
	std::list<Function*> _functions; 
public:
	NaiveAllocator(	std::list<Function*> functions) : _functions(functions) {
	
	};

	virtual std::string getFinalOpList() override {
		std::ostringstream out;

		std::map<std::string,std::string> currentlyUsedRegs = {};
		std::map<std::string, std::string> currentlyAssignedVars = {};
		std::vector<std::string> currentlyAvailableRegs = {};
		for (auto v : usableRegisters) {
			currentlyAvailableRegs.push_back(v);
			currentlyUsedRegs[v] = "";
		}
		for (auto var : IntList::globalIntList->getVarNames()) {
			currentlyAssignedVars[var] = "";
		}

		for (auto fn : _functions) {
			auto insts = fn->getInstructions();
			auto intlsts = fn->getIntList();
			for (auto var : intlsts.getVarNames()) {
				currentlyAssignedVars[var] = "";
			}

			for (auto inst : insts) {
				auto varsUsedByInst = inst->getUsedVars();
				//load vars into regs
				

				//instruction
				// 
				// 
				//store vars into regs
			}


		}

		return out.str();
	}
};

