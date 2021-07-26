#pragma once
#include "RegisterAllocator.h"
#include "Instruction.h"
#include "Function.h"
#include <iostream>
#include <algorithm>
struct Block {
    static std::map<std::string, int> blockNameToNumberMap;
    static std::map<std::string, std::vector<int>> functionReturnCallNameToNumberMap;
    static int blockCounter;
    static std::vector<Block*> blockList;

    int _blkNumber;
    std::vector<Instruction*> _instructions;
    std::vector<std::string> _labelsThisPointsTo;
    std::vector<int> _blkNumbersThisPointsTo;
    IntList* _intlists;
    Block(IntList* intlists) :_intlists(intlists), _instructions(), _labelsThisPointsTo(), _blkNumber(blockCounter++), _blkNumbersThisPointsTo(){

    }

    Block(std::string name, IntList* intlists) :_intlists(intlists), _instructions(), _labelsThisPointsTo(), _blkNumber(blockCounter++), _blkNumbersThisPointsTo() {
        blockNameToNumberMap[name] = _blkNumber;
    }

    void addInstruction(Instruction* inst) {
        _instructions.push_back(inst);

        for (auto lb : inst->getListOfBlocksThisPointsTo()) {
            _labelsThisPointsTo.push_back(lb);
        }
    }

    static void processLabels() {
        for (int i = 0; i < blockList.size(); i++) {
            auto blk = blockList[i];

            auto lastInst = blk->_instructions.back();
            bool pointBack = false;
            if (lastInst->getInstructionType() == InstructionType::CallFunctionInst || 
                lastInst->getInstructionType() == InstructionType::CallProcedureInst) {
                pointBack = true;
            }


            for (auto lb : blk->_labelsThisPointsTo) {
                blk->_blkNumbersThisPointsTo.push_back(blockNameToNumberMap[lb]);


                if (pointBack) {
                    for (auto rt : functionReturnCallNameToNumberMap[lb]) {
                        blockList[rt]->_blkNumbersThisPointsTo.push_back(i + 1);
                    }

                }
            }
        }
    }

    void printCFGBlk() {
        std::cout << "\n\n--------------------------\n--------------------------\n BLOCK NUMBER " << _blkNumber << "\n";
        std::cout << "--------------------------\n POINTS TO BLOCK NUMS: ";
        for (auto blkNum: _blkNumbersThisPointsTo) {
            std::cout << blkNum << ", ";
        }
        std::cout << "\n--------------------------" << std::endl;
        std::cout << " INSTRUCTIONS:\n";
        for (auto inst: _instructions) {
            std::cout << inst->debug() << std::endl;
        }
        std::cout << "--------------------------\n--------------------------" << std::endl;
    }


    static void printCFG() {
        for (int i = 0; i < blockList.size(); i++) {
            blockList[i]->printCFGBlk();
        }

    }


};

