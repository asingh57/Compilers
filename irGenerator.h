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

class IRGenerator;

class FunctionReader  : public TigerBaseListener{

friend class IRGenerator;
private:
	Scope* globalScope;
	Scope* currentScope;
   	ASTNode* currentASTNode;

public:
	FunctionReader(){
		
	
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
	  	sym->setAssociatedScope(Scope::create(currentScope));
	  	/*
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
				deriveFromSymbolName , 
				storageclass, 
				hasValue ,
				0);
				sym->addParam(var);	
				currentScope->addSymbol(name,var);		
				par=parList->param();
				parList=parList->param_list_tail();
				if(!parList){
					break;
				}
			}
		
		}*/
		
	  	
	  }

};




class IRGenerator  : public TigerBaseListener{
private:
	Scope* globalScope;
	Scope* currentScope;
	std::vector<ASTNode*> astStack; 
public:
	IRGenerator(FunctionReader fr): globalScope(fr.globalScope), currentScope(fr.globalScope),astStack(){
		
	}
	
	void enterFunct(TigerParser::FunctContext * ctx) override {
		auto name= ctx->ID()->getText();
		auto sym =  dynamic_cast<SymbolFunc*>(globalScope->getSymbol(name));
		
		currentScope= sym->getAssociatedScope();
		
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
				deriveFromSymbolName , 
				storageclass, 
				hasValue ,
				0);
				sym->addParam(var);	
				currentScope->addSymbol(name,var);		
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

				
	
   void exitLogical_op_expr(TigerParser::Logical_op_exprContext * ctx) override { 
   
   
   		if(ctx->logical_op_expr_ext() && ctx->logical_op_expr_ext()->compare_op_expr() ){//then we have power operators
	   		//pop everything from stack, and convert it into a new AST node   
	   		
	   		std::cout <<astStack.size() << std::endl;
	   		for(auto a : astStack){
	   			std::cout <<"|" << a->_var;
	   		}
	   				
	   		std::cout << std::endl;
	   		
	   		auto op= Operator_plus;
	   		
	   		auto nd = new ASTNode();
	   		nd->_isVar=true;
	   		auto v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
	   		nd->_var= v->getName();   		
			currentScope->addSymbol(v->getName(),v);
	   		//push that node
	   		
	   		//now start processing all nodes
	   		auto v1 =  astStack.back();
	   		nd->_left = v1;
	   		astStack.pop_back();
	   		auto v2 =  astStack.back();
	   		nd->_right = v2;
	   		astStack.pop_back();
	   		nd->_op= op;
	   		   
	   		while(astStack.size()){
	   			v1= nd;
	   			v2= astStack.back();
	   			astStack.pop_back();
	   			
	   			nd = new ASTNode();
	   			nd->_left = v1;
	   			nd->_right = v1;
	   			nd->_isVar=true;
	   			v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
	   			nd->_var= v->getName();   	
	   			nd->_op= op;	
				currentScope->addSymbol(v->getName(),v);
	   		}	
	   		
	   		astStack.push_back(nd);   		
	   	}
   
   
   }

   void exitCompare_op_expr(TigerParser::Compare_op_exprContext * ctx) override { 
   
	   if(ctx->compare_op_expr_ext() && ctx->compare_op_expr_ext()->add_op_expr() ){//then we have power operators
	   		//pop everything from stack, and convert it into a new AST node   
	   		
	   		std::cout <<astStack.size() << std::endl;
	   		for(auto a : astStack){
	   			std::cout <<"|" << a->_var;
	   		}
	   				
	   		std::cout << std::endl;
	   		
	   		auto op= Operator_plus;
	   		
	   		auto nd = new ASTNode();
	   		nd->_isVar=true;
	   		auto v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
	   		nd->_var= v->getName();   		
			currentScope->addSymbol(v->getName(),v);
	   		//push that node
	   		
	   		//now start processing all nodes
	   		auto v1 =  astStack.back();
	   		nd->_left = v1;
	   		astStack.pop_back();
	   		auto v2 =  astStack.back();
	   		nd->_right = v2;
	   		astStack.pop_back();
	   		nd->_op= op;
	   		   
	   		while(astStack.size()){
	   			v1= nd;
	   			v2= astStack.back();
	   			astStack.pop_back();
	   			
	   			nd = new ASTNode();
	   			nd->_left = v1;
	   			nd->_right = v1;
	   			nd->_isVar=true;
	   			v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
	   			nd->_var= v->getName();   	
	   			nd->_op= op;	
				currentScope->addSymbol(v->getName(),v);
	   		}	
	   		
	   		astStack.push_back(nd);   		
	   	}
   
   
   
   
   }

