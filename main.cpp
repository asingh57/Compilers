
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


	bool hasParseError=false;
	bool hasLexError=false;
	if(argc < 3){
		//cout << "argc ==" << argc << endl;
		return LEXPARSE_ERROR_IN_PROG_ARGS;
	}
	string inputFileName="";
	bool printTokens=false;
	bool printParseTree=false;
	for(int i = 1; i <argc ; i++){
		string arg = argv[i];
		if(arg == "-i"){
			if(++i>=argc){
				return LEXPARSE_ERROR_IN_PROG_ARGS;
			}
			inputFileName = argv[i];
		}
		else if(arg == "-l"){
			printTokens= true;
		}
		else if(arg == "-p"){
			printParseTree= true;
		}
		else {
			return LEXPARSE_ERROR_IN_PROG_ARGS;
		}
	}
	
	if(inputFileName==""){
		return LEXPARSE_ERROR_IN_PROG_ARGS;
	}
	else{
		//cout << "file name= " << inputFileName << endl;
	}

	std::ifstream stream;
  	stream.open(inputFileName);
  	if(!stream){
  		return LEXPARSE_ERROR_IN_PROG_ARGS;
  	}
	ANTLRInputStream input(stream);
	TigerLexer lexer(&input);
	//lexer.removeErrorListeners();
	// now add our own error listener
	auto lexErrorListen = LexerErrorListener();
	lexer.addErrorListener(&lexErrorListen);
	//lex ready
	CommonTokenStream tokens(&lexer);
	
	tokens.fill();
	
	auto vocab = lexer.getVocabulary();
	
	if(printTokens){
		for (auto token : tokens.getTokens()) {
		std::cout <<"<";
		
		std::string type = vocab.getSymbolicName(token->getType());
		if(type==""){
			type = vocab.getLiteralName(token->getType());
		}
		std::cout <<type;
		
		std::cout <<", \"";
		
		if(type!="EOF"){
			std::cout <<token->getText();
		}
		else{
			std::cout <<"EOF";
		}
		
		
		std::cout <<"\">" << std::endl;
		  //std::cout << token->toString() << std::endl;
		}
	}
	hasLexError=lexErrorListen.getError();


	auto parErrorListen = ParserErrorListener();
  	TigerParser parser(&tokens);
    	//parser.removeErrorListeners();
	auto parseErrorListen = ParserErrorListener();
	parser.addErrorListener(&parseErrorListen);
  	
  	tree::ParseTree* tree = parser.tiger_program();

	
	hasParseError=parseErrorListen.getError();
	

	if(printParseTree){
		std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
	}
	
	if(hasLexError){
		return LEXPARSE_LEXICAL_ERROR;
	}
	else if(hasParseError){
		return LEXPARSE_PARSER_ERROR;
	}
	
	
	return LEXPARSE_NO_ERROR_FOUND;
}
