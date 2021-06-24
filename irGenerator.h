#include "symbolTable.h"



enum IRErrorCodes{
	 SEMANTIC_ERROR= 4
};

enum IRErrorMessageID{
	IRERROR_NO_SUCH_TYPE,
	IRERROR_NO_ARRAY_ALLOWED_VAR,
	IRERROR_NO_SUCH_VARIABLE
};


void printErrorAndExit(int line, int col, IRErrorMessageID msg){
	
std::string desc;
	switch(msg){
		case IRERROR_NO_SUCH_TYPE:
		{
		desc = "type does not exist";
		break;
		}
		case IRERROR_NO_ARRAY_ALLOWED_VAR:
		{
		desc = "arrays are not allowed to be assigned directly to var. Must define as type first";
		break;
		}
		case IRERROR_NO_SUCH_VARIABLE:
		{
		desc = "variable doesn't exist";
		break;
		}
	
	}
	
	std::cerr << "line " <<line <<":" <<col<< " " << desc<<std::endl;
	//EXIT
	exit(SEMANTIC_ERROR);
}

class SemanticEnforcer : public TigerBaseListener{
public:
	Scope* globalScope;
	SemanticEnforcer(SymbolTableGenerator* symTable):globalScope(symTable->getTopLevelScope()){
	
	}

};

class IRGenerator{
public:
	IRGenerator();
};
