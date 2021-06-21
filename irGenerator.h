#include "symbolTable.h"


enum IRErrorCodes{
	 SEMANTIC_ERROR= 4
};

enum IRErrorMessageID{
	IRERROR_NO_SUCH_TYPE,
	IRERROR_NO_ARRAY_ALLOWED_VAR
};

class IRGenerator  : public TigerBaseListener{

private:
	Scope* mainScope;

public:
	IRGenerator(): mainScope(Scope::create()){
		
	
	}
	
	
	void printSymbolTable(){
		mainScope->printSymbols();	
	}
};
