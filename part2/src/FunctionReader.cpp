#include "FunctionReader.h"
#include "NaiveAllocator.h"
#include <fstream>
#include <iostream>


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

FunctionReader::FunctionReader(std::string filePath) : _functions(), _globalIntList(){
	//read ir line by line and store as list
	auto lineList = readFile(filePath);

	//now split into functions (this is ideal since we need to manage stack pointers)


	while (lineList.size()) {
		std::string line;
		line = lineList.front();
		lineList.pop_front();

		if (line.rfind("start_program", 0) == 0) {

			line = lineList.front();
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
			lineList.pop_front();
			_globalIntList = IntList(line);

		}
		else if (line.rfind("start_function", 0) == 0) {
			auto functionDef = lineList.front();
			functionDef.erase(remove_if(functionDef.begin(), functionDef.end(), isspace), functionDef.end());
			lineList.pop_front();

			//now intlist
			auto intlist = lineList.front();
			intlist.erase(remove_if(intlist.begin(), intlist.end(), isspace), intlist.end());
			lineList.pop_front();

			auto function = new Function(functionDef, IntList(intlist));
			_functions.push_back(function);
			//now parse instructions until we find end of function

			while (!(line.rfind("end_function", 0) == 0)) {
				line = lineList.front();
				lineList.pop_front();
				//parse this instruction
				auto instruction = Instruction::parse(line);
				function->addInstruction(instruction);
			}


		}

	}





};

