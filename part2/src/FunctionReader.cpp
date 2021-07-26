#include "FunctionReader.h"
#include "NaiveAllocator.h"
#include "BlockAllocator.h"
#include "BriggsAllocator.h"
#include <fstream>
#include <iostream>
#include <fstream>


//following 2 functions taken from https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string/25829233
std::string trim(const std::string& str,
    const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string reduce(const std::string& str,
    const std::string& fill = " ",
    const std::string& whitespace = " \t")
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}


std::list<std::string> FunctionReader::readFile(std::string filePath)
{
	std::list<std::string> lines;

	// Create and open a text file
	std::ifstream readF(filePath);

	//std::cout << "reading file " << filePath << std::endl;
	if (!readF) {
		std::cerr << "file path invalid" << std::endl;
		throw -1;
	}

	std::string line;
	while (std::getline(readF, line)) {
		// Output the text from the file

        line = reduce(line);
		if (line.length()) {
			lines.push_back(std::string(line));
		}
	}

	// Close the file
	readF.close();

	return lines;
}

FunctionReader::FunctionReader(std::string irFilePath, std::string outFilePath, bool outputMIPS, bool useNaive, bool useBlock, bool useBriggs, bool cfg, bool liveness) : _functions(), _globalIntList(){
	//read ir line by line and store as list
	auto lineList = readFile(irFilePath);

	//now split into functions (this is ideal since we need to manage stack pointers)


	while (lineList.size()) {
		std::string line;
		line = lineList.front();
		lineList.pop_front();

		if (line.rfind("start_program", 0) == 0) {

			line = lineList.front();
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
			lineList.pop_front();
			_globalIntList = new IntList(line);

		}
		else if (line.rfind("start_function", 0) == 0) {
			auto name = split(line.c_str(), ' ')[1];
			name = split(name.c_str(), '(')[0];
			auto functionDef = lineList.front();
			functionDef.erase(remove_if(functionDef.begin(), functionDef.end(), isspace), functionDef.end());
			lineList.pop_front();

			//now intlist
			auto intlist = lineList.front();
			intlist.erase(remove_if(intlist.begin(), intlist.end(), isspace), intlist.end());
			lineList.pop_front();

			auto function = new Function(name, functionDef, new IntList(intlist));
			_functions.push_back(function);
			//now parse instructions until we find end of function

			line = lineList.front();
			lineList.pop_front();
			while (!(line.rfind("end_function", 0) == 0)) {
				//parse this instruction
				auto instruction = Instruction::parse(line);
				function->addInstruction(instruction);
				instruction->setDebug(line);
				line = lineList.front();
				lineList.pop_front();
			}
			function->processVarDeclarationInstructions();


		}

	}

	std::string output = "";

	if (useNaive) {
		auto naiveAlloc = NaiveAllocator(_functions);
		output = naiveAlloc.getFinalOpList();
	}
	else if (useBlock){
		auto blockAlloc = BlockAllocator(_functions, cfg);
		output = blockAlloc.getFinalOpList();


		//TODO delet this
		auto naiveAlloc = NaiveAllocator(_functions);
		output = naiveAlloc.getFinalOpList();
	}


	//std::cout << naiveStr << std::endl;

	if(outputMIPS){
		std::ofstream out(outFilePath);
		out << output;
		out.close();
	}
};

