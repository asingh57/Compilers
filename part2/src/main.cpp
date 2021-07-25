// CompilersPart2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FunctionReader.h"
#include <iostream>
#define IRFILENAME "array_assign.ir"

#ifdef _WIN32
    std::string path = "../../../irCode/";
#else
    std::string path = "~/Desktop/CompilersShared/Compilers/part2/irCode/";    
#endif


int main()
{
    std::string outpath = path + IRFILENAME + "assembly";
    path += IRFILENAME;
    auto fnr = FunctionReader(path, outpath);

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