   void exitAdd_op_expr(TigerParser::Add_op_exprContext * ctx) override { 
   	if(ctx->add_op_expr_ext() && ctx->add_op_expr_ext()->mult_op_expr() ){//then we have power operators
   		//pop everything from stack, and convert it into a new AST node   
   		
   		std::cout <<astStack.size() << std::endl;
   		for(auto a : astStack){
   			std::cout <<"|" << a->_var;
   		}
   				
   		std::cout << std::endl;
   		
   		auto op= Operator_plus;
   		
   		auto nd = new ASTNode();
   		nd->_isVar=true;
   		auto v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
   		nd->_var= v->getName();   		
		currentScope->addSymbol(v->getName(),v);
   		//push that node
   		
   		//now start processing all nodes
   		auto v1 =  astStack.back();
   		nd->_left = v1;
   		astStack.pop_back();
   		auto v2 =  astStack.back();
   		nd->_right = v2;
   		astStack.pop_back();
   		nd->_op= op;
   		   
   		while(astStack.size()){
   			v1= nd;
   			v2= astStack.back();
   			astStack.pop_back();
   			
   			nd = new ASTNode();
   			nd->_left = v1;
   			nd->_right = v1;
   			nd->_isVar=true;
   			v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
   			nd->_var= v->getName();   	
   			nd->_op= op;	
			currentScope->addSymbol(v->getName(),v);
   		}	
   		
   		astStack.push_back(nd);   		
   	}
   
   
   
   }
   
   void exitMult_op_expr(TigerParser::Mult_op_exprContext * ctx) override { 
   	if(ctx->mult_op_expr_ext() && ctx->mult_op_expr_ext()->pow_op_expr() ){//then we have power operators
   		//pop everything from stack, and convert it into a new AST node   
   		
   		std::cout <<astStack.size() << std::endl;
   		for(auto a : astStack){
   			std::cout <<"|" << a->_var;
   		}
   				
   		std::cout << std::endl;
   		
   		auto op= Operator_multiply;
   		
   		auto nd = new ASTNode();
   		nd->_isVar=true;
   		auto v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
   		nd->_var= v->getName();   		
		currentScope->addSymbol(v->getName(),v);
   		//push that node
   		
   		//now start processing all nodes
   		auto v1 =  astStack.back();
   		nd->_left = v1;
   		astStack.pop_back();
   		auto v2 =  astStack.back();
   		nd->_right = v2;
   		astStack.pop_back();
   		nd->_op= op;
   		   
   		while(astStack.size()){
   			v1= nd;
   			v2= astStack.back();
   			astStack.pop_back();
   			
   			nd = new ASTNode();
   			nd->_left = v1;
   			nd->_right = v1;
   			nd->_isVar=true;
   			v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
   			nd->_var= v->getName();   	
   			nd->_op= op;	
			currentScope->addSymbol(v->getName(),v);
   		}	
   		
   		astStack.push_back(nd);   		
   	}
   
   
   }

   void exitPow_op_expr(TigerParser::Pow_op_exprContext * ctx) override { 
   	if(ctx->pow_op_expr_ext() && ctx->pow_op_expr_ext()->expr_no_op() ){//then we have power operators
   		//pop everything from stack, and convert it into a new AST node   
   		
   		std::cout <<astStack.size() << std::endl;
   		for(auto a : astStack){
   			std::cout <<"|" << a->_var;
   		}
   		std::cout << std::endl;
   				
   		auto nd = new ASTNode();
   		nd->_isVar=true;
   		auto v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
   		nd->_var= v->getName();   		
		currentScope->addSymbol(v->getName(),v);
   		//push that node
   		
   		//now start processing all nodes
   		auto v1 =  astStack.back();
   		nd->_left = v1;
   		astStack.pop_back();
   		auto v2 =  astStack.back();
   		nd->_right = v2;
   		astStack.pop_back();
   		nd->_op= Operator_pow;
   		   
   		while(astStack.size()){
   			v1= nd;
   			v2= astStack.back();
   			astStack.pop_back();
   			
   			nd = new ASTNode();
   			nd->_left = v1;
   			nd->_right = v1;
   			nd->_isVar=true;
   			v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,false,0);
   			nd->_var= v->getName();   		
   			nd->_op= Operator_pow;
			currentScope->addSymbol(v->getName(),v);
   		}	
   		
   		astStack.push_back(nd);   		
   	}
   	
   
   }
   
   void exitExpr_no_op(TigerParser::Expr_no_opContext * ctx) override { 
   
   	if(ctx->constant()){
   		//create temp with assigned value
   		auto nd = new ASTNode();
   		nd->_isVar=true;
   		auto v= new SymbolVariable(currentScope,TYPE_INT,"",STORAGE_VAR,true,std::stoi(ctx->constant()->INTLIT()->getText()));
   		nd->_var= v->getName();   		
		currentScope->addSymbol(v->getName(),v);
   		astStack.push_back(nd);
   	}
   }




  void exitLvalue(TigerParser::LvalueContext * ctx) override { 
  	auto nd = new ASTNode();
	nd->_isVar=true;
	//use existing var
	nd->_var = ctx->ID()->getText();
	
	if(ctx->lvalue_tail() && ctx->lvalue_tail()->expr()){  
		
   		
		nd->_isIndex= true;		
		nd->_index = astStack.back();
		astStack.pop_back();
	}
	astStack.push_back(nd);
  }




  void exitAssignment_stat(TigerParser::Assignment_statContext * ctx) override { 
  	//pop last ASTNode and put it in rval
  	
  	//use lvalue l_tail to determine remaining AST nodes to take out, and put them in lval of assignment
  
  }
  
  
  
  void enterStat_seq_if(TigerParser::Stat_seq_ifContext * ctx) override { 
  	
  }
  void exitStat_seq_if(TigerParser::Stat_seq_ifContext * ctx) override { 
  
  }
  
  void enterIf_else_stat



};
















