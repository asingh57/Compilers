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
			case IRERROR_NO_ARRAY_ALLOWED_VAR:
			{
			desc = "arrays are not allowed to be assigned directly to var. Must define as type first";
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
			
				auto lineNum = ctx->type()->ID()->getSymbol()->getLine();
				auto colNum = ctx->type()->ID()->getSymbol()->getCharPositionInLine();
				printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
			}
			sym->aliasType=TYPE_ALIAS;
			sym->alias = rvalSymbol;
			
		}
		
		_currentScope->addSymbol(name,sym);
		
	}
	
	
	void createVarDeclaration(TigerParser::Var_declarationContext * ctx){
		Symbol* sym = new Symbol;//zero out everything
		std::vector<std::string> varNames;
		
		auto idlist = ctx->id_list();
		while(idlist->id_list()){
			varNames.push_back(idlist->ID()->getText());
			idlist= idlist->id_list();
		}
		varNames.push_back(idlist->ID()->getText());
		
		StorageClass sc= STORAGE_VAR;
		if(ctx->storage_class()->STATIC()){
			//local var
			sc = STORAGE_STATIC;
		}
		sym->storageclass=sc;		
		sym->hasValue = false;
		
		if(ctx->type()->INTLIT()){
			//integer literal: this is an array NOT allowed according to 3.3 of spec
			
			auto lineNum = ctx->type()->ARRAY()->getSymbol()->getLine();
			auto colNum = ctx->type()->ARRAY()->getSymbol()->getCharPositionInLine();
			printErrorAndExit(lineNum,colNum, IRERROR_NO_ARRAY_ALLOWED_VAR);
			
		}		
		else if(ctx->type()->type_id()){
			//type is int
			sym->type=TYPE_INT;
		}
		else if(ctx->type()->ID()){
			//another type
			//look this up in current symbol table
			auto rvalSymbol = _currentScope->getSymbol(ctx->type()->ID()->getText());
			if(!rvalSymbol){
			
				auto lineNum = ctx->type()->ID()->getSymbol()->getLine();
				auto colNum = ctx->type()->ID()->getSymbol()->getCharPositionInLine();
				printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
			}
			sym->type=TYPE_ALIAS_ASSIGNED;
			sym->alias = rvalSymbol;			
		}
		
		if(ctx->optional_init()->constant()){
			int val = std::stoi (ctx->optional_init()->constant()->INTLIT()->getText());
			sym->val = val;
			sym->hasValue = true;
		}
		else if(sc==STORAGE_STATIC){
			sym->val = 0;
			sym->hasValue = true;
		}
		for(auto name: varNames){
			Symbol *copy = new Symbol;
			*copy= *sym;
			_currentScope->addSymbol(name,copy);		
		}
	
	}
	
	void createFunctDeclaration(TigerParser::FunctContext * ctx){
		auto sc=new Scope(ctx->ID()->getText(), _currentScope);
		Symbol* sym = new Symbol;
		sym->scope=sc;
		sym->type=TYPE_FUNCTION;
		sym->inputVariables= std::vector<Symbol*>();
		sym->returnType=TYPE_VOID;
		if(ctx->ret_type() && ctx->ret_type()->type()){
			auto type = ctx->ret_type()->type();
			if(type->INTLIT()){
					//integer literal: this is an array NOT ALLOWED
					auto lineNum = type->ARRAY()->getSymbol()->getLine();
					auto colNum = type->ARRAY()->getSymbol()->getCharPositionInLine();
					printErrorAndExit(lineNum,colNum, IRERROR_NO_ARRAY_ALLOWED_VAR);
			}		
			else if(type->type_id()){
				//type is int
				sym->returnType=TYPE_INT;
			}
			else if(type->ID()){
				//another type
				//look this up in current symbol table
				auto rvalSymbol = _currentScope->getSymbol(type->ID()->getText());
				if(!rvalSymbol){
				
					auto lineNum = type->ID()->getSymbol()->getLine();
					auto colNum = type->ID()->getSymbol()->getCharPositionInLine();
					printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
				}
				sym->returnType=TYPE_ALIAS_ASSIGNED;
				sym->alias = rvalSymbol;
				
			}
		}
		
		if(ctx->param_list()){
			auto parList = ctx->param_list()->param_list_tail();
			auto par = ctx->param_list()->param();
			while(par){
				Symbol* inputSym = new Symbol;				
				inputSym->hasValue = false;
				//add par to symbol table
				auto varName = par->ID()->getText();
				inputSym->name = varName;
				inputSym->storageclass=STORAGE_VAR;
				auto type = par->type();
				if(type->INTLIT()){
					//integer literal: this is an array NOT ALLOWED
					/*
					inputSym->type=TYPE_ARRAY;
					inputSym->arrayItemType= TYPE_INT;
					inputSym->len = std::stoi (type->INTLIT()->getText());
					*/
					auto lineNum = type->ARRAY()->getSymbol()->getLine();
					auto colNum = type->ARRAY()->getSymbol()->getCharPositionInLine();
					printErrorAndExit(lineNum,colNum, IRERROR_NO_ARRAY_ALLOWED_VAR);
				}		
				else if(type->type_id()){
					//type is int
					inputSym->type=TYPE_INT;
				}
				else if(type->ID()){
					//another type
					//look this up in current symbol table
					auto rvalSymbol = _currentScope->getSymbol(type->ID()->getText());
					if(!rvalSymbol){
					
						auto lineNum = type->ID()->getSymbol()->getLine();
						auto colNum = type->ID()->getSymbol()->getCharPositionInLine();
						printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
					}
					inputSym->type=TYPE_ALIAS_ASSIGNED;
					inputSym->alias = rvalSymbol;
					
				}				
				sym->inputVariables.push_back(inputSym);
				par=parList->param();
				parList=parList->param_list_tail();
				if(!parList){
					break;
				}
			}
		
		}
		
		
		_currentScope->addSymbol(ctx->ID()->getText(),sym);	
		_currentScope= sc;
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
  
  
  void enterFunct(TigerParser::FunctContext * ctx) override { 
  	createFunctDeclaration(ctx);
  }
  void exitFunct(TigerParser::FunctContext * ctx) override {
  	escapeToParent();
  }
  
  
  void enterType_declaration(TigerParser::Type_declarationContext *ctx) override { 
  	createTypeDeclaration(ctx);
  }  


  void enterVar_declaration(TigerParser::Var_declarationContext * ctx) override { 
  	createVarDeclaration(ctx);
  }
  
  

  
  

};