class BlockAllocator :
    public RegisterAllocator
{
    std::list<Function*> _functions;
    bool _printCFG;
public:
    BlockAllocator(std::list<Function*> functions, bool printCFG) : _functions(functions) , _printCFG(printCFG){

	};

    virtual std::string getFinalOpList() override {
        std::ostringstream out;

        std::vector<std::string> currentlyAvailableRegs = {};
        std::vector<std::string> currentlyUsedRegs = {};
        for (auto v : usableRegisters) {
            currentlyAvailableRegs.push_back(v);
        }

        //create library function block
        IntList* intls = new IntList();
        Block* printblk = new Block("printi", intls);
        printblk->addInstruction(new Instruction("", {},"#printi"));
        std::vector<int> returnBlkIndicesPrinti = {0};
        Block::blockList.push_back(printblk);
        Block::functionReturnCallNameToNumberMap["printi"] = returnBlkIndicesPrinti;

        //functionReturnCallNameToNumberMap
        for (auto fn : _functions) {
            std::vector<int> returnBlkIndices;
            bool newFunction = true;

            auto insts = fn->getInstructions();
            auto intlsts = fn->getIntList();

            //create new block
            Block* currblk= nullptr;
            bool nextItemIsLeader = false;

            auto lastInstOfFn = insts.back();

            for (auto inst: insts) {
                auto instType = inst->getInstructionType();




                if (instType ==InstructionType::LabelInst
                    ||
                    nextItemIsLeader
                    ) {
                    if (currblk) {
                        Block::blockList.push_back(currblk);
                    }




                    if (newFunction) {
                        newFunction = false;
                    }
                    else {
                        //make the last block point to current block
                        if (currblk) {
                            currblk->_blkNumbersThisPointsTo.push_back(currblk->_blkNumber + 1);
                        }
                    }


                    if (instType == InstructionType::LabelInst) {
                        currblk = new Block(dynamic_cast<LabelInstruction*>(inst)->getLabelName(), intlsts);
                    }
                    else {
                        currblk = new Block(intlsts);
                    }

                    nextItemIsLeader = false;

                }
                else if (instType == InstructionType::BreqInst
                    ||
                    instType == InstructionType::BrgeqInst
                    ||
                    instType == InstructionType::BrgtInst
                    ||
                    instType == InstructionType::BrleqInst
                    ||
                    instType == InstructionType::BrltInst
                    ||
                    instType == InstructionType::BrneqInst
                    ||
                    instType == InstructionType::CallFunctionInst
                    ||
                    instType == InstructionType::CallProcedureInst
                    ||
                    instType == InstructionType::GotoInst
                    ||
                    instType == InstructionType::ReturnFunctionInst
                    ||
                    instType == InstructionType::ReturnProcedureInst
                    ) {

                    nextItemIsLeader = true;


                }
                if (instType == InstructionType::ReturnFunctionInst
                    ||
                    instType == InstructionType::ReturnProcedureInst
                    ) {
                    returnBlkIndices.push_back(currblk->_blkNumber);
                }

                currblk->addInstruction(inst);

            }


            if (currblk) {
                Block::blockList.push_back(currblk);
            }


            Block::functionReturnCallNameToNumberMap[fn->getName()] = returnBlkIndices;
        }
        Block::processLabels();

        if (_printCFG) {
            Block::printCFG();
        }

        auto cmp = [](std::pair<std::string, int>& a,
            std::pair<std::string, int>& b)
        {
            return a.second > b.second;
        };

        for (auto blk : Block::blockList) {
            out << "############\n";
            bool blockInit = false;

            std::map<std::string, int>mostUsedVars;

            for (auto inst : blk->_instructions) {
                auto vars = inst->getUsedVars();
                for (auto var : vars) {
                    if (inst->varRegMapContainsVar(var)) {
                        continue;
                    }
                    if (mostUsedVars.count(var) == 0) {
                        mostUsedVars[var] = 1;
                    }
                    else {
                        mostUsedVars[var]++;
                    }
                }
            }
            std::vector <std::pair<std::string, int>> usedVars;

            //now we have all the var's reference count, convert to vector

            for (auto pair : mostUsedVars) {
                usedVars.push_back(pair);
            }

            //now sort 

            sort(usedVars.begin(), usedVars.end(), cmp);


            auto insts = blk->_instructions;
            auto intlsts = blk->_intlists;


            std::map<std::string, std::string> varToRegMapLocal;
            std::string initStr="";
            for (auto [varName, val] : usedVars) {
                varToRegMapLocal[varName] = "";
                if (currentlyAvailableRegs.size() <= 4) {
                    break;//we're out of registers, lets hold onto a few temporaries
                }
                else {

                    auto reg = currentlyAvailableRegs.back();
                    currentlyUsedRegs.push_back(reg);
                    currentlyAvailableRegs.pop_back();

                    varToRegMapLocal[varName] = reg;
                    initStr+= blk->_intlists->getLoadInstruction(varName, reg) + "\n";
                    for (auto inst : blk->_instructions) {
                        inst->addToVarRegisterMap(varName, reg);
                    }
                }
            }

            Instruction* lastGeneric = nullptr;


            if (insts.size()>=2 && insts[insts.size()-2]->getInstructionType() == InstructionType::GenericInst && insts[insts.size() - 2]->getDefaultInstruction()[0]=='a') {
                lastGeneric = insts[insts.size() - 2];
            }

            for (auto inst : insts) {


                auto varsUsedByInst = inst->getUsedVars();
                //load vars into regs
                for (auto v : varsUsedByInst) {
                    if (inst->varRegMapContainsVar(v)) {
                        continue;
                    }
                    if (varToRegMapLocal[v] != "") {
                        continue;
                    }

                    auto reg = currentlyAvailableRegs.back();
                    currentlyUsedRegs.push_back(reg);
                    currentlyAvailableRegs.pop_back();
                    //std::cout << "v=" << v << std::endl;
                    out << intlsts->getLoadInstruction(v, reg) << std::endl;
                    inst->addToVarRegisterMap(v, reg);
                }
                if (inst->getInstructionType()==InstructionType::LabelInst|| inst->getInstructionType() == InstructionType::GenericInst) {
                    
                }
                else if(!blockInit){
                    out << initStr;
                    blockInit = true;
                }


                bool isReturnFunction = inst->getInstructionType() == InstructionType::ReturnFunctionInst;
                bool isFunctionCall = inst->getInstructionType() == InstructionType::CallFunctionInst;

                //store vars into mem

                std::string storeInst;
                if (inst == lastGeneric || (!lastGeneric && inst==insts[insts.size()-1])) {
                    for (auto [v, reg] : varToRegMapLocal) {

                        auto reg = inst->getRegFromVar(v);
                        storeInst = intlsts->getStoreInstruction(v, reg) + "\n";
                        if (!isReturnFunction) {
                            out << intlsts->getStoreInstruction(v, reg) << std::endl;
                        }
                        else {
                            (dynamic_cast<ReturnFunctionInstruction*>(inst))->setPreReturnInstruction(intlsts->getStoreInstruction(v, reg) + "\n");
                        }
                        inst->addToVarRegisterMap(v, reg);
                        currentlyAvailableRegs.push_back(currentlyUsedRegs.back());
                        currentlyUsedRegs.pop_back();

                    }
                }

                if (!isReturnFunction) {
                    //instruction
                    out << inst->getMIPSInstruction() << std::endl;
                }



                for (auto v : varsUsedByInst) {
                    if (inst->varRegMapContainsVar(v)) {
                        continue;
                    }
                    if (varToRegMapLocal[v] != "") {
                        continue;
                    }

                    auto reg = inst->getRegFromVar(v);
                    if (!isReturnFunction) {
                        out << intlsts->getStoreInstruction(v, reg) << std::endl;
                    }
                    else {
                        (dynamic_cast<ReturnFunctionInstruction*>(inst))->setPreReturnInstruction(intlsts->getStoreInstruction(v, reg) + "\n");
                    }
                    inst->addToVarRegisterMap(v, reg);
                    currentlyAvailableRegs.push_back(currentlyUsedRegs.back());
                    currentlyUsedRegs.pop_back();
                }


                if (isReturnFunction) {
                    out << inst->getMIPSInstruction() << std::endl;
                }


                if (isFunctionCall) {
                    out << storeInst;
                }

            }



        }
        //now go through each block and find most used variables, load store as appropriate
       /* for (auto blk: Block::blockList) {

            out << "############\n";

            std::map<std::string, int>mostUsedVars;

            for (auto inst : blk->_instructions) {
                auto vars = inst->getUsedVars();
                for (auto var : vars) {
                    if (inst->varRegMapContainsVar(var)) {
                        continue;
                    }
                    if (mostUsedVars.count(var) == 0) {
                        mostUsedVars[var] = 1;
                    }
                    else {
                        mostUsedVars[var]++;
                    }
                }
            }
            std::vector <std::pair<std::string, int>> usedVars;

            //now we have all the var's reference count, convert to vector

            for (auto pair : mostUsedVars) {
                usedVars.push_back(pair);
            }

            //now sort 

            sort(usedVars.begin(), usedVars.end(), cmp);


            std::map<std::string, std::string> varToRegMapLocal;

            int skipCount = 0;

            if (blk->_instructions[0]->getInstructionType() == InstructionType::LabelInst) {
                //print it immediately

                out << blk->_instructions[0]->getMIPSInstruction() << std::endl;
                skipCount++;
            }

            if (blk->_instructions.size()>=2 && blk->_instructions[1]->getInstructionType() == InstructionType::GenericInst) {

                out << blk->_instructions[1]->getMIPSInstruction() << std::endl;
                skipCount++;
            }


            //time to assign registers
            for (auto [varName, val] : usedVars) {
                varToRegMapLocal[varName] = "";
                if (currentlyAvailableRegs.size()<=4) {
                    break;//we're out of registers, lets hold onto a few temporaries
                }
                else {

                    auto reg = currentlyAvailableRegs.back();
                    currentlyUsedRegs.push_back(reg);
                    currentlyAvailableRegs.pop_back();

                    varToRegMapLocal[varName] = reg;
                    out << blk->_intlists->getLoadInstruction(varName, reg) << std::endl;
                    for (auto inst : blk->_instructions) {
                        inst->addToVarRegisterMap(varName, reg);
                    }
                }
            }
            int ct = 0;
            std::unordered_set <std::string>varsUsedByBlk;

            Instruction* secondLastInst=nullptr;
            for (auto inst : blk->_instructions) {
                bool isLastInstruction = inst== blk->_instructions[blk->_instructions.size()-1];
                bool isSecondLastInstruction = blk->_instructions.size()>=2 && inst == blk->_instructions[blk->_instructions.size() - 2] && blk->_instructions[blk->_instructions.size() - 2]->getInstructionType()==InstructionType::GenericInst;
                if (ct++< skipCount) {
                    continue;
                }
                if (isSecondLastInstruction && blk->_instructions[blk->_instructions.size() - 1]->getInstructionType()==InstructionType::ReturnFunctionInst) {
                    secondLastInst = inst;
                    continue;
                }

                auto varsUsedByInst = inst->getUsedVars();
                //load vars into regs
                for (auto v : varsUsedByInst) {
                    varsUsedByBlk.insert(v);
                    if (inst->varRegMapContainsVar(v)) {
                        continue;
                    }
                    if (varToRegMapLocal[v] !="") {
                        continue;
                    }

                    auto reg = currentlyAvailableRegs.back();
                    currentlyUsedRegs.push_back(reg);
                    currentlyAvailableRegs.pop_back();
                    //std::cout << "v=" << v << std::endl;
                    out << blk->_intlists->getLoadInstruction(v, reg) << std::endl;
                    inst->addToVarRegisterMap(v, reg);
                }
                auto instType = inst->getInstructionType();
                bool isReturnFunction = instType == InstructionType::ReturnFunctionInst;
                
                bool isJumper = false;

                if (instType == InstructionType::BreqInst
                    ||
                    instType == InstructionType::BrgeqInst
                    ||
                    instType == InstructionType::BrgtInst
                    ||
                    instType == InstructionType::BrleqInst
                    ||
                    instType == InstructionType::BrltInst
                    ||
                    instType == InstructionType::BrneqInst
                    ||
                    instType == InstructionType::CallFunctionInst
                    ||
                    instType == InstructionType::CallProcedureInst
                    ||
                    instType == InstructionType::GotoInst
                    ||
                    instType == InstructionType::ReturnFunctionInst
                    ||
                    instType == InstructionType::ReturnProcedureInst
                    ) {

                    isJumper = true;
                }

                if (!isJumper) {
                    //instruction
                    out << inst->getMIPSInstruction() << std::endl;
                }




                //store vars into mem

                if (isLastInstruction) {

                    for (auto v : varsUsedByBlk) {
                        if (inst->varRegMapContainsVar(v)) {
                            continue;
                        }
                        auto reg = inst->getRegFromVar(v);


                        if (inst->getInstructionType() == InstructionType::CallFunctionInst && v==inst->getAllVars()[0]) {
                            auto fni = dynamic_cast<CallFunctionInstruction*>(inst);
                            fni->setPostCall(blk->_intlists->getStoreInstruction(v, reg));
                        }

                        if (!isReturnFunction) {
                            out << blk->_intlists->getStoreInstruction(v, reg) << std::endl;
                        }
                        else {
                            (dynamic_cast<ReturnFunctionInstruction*>(inst))->setPreReturnInstruction(blk->_intlists->getStoreInstruction(v, reg) + "\n");
                            
                        }
                        if (secondLastInst) {
                            (dynamic_cast<ReturnFunctionInstruction*>(inst))->setPreReturnInstruction(secondLastInst->getDefaultInstruction() + "\n");
                        }
                        inst->addToVarRegisterMap(v, reg);
                    }
                }
                else {
                    for (auto v : varsUsedByInst) {

                    
                            if (inst->varRegMapContainsVar(v)) {
                                continue;
                            }
                            if (varToRegMapLocal[v] != "") {
                                continue;
                            }
                            auto reg = inst->getRegFromVar(v);



                            varsUsedByBlk.erase(varsUsedByBlk.find(v));
                            if (!isReturnFunction) {
                                out << blk->_intlists->getStoreInstruction(v, reg) << std::endl;
                            }
                            else {
                                (dynamic_cast<ReturnFunctionInstruction*>(inst))->setPreReturnInstruction(blk->_intlists->getStoreInstruction(v, reg) + "\n");
                            }
                            if (secondLastInst) {
                                (dynamic_cast<ReturnFunctionInstruction*>(inst))->setPreReturnInstruction(secondLastInst->getDefaultInstruction() + "\n");
                            }
                            inst->addToVarRegisterMap(v, reg);
                            currentlyAvailableRegs.push_back(currentlyUsedRegs.back());
                            currentlyUsedRegs.pop_back();
                        }
                }

                if (isJumper) {
                    out << inst->getMIPSInstruction() << std::endl;
                }

            }

            //make regs available again
            while (currentlyUsedRegs.size()) {
                currentlyAvailableRegs.push_back(currentlyUsedRegs.back());
                currentlyUsedRegs.pop_back();
            }


        }
        */
        return out.str();
    }
};

