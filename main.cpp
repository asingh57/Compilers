
#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "TigerLexer.h"
#include "TigerParser.h"
#include "irGenerator.h"

using namespace antlr4;
using namespace std;

//-----------------------------------------------------------------------------------------------------
//ERRORS FOR LEXER AND PARSER

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

//-----------------------------------------------------------------------------------------------------



int main(int argc, char *argv[]){

//PART 1 of the assignment
//-----------------------------------------------------------------------------------------------------
	bool hasParseError=false;
	bool hasLexError=false;
	if(argc < 3){
		//cout << "argc ==" << argc << endl;
		return LEXPARSE_ERROR_IN_PROG_ARGS;
	}
	string inputFileName="";
	bool printTokens=false;
	bool printParseTree=false;
	bool printSymbolTable=false;
	bool outputIR=false;
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
		else if(arg == "-s"){
			printSymbolTable= true;
		}
		else if(arg == "–-ir"){
			outputIR = true;
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
		
		std::string type = vocab.getSymbolicName(token->getType());
		if(type==""){
			type = vocab.getLiteralName(token->getType());
		}
		if(type=="EOF"){
			continue;
		}
		
		std::cout <<"<";
		std::cout <<type;
		
		std::cout <<", \"";
		
		std::cout <<token->getText();
		
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
//-----------------------------------------------------------------------------------------------------
	
	
	//IRGenerator intermediateRep= IRGenerator();
	
	SymbolTableGenerator symT;//collects function names
  	tree::ParseTreeWalker::DEFAULT.walk(&symT, tree);
	
	SemanticEnforcer semE(&symT);//does semantic enforcement
  	tree::ParseTreeWalker::DEFAULT.walk(&semE, tree);
	
	
	if(printSymbolTable){
	
		symT.printSymbolTable();
	}
	
	
	
	
	
	return LEXPARSE_NO_ERROR_FOUND;
}
