#include "symbolTable.h"


enum IRErrorCodes{
	 SEMANTIC_ERROR= 4
};

enum IRErrorMessageID{
	IRERROR_NO_SUCH_TYPE
};

class IRGenerator  : public TigerBaseListener{

private:
	Scope* _globalScope;
	Scope* _currentScope;
	
	void printErrorAndExit(int line, int col, IRErrorMessageID msg){
	
	std::string desc;
		switch(msg){
			case IRERROR_NO_SUCH_TYPE:
			{
			desc = "type does not exist";
			break;
			}
		
		}
		
		std::cerr << "line " <<line <<":" <<col<< " " << desc<<std::endl;
		//EXIT
		exit(SEMANTIC_ERROR);
	}
	
	void escapeToParent(){
		if(_currentScope->getParent()){
			_currentScope = _currentScope->getParent();
		}
	}
	
	void createTypeDeclaration(TigerParser::Type_declarationContext *ctx){
	
		//insert to symbol table ID matching with symbol
		auto name = ctx->ID()->getText();
		Symbol* sym = new Symbol;//zero out everything
		sym->type = TYPE_ALIAS;
		if(ctx->type()->INTLIT()){
			//integer literal: this is an array
			sym->aliasType=TYPE_ARRAY;
			sym->arrayItemType= TYPE_INT;
			sym->len = std::stoi (ctx->type()->INTLIT()->getText());
		}		
		else if(ctx->type()->type_id()){
			//type is int
			sym->aliasType=TYPE_INT;
		}
		else if(ctx->type()->ID()){
			//another type
			//look this up in current symbol table
			auto rvalSymbol = _currentScope->getSymbol(ctx->type()->ID()->getText());
			if(!rvalSymbol){
			
				auto lineNum = ctx->getStart()->getLine();
				auto colNum = ctx->type()->ID()->getSymbol()->getCharPositionInLine();
				printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
			}
			sym->aliasType=TYPE_ALIAS;
			sym->alias = rvalSymbol;
			
		}
		
		_currentScope->addSymbol(name,sym);
		
	}
	
public:
	
	IRGenerator(){};
	
	void printSymbolTable(){
		_globalScope->printSymbolTable();
	}
	
  void enterTiger_program(TigerParser::Tiger_programContext *ctx) override { 
	_globalScope = new Scope(ctx->ID()->getText());
	_currentScope = _globalScope;
  }
  
  
  void enterType_declaration(TigerParser::Type_declarationContext *ctx) override { 
  	createTypeDeclaration(ctx);
  }  


  void enterVar_declaration(TigerParser::Var_declarationContext * ctx) override { 
  
  }
  
  

};
