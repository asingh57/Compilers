#pragma once
#include "RegisterAllocator.h"
#include "Function.h"
#include <list>
#include <string>
#include <iostream>
class NaiveAllocator : public RegisterAllocator
{

private:
	std::list<Function*> _functions; 
public:
	NaiveAllocator(	std::list<Function*> functions) : _functions(functions) {
	
	};

	virtual std::string getFinalOpList() override {
		std::ostringstream out;

		std::vector<std::string> currentlyAvailableRegs = {};
		std::vector<std::string> currentlyUsedRegs = {};
		for (auto v : usableRegisters) {
			currentlyAvailableRegs.push_back(v);
		}

		for (auto fn : _functions) {
			auto insts = fn->getInstructions();
			auto intlsts = fn->getIntList();

			for (auto inst : insts) {
				auto varsUsedByInst = inst->getUsedVars();
				//load vars into regs
				for (auto v: varsUsedByInst) {
					if (inst->varRegMapContainsVar(v)) {
						continue;
					}

					auto reg = currentlyAvailableRegs.back();
					currentlyUsedRegs.push_back(reg);
					currentlyAvailableRegs.pop_back();
					std::cout << "v=" << v << std::endl;
					out << intlsts->getLoadInstruction(v, reg) << std::endl;
					inst->addToVarRegisterMap(v, reg);
				}

				//instruction
				out << inst->getMIPSInstruction() << std::endl;
				
				//store vars into mem

				for (auto v : varsUsedByInst) {
					if (inst->varRegMapContainsVar(v)) {
						continue;
					}
					auto reg = inst->getRegFromVar(v);
					out << intlsts->getStoreInstruction(v, reg) << std::endl;
					inst->addToVarRegisterMap(v, reg);
				}

				//make regs available again
				while (currentlyUsedRegs.size()) {
					currentlyAvailableRegs.push_back(currentlyUsedRegs.back());
					currentlyUsedRegs.pop_back();
				}
			}


		}

		return out.str();
	}
};

