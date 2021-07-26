// CompilersPart2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FunctionReader.h"
#include <iostream>
#include <cstring> 
#define IRFILENAME "combo_arithmetic.ir"

#ifdef _WIN32
    std::string inPath = "../../../irCode/";
#else
    std::string inPath = "~/Desktop/CompilersShared/Compilers/part2/irCode/";
#endif


int main(int argc, char* argv[])
{
    std::string outpath;
    inPath += IRFILENAME;

    bool naive = false;
    bool block = false;
    bool briggs = false;
    bool cfg = false;
    bool liveness = false;
    bool outputMIPS = false;
    if (argc==1) {
        //naive = true;
        //outputMIPS = true;
        block = true;
        cfg = true;

        //briggs = true;
        liveness = true;
        outputMIPS = true;
    }
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (strcmp(argv[i], "--mips") == 0) {
            outputMIPS = true;
        }
        else if (strcmp(argv[i], "--cfg") == 0) {
            cfg = true;
        }
        else if (strcmp(argv[i], "--liveness") == 0) {
            liveness = true;
        }
        else if (arg == "-n") {
            naive = true;
        }
        else if (arg == "-b") {
            block = true;
        }
        else if (arg == "-g") {
            briggs = true;
        }
        else if (arg == "-i") {
            if (++i >= argc) {
                return -1;
            }
        }
        else if (arg == "-r") {
            if (++i >= argc) {
                return -1;
            }
            inPath= argv[i];
        }

    }

    if (!naive && !block && !briggs) {
        naive = true;
    }

    if (outputMIPS) {
        outpath = inPath;
        outpath = outpath.substr(0, outpath.find_last_of('.')) + ".s";

    }




    auto fnr = FunctionReader(inPath, outpath, outputMIPS, naive, block, briggs, cfg, liveness);
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
