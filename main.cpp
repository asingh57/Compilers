
#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "TigerLexer.h"
#include "TigerParser.h"

using namespace antlr4;
using namespace std;


int main(int argc, char *argv[]){

	std::ifstream stream;
  	stream.open(argv[1]);
	ANTLRInputStream input(stream);
	TigerLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	tokens.fill();
	for (auto token : tokens.getTokens()) {
	  //std::cout << token->toString() << std::endl;
	}

  	TigerParser parser(&tokens);
  	tree::ParseTree* tree = parser.tiger_program();

  	std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
	return 0;
}
