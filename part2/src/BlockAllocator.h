#pragma once
#include "RegisterAllocator.h"
#include "Instruction.h"
#include "Function.h"
#include <iostream>
struct Block {
    static std::map<std::string, int> blockNameToNumberMap;
    static std::map<std::string, std::vector<int>> functionReturnCallNameToNumberMap;
    static int blockCounter;
    static std::vector<Block*> blockList;

    int _blkNumber;
    std::vector<Instruction*> _instructions;
    std::vector<std::string> _labelsThisPointsTo;
    std::vector<int> _blkNumbersThisPointsTo;
    Block() : _instructions(), _labelsThisPointsTo(), _blkNumber(blockCounter++), _blkNumbersThisPointsTo(){

    }

    Block(std::string name) : _instructions(), _labelsThisPointsTo(), _blkNumber(blockCounter++), _blkNumbersThisPointsTo() {
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
        Block* printblk = new Block("printi");
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
                        currblk = new Block(dynamic_cast<LabelInstruction*>(inst)->getLabelName());
                    }
                    else {
                        currblk = new Block;
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



        //now go through each block and find most used variables


        return out.str();
    }
};

