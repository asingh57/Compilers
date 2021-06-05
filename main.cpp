
#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "TigerLexer.h"
#include "TigerParser.h"

using namespace antlr4;
using namespace std;


enum LexerParserErrorCodes{
	LEXPARSE_NO_ERROR_FOUND = 0,
	LEXPARSE_ERROR_IN_PROG_ARGS = 1,
	LEXPARSE_LEXICAL_ERROR = 2,
	LEXPARSE_PARSER_ERROR =  3
};

class LexerErrorListener : public BaseErrorListener {
private:

  bool lexError;
public:
  bool getError(){
   return lexError;  
  }
  
  LexerErrorListener() : lexError(false){};
  

  inline void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                           const std::string &msg, std::exception_ptr e) override{
  		
  	lexError = true;
                           };
 };

class ParserErrorListener : public BaseErrorListener {
private:
  bool parseError;
public:
  bool getError(){
   return parseError;  
  }

  ParserErrorListener() : parseError(false){};

  inline void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                           const std::string &msg, std::exception_ptr e) override{
  	parseError = true;
                           };
};




int main(int argc, char *argv[]){

	std::ifstream stream;
  	stream.open(argv[1]);
  	if(!stream){
  		return LEXPARSE_ERROR_IN_PROG_ARGS;
  	}
	ANTLRInputStream input(stream);
	TigerLexer lexer(&input);
	lexer.removeErrorListeners();
	// now add our own error listener
	auto lexErrorListen = LexerErrorListener();
	lexer.addErrorListener(&lexErrorListen);
	//lex ready
	CommonTokenStream tokens(&lexer);
	
	tokens.fill();
	
	bool printTokens=false;
	if(printTokens){
		for (auto token : tokens.getTokens()) {
		  //std::cout << token->toString() << std::endl;
		}
	}
	if(lexErrorListen.getError()){
		return LEXPARSE_LEXICAL_ERROR;
	}


	auto parErrorListen = ParserErrorListener();
  	TigerParser parser(&tokens);
    	parser.removeErrorListeners();
	auto parseErrorListen = ParserErrorListener();
	parser.addErrorListener(&parseErrorListen);
  	
  	tree::ParseTree* tree = parser.tiger_program();

	if(parseErrorListen.getError()){
		return LEXPARSE_PARSER_ERROR;
	}


  	//std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
	return LEXPARSE_NO_ERROR_FOUND;
}
