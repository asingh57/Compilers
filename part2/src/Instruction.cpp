#include "Instruction.h"
#include <algorithm>
#include <vector>


Instruction* Instruction::parse(std::string instStr)
{
    //remove all whitespaces
    instStr.erase(std::remove_if(instStr.begin(), instStr.end(), isspace), instStr.end());

    if (instStr.back()==':') {//this is a label
        return new LabelInstruction(instStr.substr(0, instStr.length()-1));
    }
    else{
        //this is an op, split commas
        auto parsed = split(instStr.c_str());
        auto op = parsed[0];
        parsed.erase(parsed.begin());
        auto remain = parsed;

        if (op == "assign") {
            if (remain.size()==2) {
                //int
                return new AssignInstruction(remain);
            }
            else {
                //int array
                return new InitialiseArrayConstInstruction(remain);
            }
        }
        else if (op == "add") {

            return new AddInstruction(remain);
        }
        else if (op == "sub") {

            return new SubInstruction(remain);
        }
        else if (op == "mult") {

            return new MultInstruction(remain);
        }
        else if (op == "div") {

            return new DivInstruction(remain);
        }
        else if (op == "and") {

            return new AndInstruction(remain);
        }
        else if (op == "or") {

            return new OrInstruction(remain);
        }
        else if (op == "goto") {

            return new GotoInstruction(remain);
        }
        else if (op == "breq") {

            return new BreqInstruction(remain);
        }
        else if (op == "brneq") {

            return new BrneqInstruction(remain);
        }
        else if (op == "brgt") {

            return new BrgtInstruction(remain);
        }
        else if (op == "brlt") {

            return new BrltInstruction(remain);
        }
        else if (op == "brleq") {

            return new BrleqInstruction(remain);
        }
        else if (op == "brgeq") {

            return new BrgeqInstruction(remain);
        }
        else if (op == "return") {
            if (remain.size()==0) {
                //returns nothing
                return new ReturnProcedureInstruction();
            }
            else {
                //returns something
                return new ReturnFunctionInstruction(remain);
            }
        }
        else if (op == "call") {

            return new CallProcedureInstruction(remain);
        }
        else if (op == "callr") {

            return new CallFunctionInstruction(remain);
        }
        else if (op == "array_store") {

            return new CallStoreArrayInstruction(remain);
        }
        else if (op == "array_load") {

            return new CallLoadArrayInstructionInstruction(remain);
        }
        else {
            throw "no proper instruction";
        }

    }

    return nullptr;
}



int Instruction::extraCounter = 0;
