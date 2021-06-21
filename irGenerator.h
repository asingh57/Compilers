#include "symbolTable.h"


enum IRErrorCodes{
	 SEMANTIC_ERROR= 4
};

enum IRErrorMessageID{
	IRERROR_NO_SUCH_TYPE,
	IRERROR_NO_ARRAY_ALLOWED_VAR
};


void printErrorAndExit(int line, int col, IRErrorMessageID msg){
	
	
enum IRErrorCodes{
	 SEMANTIC_ERROR= 4
};

enum IRErrorMessageID{
	IRERROR_NO_SUCH_TYPE,
	IRERROR_NO_ARRAY_ALLOWED_VAR
};

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

class SymbolTableGenerator  : public TigerBaseListener{

private:
	Scope* globalScope;
	Scope* currentScope;
	bool inMain;

public:
	SymbolTableGenerator(): inMain(false){
		
	
	}
	void printSymbolTable(){
		globalScope->printSymbols();	
	}
	
	
	//derived functions
	
	
	  void enterTiger_program(TigerParser::Tiger_programContext *ctx) override { 
		globalScope = Scope::create();
		currentScope= globalScope;
	  }	  
	  
	  void enterFunct(TigerParser::FunctContext * ctx) override { 	  	
	  	
	  	auto name= ctx->ID()->getText();	  	
	  	//create symbol for function	
	  	auto retType = TYPE_VOID;
	  	std::string aliasName = "";
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
				retType=TYPE_INT;
			}
			else if(type->ID()){
				//another type
				//look this up in current symbol table
				auto rvalSymbol = currentScope->getSymbol(type->ID()->getText());
				if(!rvalSymbol){
				
					auto lineNum = type->ID()->getSymbol()->getLine();
					auto colNum = type->ID()->getSymbol()->getCharPositionInLine();
					printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
				}
				retType=TYPE_TYPEDEF;
				aliasName = rvalSymbol->getName();
				
			}
		}
	  	SymbolFunc * sym = new SymbolFunc(name, currentScope,retType,aliasName); 
	  	currentScope->addSymbol(name, sym);
	  	currentScope=Scope::create(currentScope);
	  	sym->setAssociatedScope(currentScope);
  		if(ctx->param_list()){
			auto parList = ctx->param_list()->param_list_tail();
			auto par = ctx->param_list()->param();
			while(par){
								
				bool hasValue = false;
				//add par to symbol table
				auto varName = par->ID()->getText();
				auto name = varName;
				auto storageclass=STORAGE_VAR;
				auto type = par->type();
				auto deriveFromType = TYPE_INT;
				std::string deriveFromSymbolName = "";
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
					deriveFromType=TYPE_INT;
				}
				else if(type->ID()){
					//another type
					//look this up in current symbol table
					auto rvalSymbol = currentScope->getSymbol(type->ID()->getText());
					if(!rvalSymbol){
					
						auto lineNum = type->ID()->getSymbol()->getLine();
						auto colNum = type->ID()->getSymbol()->getCharPositionInLine();
						printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
					}
					deriveFromType=TYPE_TYPEDEF;
					deriveFromSymbolName = rvalSymbol->getName();						
				}		
				//now add this symbol
				SymbolVariable *var = new SymbolVariable(
				name, 
				currentScope, 
				deriveFromType, 
				deriveFromSymbolName /*used if deriveFromType is TYPE_TYPEDEF*/, 
				storageclass, 
				hasValue ,
				0/*gets assigned to zero if StorageClass  static*/);
				sym->addParam(var);	
						
				par=parList->param();
				parList=parList->param_list_tail();
				if(!parList){
					break;
				}
			}
		
		}
	  	
	  	
	  	
	  	
	  }
	  
	   void exitFunct(TigerParser::FunctContext * ctx) override {
	   	currentScope=currentScope->parent();
	   }
	  
	  
	  
	  void enterType_declaration(TigerParser::Type_declarationContext *ctx) override { 
		//insert to symbol table ID matching with symbol
		auto name = ctx->ID()->getText();
		bool isArray= false;
		int arrayLen = 0;
		Type deriveFromType;
		std::string deriveFromSymbolName;
		if(ctx->type()->INTLIT()){
			//integer literal: this is an array
			isArray=true;
			arrayLen = std::stoi (ctx->type()->INTLIT()->getText());
			deriveFromType=TYPE_INT;
		}		
		else if(ctx->type()->type_id()){
			//type is int
			deriveFromType=TYPE_INT;
		}
		else if(ctx->type()->ID()){
			//another type
			//look this up in current symbol table
			auto rvalSymbol = currentScope->getSymbol(ctx->type()->ID()->getText());
			if(!rvalSymbol){
			
				auto lineNum = ctx->type()->ID()->getSymbol()->getLine();
				auto colNum = ctx->type()->ID()->getSymbol()->getCharPositionInLine();
				printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
			}
			deriveFromType=TYPE_TYPEDEF;
			deriveFromSymbolName = rvalSymbol->getName();
			
		}
		
		Symbol* sym = new SymbolTypedef(
			name, 
			currentScope, 
			isArray, 
			arrayLen, 
			deriveFromType, 
			deriveFromSymbolName
			);
		currentScope->addSymbol(name,sym);
	  }  


	  void enterVar_declaration(TigerParser::Var_declarationContext * ctx) override { 
		std::vector<std::string> varNames;
		Type deriveFromType=TYPE_INT;
		std::string deriveFromSymbolName=""; /*used if deriveFromType is TYPE_TYPEDEF*/
		StorageClass storageclass=STORAGE_VAR; 
		bool hasValue=false;
		int defaultValue=0;
		
		
		auto idlist = ctx->id_list();
		while(idlist->id_list()){
			varNames.push_back(idlist->ID()->getText());
			idlist= idlist->id_list();
		}
		varNames.push_back(idlist->ID()->getText());
		
		storageclass= STORAGE_VAR;
		if(ctx->storage_class()->STATIC()){
			//local var
			storageclass = STORAGE_STATIC;
		}

		
		if(ctx->type()->INTLIT()){
			//integer literal: this is an array NOT allowed according to 3.3 of spec
			
			auto lineNum = ctx->type()->ARRAY()->getSymbol()->getLine();
			auto colNum = ctx->type()->ARRAY()->getSymbol()->getCharPositionInLine();
			printErrorAndExit(lineNum,colNum, IRERROR_NO_ARRAY_ALLOWED_VAR);
			
		}		
		else if(ctx->type()->type_id()){
			//type is int
			deriveFromType=TYPE_INT;
		}
		else if(ctx->type()->ID()){
			//another type
			//look this up in current symbol table
			auto rvalSymbol = currentScope->getSymbol(ctx->type()->ID()->getText());
			if(!rvalSymbol){
			
				auto lineNum = ctx->type()->ID()->getSymbol()->getLine();
				auto colNum = ctx->type()->ID()->getSymbol()->getCharPositionInLine();
				printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
			}
			deriveFromType=TYPE_TYPEDEF;
			deriveFromSymbolName = rvalSymbol->getName();			
		}
		
		if(ctx->optional_init()->constant()){
			int val = std::stoi (ctx->optional_init()->constant()->INTLIT()->getText());
			defaultValue = val;
			hasValue = true;
		}
		else if(storageclass==STORAGE_STATIC){
			defaultValue = 0;
			hasValue = true;
		}
		for(auto name: varNames){
			SymbolVariable *sym = new SymbolVariable(
			name, 
			currentScope, 
			deriveFromType, 
			deriveFromSymbolName /*used if deriveFromType is TYPE_TYPEDEF*/, 
			storageclass, 
			hasValue ,
			defaultValue/*gets assigned to zero if StorageClass  static*/);
			currentScope->addSymbol(name,sym);		
		}
	  }
	
	
};
