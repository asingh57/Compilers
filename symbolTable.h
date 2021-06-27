#ifndef _SYMBOLTABLE
#define _SYMBOLTABLE
#include "stat.h"

#include <map>
#include <string>
#include <variant>
#include <vector>
#include <cstring>

enum IRErrorCodes{
	 SEMANTIC_ERROR= 4
};

enum IRErrorMessageID{
	IRERROR_NO_SUCH_TYPE,
	IRERROR_NO_ARRAY_ALLOWED_VAR,
	IRERROR_NO_SUCH_VARIABLE,
	IRERROR_ZERO_SIZED_ARRAY,
	IRERROR_NOT_ASSIGNABLE_TYPE,
	IRERROR_NONSTATICVAR_NOT_ALLOWED_MAIN,
	IRERROR_NOT_ASSIGNABLE_VAR,
	IRERROR_SYMBOL_ALREADY_EXISTS,
	IRERROR_ILLEGAL_BREAK_STATEMENT,
	IRERROR_COMPARATORS_NON_ASSOCIATIVE,
	IRERROR_PROCEDURE_NON_NULL_RETURN,
	IRERROR_FUNCTION_NO_RETURN_VAL,
	IRERROR_ARRAY_OPERATOR,
	IRERROR_INDEX_ON_NON_ARRAY
	
};


void printErrorAndExit(int line, int col, IRErrorMessageID msg);


class ErrorCheckingTask{
public:
	static std::vector<std::function<void()>> tasks;
	
};

class SymbolTableGenerator : public TigerBaseListener{
public:
	Scope* globalScope;
	SymbolTableGenerator(){
	}
	
	Scope* getTopLevelScope(){
		return globalScope;
	}

void printSymbolTable(){
	logger("printing symbol table");
	globalScope->printSymbols();

}

  virtual void enterTiger_program(TigerParser::Tiger_programContext * ctx) override { 
  
	logger("global scope created");
	globalScope= Scope::create();
	globalScope->_programName= ctx->ID()->getText();
  }
  virtual void exitTiger_program(TigerParser::Tiger_programContext * /*ctx*/) override { 
  	Scope::scopeStack.pop_back();
  }



  virtual void enterType_declaration(TigerParser::Type_declarationContext * ctx) override {
  	//add type declarations to last scope
  	auto name = ctx->ID()->getText();
  	
  	int lineNum = ctx->ID()->getSymbol()->getLine();
	int charPos =  ctx->ID()->getSymbol()->getCharPositionInLine();
	std::string scopeName;
	auto res = Scope::scopeStack.back()->getSymbol(ctx->ID()->getText(), scopeName,false);
	if(res!=nullptr){
		ErrorCheckingTask::tasks.push_back([lineNum,charPos](){				
			printErrorAndExit(lineNum,charPos, IRERROR_SYMBOL_ALREADY_EXISTS);	
		});
	}
  	
	bool isArray= false;
	int arrayLen = 0;
	Type deriveFromType;
	std::string deriveFromSymbolName;
	
	auto sym = new SymbolTypedef(
		name,
		isArray, 
		arrayLen, 
		deriveFromType, 
		deriveFromSymbolName
		);
	if(ctx->type()->INTLIT()){
		//integer literal: this is an array
		isArray=true;
		arrayLen = std::stoi (ctx->type()->INTLIT()->getText());
		int lineNum =  ctx->type()->INTLIT()->getSymbol()->getLine();
		int charPos =  ctx->type()->INTLIT()->getSymbol()->getCharPositionInLine();
		ErrorCheckingTask::tasks.push_back([arrayLen,lineNum,charPos](){
			if(arrayLen<=0){
				printErrorAndExit(lineNum,charPos, IRERROR_ZERO_SIZED_ARRAY);				
			}		
		});
		
		deriveFromType=TYPE_INT;
	}		
	else if(ctx->type()->type_id()){
		//type is int
		deriveFromType=TYPE_INT;
	}
	else if(ctx->type()->ID()){
	
	
		int lineNum =  ctx->type()->ID()->getSymbol()->getLine();
		int charPos =  ctx->type()->ID()->getSymbol()->getCharPositionInLine();
		deriveFromSymbolName = ctx->type()->ID()->getText();
		Scope* back = Scope::scopeStack.back();
		ErrorCheckingTask::tasks.push_back([deriveFromSymbolName,lineNum,charPos,back,sym](){
			std::string scopeName;
			auto res = back->getSymbol(deriveFromSymbolName, scopeName);
			if(res==nullptr){
				printErrorAndExit(lineNum,charPos, IRERROR_NO_SUCH_TYPE);				
			}
			else if(res->getType()!=TYPE_TYPEDEF){
				printErrorAndExit(lineNum,charPos, IRERROR_NOT_ASSIGNABLE_TYPE);				
			}
			else{
				sym->_deriveFromSymbolName=deriveFromSymbolName;//+scopeName;
			}
		});
	
		deriveFromType=TYPE_TYPEDEF;
		
	}
	sym->_isArray = isArray;
	sym->_arrayLen = arrayLen;
	sym->_deriveFromType = deriveFromType;
	sym->_deriveFromSymbolName = deriveFromSymbolName;
  }
  

  virtual void enterVar_declaration(TigerParser::Var_declarationContext * ctx) override { 
  	//add var declarations to last scope
  	std::vector<std::string> varNames;
	Type deriveFromType=TYPE_INT;
	std::string deriveFromSymbolName=""; /*used if deriveFromType is TYPE_TYPEDEF*/
	StorageClass storageclass=STORAGE_VAR; 
	bool hasValue=false;
	int defaultValue=0;
	
	auto back = Scope::scopeStack.back();
	
	auto idlist = ctx->id_list();
	while(idlist->id_list()){
		//check if this var exists in this scope
		int lineNum = idlist->ID()->getSymbol()->getLine();
		int charPos =  idlist->ID()->getSymbol()->getCharPositionInLine();
		std::string scopeName;
		auto res = back->getSymbol(idlist->ID()->getText(), scopeName,false);
		if(res!=nullptr || std::find(varNames.begin(), varNames.end(),idlist->ID()->getText())!=varNames.end()){

			ErrorCheckingTask::tasks.push_back([lineNum,charPos](){				
				printErrorAndExit(lineNum,charPos, IRERROR_SYMBOL_ALREADY_EXISTS);	
			});
		}
		varNames.push_back(idlist->ID()->getText());
		
		idlist= idlist->id_list();
	}
	
	//check if this var exists in this scope
	int lineNum = idlist->ID()->getSymbol()->getLine();
	int charPos =  idlist->ID()->getSymbol()->getCharPositionInLine();
	std::string scopeName;
	auto res = back->getSymbol(idlist->ID()->getText(), scopeName,false);
	if(res!=nullptr || std::find(varNames.begin(), varNames.end(),idlist->ID()->getText())!=varNames.end()){

		ErrorCheckingTask::tasks.push_back([lineNum,charPos](){				
			printErrorAndExit(lineNum,charPos, IRERROR_SYMBOL_ALREADY_EXISTS);	
		});
	}
	varNames.push_back(idlist->ID()->getText());
	
	storageclass= STORAGE_VAR;
	if(ctx->storage_class()->STATIC()){
		//local var
		storageclass = STORAGE_STATIC;
	}
	else if(back->_programName.size()){//this is the main scope, everything must be static
		int lineNum =  ctx->storage_class()->VAR()->getSymbol()->getLine();
		int charPos =  ctx->storage_class()->VAR()->getSymbol()->getCharPositionInLine();
		ErrorCheckingTask::tasks.push_back([lineNum,charPos](){			
			printErrorAndExit(lineNum,charPos, IRERROR_NONSTATICVAR_NOT_ALLOWED_MAIN);		
		});
	
	}

	std::vector<SymbolVariable *> *vars = new std::vector<SymbolVariable *>();

	
	if(ctx->type()->INTLIT()){
		// error handling integer literal: this is an array NOT allowed according to 3.3 of spec		
		int lineNum =  ctx->type()->ARRAY()->getSymbol()->getLine();
		int charPos =  ctx->type()->ARRAY()->getSymbol()->getCharPositionInLine();
		ErrorCheckingTask::tasks.push_back([lineNum,charPos](){			
			printErrorAndExit(lineNum,charPos, IRERROR_NO_ARRAY_ALLOWED_VAR);		
		});
		
	}		
	else if(ctx->type()->type_id()){
		//type is int
		deriveFromType=TYPE_INT;
	}
	else if(ctx->type()->ID()){
		//another type
		// look this up in current symbol table
		
		int lineNum =  ctx->type()->ID()->getSymbol()->getLine();
		int charPos =  ctx->type()->ID()->getSymbol()->getCharPositionInLine();
		deriveFromSymbolName = ctx->type()->ID()->getText();
		ErrorCheckingTask::tasks.push_back([deriveFromSymbolName,lineNum,charPos,back,vars](){
			std::string scopeName;
			auto res = back->getSymbol(deriveFromSymbolName, scopeName);
			if(res==nullptr){
				printErrorAndExit(lineNum,charPos, IRERROR_NO_SUCH_TYPE);				
			}
			else if(res->getType()!=TYPE_TYPEDEF){
				printErrorAndExit(lineNum,charPos, IRERROR_NOT_ASSIGNABLE_TYPE);				
			}
			else{
				for(auto var : *vars){
					var->_deriveFromSymbolName=deriveFromSymbolName;//+scopeName;				
				}
			}
		});
		
		deriveFromType=TYPE_TYPEDEF;
		deriveFromSymbolName = ctx->type()->ID()->getText();		
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
		deriveFromType, 
		deriveFromSymbolName /*used if deriveFromType is TYPE_TYPEDEF*/, 
		storageclass, 
		hasValue ,
		defaultValue/*gets assigned to zero if StorageClass  static*/);

		vars->push_back(sym);
	}
  	
  	
  }


  virtual void enterFunct(TigerParser::FunctContext * ctx) override {
  	//add function and scope associated with it
  	  	
	  	auto name= ctx->ID()->getText();	  	
	  	//create symbol for function	
	  	auto retType = TYPE_VOID;
	  	std::string aliasName = "";
		Scope* back = Scope::scopeStack.back();
	  	SymbolFunc * sym = new SymbolFunc(name,retType,aliasName);
	  	if(ctx->ret_type() && ctx->ret_type()->type()){
			auto type = ctx->ret_type()->type();
			if(type->INTLIT()){
					//integer literal: this is an array NOT ALLOWED
										
					auto lineNum = type->ARRAY()->getSymbol()->getLine();
					auto charPos = type->ARRAY()->getSymbol()->getCharPositionInLine();
					ErrorCheckingTask::tasks.push_back([lineNum,charPos](){
						
						printErrorAndExit(lineNum,charPos, IRERROR_NO_ARRAY_ALLOWED_VAR);
					});
					
			}		
			else if(type->type_id()){
				//type is int
				retType=TYPE_INT;
			}
			else if(type->ID()){
				//another type
				//look this up in current symbol table move to semantic analysis
				
				int lineNum = type->ID()->getSymbol()->getLine();
				int charPos =  type->ID()->getSymbol()->getCharPositionInLine();
				aliasName = type->ID()->getText();
				ErrorCheckingTask::tasks.push_back([aliasName,lineNum,charPos,back,sym](){
					std::string scopeName;
					auto res = back->getSymbol(aliasName, scopeName);
					if(res==nullptr){
						printErrorAndExit(lineNum,charPos, IRERROR_NO_SUCH_TYPE);				
					}
					else if(res->getType()!=TYPE_TYPEDEF){
						printErrorAndExit(lineNum,charPos, IRERROR_NOT_ASSIGNABLE_TYPE);				
					}
					else{
						sym->_returnSymbol=aliasName;//+scopeName;	
					}
				});
				retType=TYPE_TYPEDEF;
				
			}
		}
		sym->_returnType=retType;
		sym->_returnSymbol=aliasName;
	  	sym->setAssociatedScope(Scope::create(Scope::scopeStack.back()));
	  	
	  	SymbolFunc::lastFunction = sym;
	  	
  		if(ctx->param_list()){
			auto parList = ctx->param_list()->param_list_tail();
			auto par = ctx->param_list()->param();
				
			//now add this symbol
			while(par){
								
				bool hasValue = false;
				//add par to symbol table
				auto varName = par->ID()->getText();
				auto name = varName;
				auto storageclass=STORAGE_VAR;
				auto type = par->type();
				auto deriveFromType = TYPE_INT;
				std::string deriveFromSymbolName = "";
				
				SymbolVariable *var = new SymbolVariable(
				name, 
				deriveFromType, 
				deriveFromSymbolName , 
				storageclass, 
				hasValue ,
				0);
				if(type->INTLIT()){
					//move to semantic analysis
					//integer literal: this is an array NOT ALLOWED					
										
					auto lineNum = type->ARRAY()->getSymbol()->getLine();
					auto charPos = type->ARRAY()->getSymbol()->getCharPositionInLine();
					ErrorCheckingTask::tasks.push_back([lineNum,charPos](){
						
						printErrorAndExit(lineNum,charPos, IRERROR_NO_ARRAY_ALLOWED_VAR);
					});
				}		
				else if(type->type_id()){
					//type is int
					deriveFromType=TYPE_INT;
				}
				else if(type->ID()){
					// move to semantic analysis
					int lineNum = type->ID()->getSymbol()->getLine();
					int charPos =  type->ID()->getSymbol()->getCharPositionInLine();
					deriveFromSymbolName = type->ID()->getText();
					ErrorCheckingTask::tasks.push_back([deriveFromSymbolName,lineNum,charPos,back,var](){
						std::string scopeName;
						auto res = back->getSymbol(deriveFromSymbolName, scopeName);
						if(res==nullptr){
							printErrorAndExit(lineNum,charPos, IRERROR_NO_SUCH_TYPE);				
						}
						else if(res->getType()!=TYPE_TYPEDEF){
							printErrorAndExit(lineNum,charPos, IRERROR_NOT_ASSIGNABLE_TYPE);				
						}
						else{
							//sym->_returnSymbol=aliasName+scopeName;	
							var->_deriveFromSymbolName=deriveFromSymbolName;//+scopeName;
						}
					});
					var->_deriveFromSymbolName=deriveFromSymbolName;
								
					//another type
					deriveFromType=TYPE_TYPEDEF;
					
									
				}	
				var->_deriveFromType=deriveFromType;
				var->_deriveFromSymbolName = deriveFromSymbolName;
				var->_storageclass= storageclass;
				var->_hasValue= hasValue;
				
				sym->addParam(var);		
				par=parList->param();
				parList=parList->param_list_tail();
				if(!parList){
					break;
				}
			}
		
		}
		
  
  }
  virtual void exitFunct(TigerParser::FunctContext * ctx) override { 
  	//pop scope
  	Scope::scopeStack.pop_back();
	SymbolFunc::lastFunction = NULL;
  }

/*
  virtual void enterRet_type(TigerParser::Ret_typeContext * ctx) override { 
  	//add return type to last fn
  }

  virtual void enterParam(TigerParser::ParamContext * ctx) override {  
  	//add param to last function
  	//add param to scope
   }
  */
  int countStats(TigerParser::Stat_seqContext* ctx){
  	int count = 0;
  	TigerParser::StatContext* st; 
  	st = ctx->stat();
  	if(!st){
  		return 0;
  	}
    	ctx = ctx->stat_seq();
    	//add st
    	count++;
  	while(ctx){
  	st = ctx->stat();
  	//add st
    	count++;
  	
  	//get next
  	ctx = ctx->stat_seq();
  	}
  	
  	return count;
  
  }
  
  void popLastStatAndAddToCurrentScope(){  
  
  		if(Stat::statStack.size()==0){
  			logger("WARNING EMPTY STATSTACK");
  		
  		}
  
  		logger("pop last stat and add to ");
  		logger(Scope::scopeStack.back()->getName());
  		logger("stat name:" + Stat::statStack.back()->getName());
  		Scope::scopeStack.back()->addStat(Stat::statStack.back());
  		Stat::statStack.pop_back();
  }
  
  virtual void exitStat_seq_func(TigerParser::Stat_seq_funcContext * ctx) override { 
  
  	//count number of stats and pop that many from stats, then add them to scope
  	auto cnt = countStats(ctx->stat_seq());
  	logger("exit func");
  	
  	logger("fn stat count" + std::to_string(cnt));
  	for(int i=0; i< cnt; i++){
  	 	logger("-------");
  		popLastStatAndAddToCurrentScope();
  	}
  }

  virtual void exitAssignment_stat(TigerParser::Assignment_statContext * ctx) override {
  	//create stat and AUTO push to stats
  	auto bk =ASTNode::astStack.back();
  	StatAssignment *st = new StatAssignment(bk);
  	
  	//make sure rval is not an array
	int lineNum = ctx->ASSIGN()->getSymbol()->getLine();
	int charPos =  ctx->ASSIGN()->getSymbol()->getCharPositionInLine();
	
	
	
  	ErrorCheckingTask::tasks.push_back([lineNum,charPos,bk](){
	bool isArrayRHS=false;
  	bool hasInvalidIndex= false;
  	if(!bk->isIntegerChain(hasInvalidIndex)){
		/*ErrorCheckingTask::tasks.push_back([lineNum,charPos](){
		
			printErrorAndExit(lineNum,charPos, IRERROR_ARRAY_RVAL);
		});*/
		isArrayRHS=true;
		
  	}
  	if(hasInvalidIndex){
		
			printErrorAndExit(lineNum,charPos, IRERROR_INDEX_ON_NON_ARRAY);
  	}
  	});
  	
  	
  	//assign stat rval = last astnode and pop that node
  	ASTNode::astStack.pop_back();
  	
  	
  	
  	//set lvalues
  	ASTNode* index= NULL;
  	//TODO lvalue indices
  	auto tail = ctx->l_tail();	
  	if(ctx->lvalue()->lvalue_tail()){
		index=ASTNode::astStack.back();
		ASTNode::astStack.pop_back();
	}
  	st->_lvalues.push_back(std::make_pair(ctx->lvalue()->ID()->getSymbol()->getText(),index));
  	
  	{
  	//TODO
  	//check if array lhs matches rhs
  	
  	}
  	
  	
  	
  	while(tail && tail->lvalue()){
  		index= NULL;
  		if(tail->lvalue()->lvalue_tail()){
			index=ASTNode::astStack.back();
			ASTNode::astStack.pop_back();
		}
  		st->_lvalues.push_back(std::make_pair(tail->lvalue()->ID()->getSymbol()->getText(),index));  	
  		
  		{
  		//TODO
	  	//check if array lhs matches rhs
	  	
	  	}
  		
  			
  		tail = tail->l_tail();
  	}
  	
   }

  virtual void exitIf_stat(TigerParser::If_statContext * ctx) override {
  	
   	//pop num stats equal to number of stats in stat_seq_then: this is the THEN statements
   	auto cnt = countStats(ctx->if_stat_lhs()->stat_seq_then()->stat_seq());
  	logger("exit if");
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}
	   
   	//create stat and associate the last astnode to the condition, and last scope to the "then" condition
   	auto stat = new StatIfStmt(ASTNode::astStack.back(), Scope::scopeStack.back());
   	ASTNode::astStack.pop_back();   
  	Scope::scopeStack.pop_back();
  }

  virtual void exitIf_else_stat(TigerParser::If_else_statContext * ctx) override {
  	
  	auto elseScope = Scope::scopeStack.back();
  	//pop num stats equal to number of stats in stat_seq_else: this is the ELSE statements
  	auto cnt = countStats(ctx->if_stat_lhs()->stat_seq_then()->stat_seq());
  	logger("exit ifelse");
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}
  	Scope::scopeStack.pop_back();
  	
  	auto ifScope = Scope::scopeStack.back();
  	//pop num stats equal to number of stats in stat_seq_then: this is the THEN statements
  	cnt = countStats(ctx->stat_seq_else()->stat_seq());
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}
  	Scope::scopeStack.pop_back();
  	
  	//create stat with the if scope, else scope and the last ast node as the expression
  	auto ifelse = new StatIfElseStmt(ASTNode::astStack.back(), ifScope, elseScope);
  	ASTNode::astStack.pop_back();
  	
  }
  

	
  virtual void enterWhile_stat(TigerParser::While_statContext * ctx) override {  
  	StatBreak::loopCounter++;
  }

  virtual void exitWhile_stat(TigerParser::While_statContext * ctx) override {  
  	//pop num stats equal to number of stats in stat_seq_while: these are the statements
  	auto cnt = countStats(ctx->stat_seq_while()->stat_seq());
  	logger("exit while");
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}
  	
  	//create stat and last ast node and the last scope
  	auto st = new StatWhileStmt(ASTNode::astStack.back(), Scope::scopeStack.back());
  	
  	
  	ASTNode::astStack.pop_back();   
  	Scope::scopeStack.pop_back();	
  	StatBreak::loopCounter--;
  }


  virtual void enterFor_stat(TigerParser::For_statContext * ctx) override { 
  	StatBreak::loopCounter++;
  }
  
  
  virtual void exitFor_stat(TigerParser::For_statContext * ctx) override { 
  	//pop ast: to
  	auto to = ASTNode::astStack.back();
  	ASTNode::astStack.pop_back();   
  	//pop ast: from
  	auto from = ASTNode::astStack.back();
  	ASTNode::astStack.pop_back();
  	//ID: name of var in for
  	auto varName= ctx->ID()->getText();
  	
  	
  	
  	//create stat and add the nodes, as well as the last scope
  	auto stFor= new StatFor(varName, from, to, Scope::scopeStack.back());
  	
  	
  	//check if this var exists
  	int lineNum = ctx->ID()->getSymbol()->getLine();
	int charPos =  ctx->ID()->getSymbol()->getCharPositionInLine();
	Scope* back = Scope::scopeStack.back();
	ErrorCheckingTask::tasks.push_back([lineNum,varName,charPos,back,stFor](){
		std::string scopeName;
		auto res = back->getSymbol(varName, scopeName);
		if(res==nullptr){
			printErrorAndExit(lineNum,charPos, IRERROR_NO_SUCH_VARIABLE);				
		}
		else if(res->getType()!=TYPE_VARIABLE){
			printErrorAndExit(lineNum,charPos, IRERROR_NOT_ASSIGNABLE_VAR);				
		}
		else{
			stFor->_assignVar=varName;//+scopeName;
		}
	});
  	
  	//pop count of stat_seq_for  	
  	auto cnt = countStats(ctx->stat_seq_for()->stat_seq());
  	logger("exit for");
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}  	
  	
  	Scope::scopeStack.pop_back();
  	StatBreak::loopCounter--;
  
  }

  virtual void exitFncall_stat(TigerParser::Fncall_statContext * ctx) override { 
  	//ID function name
  	//create stat and add the above  
  	auto fnCall = new StatFnCall(ctx->ID()->getText());  	
  	//pop ast count equal to expr_list-> function params
  	int cnt=0;
  	if(ctx->expr_list() && ctx->expr_list()->expr()){
  		cnt++;
  		auto tail = ctx->expr_list()->expr_list_tail();
  		while(tail && tail->expr()){
  			cnt++;
  			tail = tail->expr_list_tail();
  		}
  	}
  	
  	for(int i=0;i<cnt;i++){
  		fnCall->_fnCallParams.push_back(ASTNode::astStack.back());
  		ASTNode::astStack.pop_back();
  	}  	
  	
  	//opt_prefix Lval assignment  	
  	if(ctx->opt_prefix() && ctx->opt_prefix()->lvalue()){
  		fnCall->_lvalue = ctx->opt_prefix()->lvalue()->ID()->getText();
  		
  		if(ctx->opt_prefix()->lvalue()->lvalue_tail()){
  			fnCall->_lvalueIndex=ASTNode::astStack.back();
  			ASTNode::astStack.pop_back();
  		}
  	}
  	
  	
  }

  virtual void exitBreak_stat(TigerParser::Break_statContext * ctx) override { 
  	//create stat
  	auto br = new StatBreak();
  	
  	if (StatBreak::loopCounter==0){  
  	
		int lineNum = ctx->BREAK()->getSymbol()->getLine();
		int charPos =  ctx->BREAK()->getSymbol()->getCharPositionInLine();
			
		ErrorCheckingTask::tasks.push_back([lineNum,charPos](){				
			printErrorAndExit(lineNum,charPos, IRERROR_ILLEGAL_BREAK_STATEMENT);	
		});
  	}
  }

  virtual void exitReturn_stat(TigerParser::Return_statContext * ctx) override { 
  	ASTNode* returnVal = nullptr;
  	
  	//if opt_return-> take last astnode
  	if(ctx->opt_return() && ctx->opt_return()->expr()){
  		returnVal=ASTNode::astStack.back();
  		ASTNode::astStack.pop_back();
  	}
  	auto fn = SymbolFunc::lastFunction;
  	
	int lineNum = ctx->RETURN()->getSymbol()->getLine();
	int charPos =  ctx->RETURN()->getSymbol()->getCharPositionInLine();
	
  	if(fn->_returnType==TYPE_VOID && returnVal!=nullptr){
  		ErrorCheckingTask::tasks.push_back([lineNum,charPos](){				
			printErrorAndExit(lineNum,charPos, IRERROR_PROCEDURE_NON_NULL_RETURN);	
		});
  	}
  	else if(fn->_returnType!=TYPE_VOID && returnVal==nullptr){
  		ErrorCheckingTask::tasks.push_back([lineNum,charPos](){				
			printErrorAndExit(lineNum,charPos, IRERROR_FUNCTION_NO_RETURN_VAL);	
		});
  	}
  	else if(fn->_returnType!=TYPE_VOID){
  	//TODO deep analysis of return type
  	
  	}
  	
  
  	//create stat with above
  	auto stReturn = new StatReturn(returnVal);
  }

  virtual void enterSub_scope_stat(TigerParser::Sub_scope_statContext * ctx) override { 
  	//create scope
  	Scope::create(Scope::scopeStack.back());
  }
  virtual void exitSub_scope_stat(TigerParser::Sub_scope_statContext * ctx) override { 
	//remove stats
  	auto cnt = countStats(ctx->stat_seq());
  	logger("exit subscope");
  	for(int i=0; i< cnt; i++){
  		logger("added stat to last scope");
  		popLastStatAndAddToCurrentScope();
  	}  	
  	//create stat and associate last scope with it
  	auto ss = new StatSubScope(Scope::scopeStack.back());
  	//exit scope, pop
  	Scope::scopeStack.pop_back();
  }
  
  virtual void enterStat_seq_then(TigerParser::Stat_seq_thenContext * ctx) override { 
  	//create scope
  	Scope::create(Scope::scopeStack.back());
  }

  virtual void enterStat_seq_else(TigerParser::Stat_seq_elseContext * ctx) override { 
  	//create scope
  	Scope::create(Scope::scopeStack.rbegin()[1]);//second to last is the parent of the else
  }

  virtual void enterStat_seq_while(TigerParser::Stat_seq_whileContext * ctx) override {
  	//create scope
  	Scope::create(Scope::scopeStack.back());
   }

  virtual void enterStat_seq_for(TigerParser::Stat_seq_forContext * ctx) override { 
  	//create scope
  	Scope::create(Scope::scopeStack.back());
  }


// the following create ast nodes and associated temp vars
  virtual void exitLogical_op_expr(TigerParser::Logical_op_exprContext * ctx) override { 
  	TigerParser::Logical_op_expr_extContext * logicalExt=ctx->logical_op_expr_ext();  

  
  	while(logicalExt && logicalExt->compare_op_expr() ){//then we have power operators
   		 logger("creating logical op");
   		 auto nd = new ASTNode();
	 	int lineNum;
		int charPos;
   		 if(logicalExt->AND()){
   		 	nd->_op = OPERATOR_AND;   
   		 	lineNum = logicalExt->AND()->getSymbol()->getLine();
   		 	charPos =  logicalExt->AND()->getSymbol()->getCharPositionInLine();	
  		}
  		else{
   		 	nd->_op = OPERATOR_OR;  
   		 	lineNum = logicalExt->OR()->getSymbol()->getLine();
   		 	charPos =  logicalExt->OR()->getSymbol()->getCharPositionInLine();
  			
  		}
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 nd->_left = v2;
   		 nd->_right = v1;   	
   		 
   		
		ErrorCheckingTask::tasks.push_back([lineNum,charPos, v1, v2](){
	   		bool hasInvalidIndex= false;
			bool isArrayRHS=false;

		  	if(!(v1->isIntegerChain(hasInvalidIndex) && v2->isIntegerChain(hasInvalidIndex))){

				
					printErrorAndExit(lineNum,charPos, IRERROR_ARRAY_OPERATOR);
				isArrayRHS=true;
				
		  	}

		  	if(hasInvalidIndex){
				
					printErrorAndExit(lineNum,charPos, IRERROR_INDEX_ON_NON_ARRAY);
		  	}
   		 
		}); 
   		 		 		
   		 logicalExt= logicalExt->logical_op_expr_ext();
   		 ASTNode::astStack.push_back(nd); 
   	}  	
  	
  }

  virtual void exitCompare_op_expr(TigerParser::Compare_op_exprContext * ctx) override { 
  	TigerParser::Compare_op_expr_extContext * compareExt=ctx->compare_op_expr_ext();  

  	//EQUAL | NEQUAL | LESS | GREAT | LESSEQ | GREATEQ
  
  	int count = 0;
  
  	while(compareExt && compareExt->add_op_expr() ){//then we have power operators
   		 logger("creating compare op");
   		 auto nd = new ASTNode();
   		 
   		 
	 	int lineNum;
		int charPos;
   		 
   		 if(compareExt->EQUAL()){
   		 	nd->_op = OPERATOR_EQ;   
   		 	lineNum = compareExt->EQUAL()->getSymbol()->getLine();
   		 	charPos =  compareExt->EQUAL()->getSymbol()->getCharPositionInLine();	
  		}
  		else if(compareExt->NEQUAL()){
   		 	nd->_op = OPERATOR_NEQ; 
   		 	lineNum = compareExt->NEQUAL()->getSymbol()->getLine();
   		 	charPos =  compareExt->NEQUAL()->getSymbol()->getCharPositionInLine();  	
  		}
  		else if(compareExt->LESS()){
   		 	nd->_op = OPERATOR_LT;    
   		 	lineNum = compareExt->LESS()->getSymbol()->getLine();
   		 	charPos =  compareExt->LESS()->getSymbol()->getCharPositionInLine(); 	
  		}
  		else if(compareExt->GREAT()){
  			nd->_op = OPERATOR_GT;     
   		 	lineNum = compareExt->GREAT()->getSymbol()->getLine();
   		 	charPos =  compareExt->GREAT()->getSymbol()->getCharPositionInLine(); 	
  		}
  		else if(compareExt->LESSEQ()){
  			nd->_op = OPERATOR_LTE;  	
   		 	lineNum = compareExt->LESSEQ()->getSymbol()->getLine();
   		 	charPos =  compareExt->LESSEQ()->getSymbol()->getCharPositionInLine(); 	
  		}
  		else if(compareExt->GREATEQ()){
  			nd->_op = OPERATOR_GTE;  
   		 	lineNum = compareExt->GREATEQ()->getSymbol()->getLine();
   		 	charPos =  compareExt->GREATEQ()->getSymbol()->getCharPositionInLine();   		
  		}
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 nd->_left = v2;
   		 nd->_right = v1;   		 
   		 		 		
   		 compareExt= compareExt->compare_op_expr_ext();
   		 count++;
   		 if(count >=2){
			ErrorCheckingTask::tasks.push_back([lineNum,charPos](){
				printErrorAndExit(lineNum,charPos, IRERROR_COMPARATORS_NON_ASSOCIATIVE);
			});
   		 }
   		 
   		 
		ErrorCheckingTask::tasks.push_back([lineNum,charPos, v1, v2](){
	   		bool hasInvalidIndex= false;
			bool isArrayRHS=false;

		  	if(!(v1->isIntegerChain(hasInvalidIndex) && v2->isIntegerChain(hasInvalidIndex))){

				
					printErrorAndExit(lineNum,charPos, IRERROR_ARRAY_OPERATOR);
				isArrayRHS=true;
				
		  	}

		  	if(hasInvalidIndex){
				
					printErrorAndExit(lineNum,charPos, IRERROR_INDEX_ON_NON_ARRAY);
		  	}
   		 
		});
	  	
	  	
	  	
   		 ASTNode::astStack.push_back(nd); 		
   	}
  }

  virtual void exitAdd_op_expr(TigerParser::Add_op_exprContext * ctx) override { 
  	TigerParser::Add_op_expr_extContext * addExt=ctx->add_op_expr_ext();  

  	
   		
  
  	while(addExt && addExt->mult_op_expr() ){//then we have power operators

   		int lineNum, charPos;
   		 logger("creating add/sub op");
   		 auto nd = new ASTNode();
   		 if(addExt->PLUS()){
   		 	nd->_op = OPERATOR_PLUS; 
			lineNum = addExt->PLUS()->getSymbol()->getLine();
			charPos =  addExt->PLUS()->getSymbol()->getCharPositionInLine();  	
  		}
  		else{
  			nd->_op = OPERATOR_MINUS; 
			lineNum = addExt->MINUS()->getSymbol()->getLine();
			charPos =  addExt->MINUS()->getSymbol()->getCharPositionInLine();
  		}
   		 
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 nd->_left = v2;
   		 nd->_right = v1;   		 
   		 		 		
   		 	
		ErrorCheckingTask::tasks.push_back([lineNum,charPos, v1, v2](){
	   		bool hasInvalidIndex= false;
			bool isArrayRHS=false;

		  	if(!(v1->isIntegerChain(hasInvalidIndex) && v2->isIntegerChain(hasInvalidIndex))){

				
					printErrorAndExit(lineNum,charPos, IRERROR_ARRAY_OPERATOR);
				isArrayRHS=true;
				
		  	}

		  	if(hasInvalidIndex){
				
					printErrorAndExit(lineNum,charPos, IRERROR_INDEX_ON_NON_ARRAY);
		  	}
   		 
		});
   		 		 		
   		 addExt= addExt->add_op_expr_ext();
   		 ASTNode::astStack.push_back(nd); 
   	}
  
  
  }

  virtual void exitMult_op_expr(TigerParser::Mult_op_exprContext * ctx) override { 
  	TigerParser::Mult_op_expr_extContext * mulExt=ctx->mult_op_expr_ext(); 
  	auto op = OPERATOR_MULT;
  	
  
  	while(mulExt && mulExt->pow_op_expr() ){//then we have power operators
   		 logger("creating mult op");
   		 auto nd = new ASTNode(); 
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();   		 
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 
   		 
   		 //assert v1 and v2 are not arrays

   		int lineNum, charPos;
   		if(mulExt->MULT()){
		lineNum = mulExt->MULT()->getSymbol()->getLine();
		charPos =  mulExt->MULT()->getSymbol()->getCharPositionInLine();
   		op = OPERATOR_MULT;
   		}
   		else{
		lineNum = mulExt->DIV()->getSymbol()->getLine();
		charPos =  mulExt->DIV()->getSymbol()->getCharPositionInLine();
   		op = OPERATOR_DIV;
   		
   		}
   		 nd->_op = op;
		
		

		

	  	ErrorCheckingTask::tasks.push_back([lineNum,charPos, v1, v2](){
	   		bool hasInvalidIndex= false;
			bool isArrayRHS=false;

		  	if(!(v1->isIntegerChain(hasInvalidIndex) && v2->isIntegerChain(hasInvalidIndex))){

				
					printErrorAndExit(lineNum,charPos, IRERROR_ARRAY_OPERATOR);
				isArrayRHS=true;
				
		  	}

		  	if(hasInvalidIndex){
				
					printErrorAndExit(lineNum,charPos, IRERROR_INDEX_ON_NON_ARRAY);
		  	}
   		 
		});
   		 
   		 ASTNode::astStack.push_back(nd); 
   		 
   		 nd->_left = v2;
   		 nd->_right = v1;
   		 
   		 		 		
   		 mulExt= mulExt->mult_op_expr_ext();
   	}
  	
  	
  	
  	
  	
  }

  virtual void exitPow_op_expr(TigerParser::Pow_op_exprContext * ctx) override { 
  	TigerParser::Pow_op_expr_extContext * powExt=ctx->pow_op_expr_ext();
  	
  
  	while(powExt && powExt->expr_no_op() ){//then we have power operators
   		 logger("creating pow op");
   		 auto nd = new ASTNode();
   		 nd->_op = OPERATOR_POW;
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();   		 
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 
   		 
   		 //assert v1 and v2 are not arrays
		int lineNum = powExt->POW()->getSymbol()->getLine();
		int charPos =  powExt->POW()->getSymbol()->getCharPositionInLine();
		
		
		ErrorCheckingTask::tasks.push_back([lineNum,charPos, v1, v2](){
	   		bool hasInvalidIndex= false;
			bool isArrayRHS=false;

		  	if(!(v1->isIntegerChain(hasInvalidIndex) && v2->isIntegerChain(hasInvalidIndex))){

				
					printErrorAndExit(lineNum,charPos, IRERROR_ARRAY_OPERATOR);
				isArrayRHS=true;
				
		  	}

		  	if(hasInvalidIndex){
				
					printErrorAndExit(lineNum,charPos, IRERROR_INDEX_ON_NON_ARRAY);
		  	}
   		 
		});
   		 
   		 nd->_left = v2;
   		 nd->_right = v1;
   		 
   		 		 		
   		 powExt= powExt->pow_op_expr_ext();
   		 ASTNode::astStack.push_back(nd);  
   	}
  
  }

  virtual void exitExpr_no_op(TigerParser::Expr_no_opContext * ctx) override { 
  	//handle lvalue here
  	
   	if(ctx->constant()){
   		logger("creating const");
   		//create temp with assigned value
   		auto nd = new ASTNode();
   		auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,true,std::stoi(ctx->constant()->INTLIT()->getText()));
   		nd->_var= v->getName();
   		std::string scopeName;
		Scope* back = Scope::scopeStack.back();
		auto res = back->getSymbol(nd->_var, scopeName);
		nd->_var=nd->_var;//+scopeName;
   		nd->_isLeaf = true;
   		ASTNode::astStack.push_back(nd);
   	

   	}
  	
  }
  
  
  void exitLvalue(TigerParser::LvalueContext * ctx) override { 
   	logger("creating lvalue");
  	auto nd = new ASTNode();
	//use existing var
	nd->_var = ctx->ID()->getText();
	
	//check if this var exists
	int lineNum = ctx->ID()->getSymbol()->getLine();
	int charPos =  ctx->ID()->getSymbol()->getCharPositionInLine();
	Scope* back = Scope::scopeStack.back();
	ErrorCheckingTask::tasks.push_back([lineNum,charPos,nd,back](){
		std::string scopeName;
		auto res = back->getSymbol(nd->_var, scopeName);
		if(res==nullptr){
			printErrorAndExit(lineNum,charPos, IRERROR_NO_SUCH_VARIABLE);				
		}
		else if(res->getType()!=TYPE_VARIABLE){
			printErrorAndExit(lineNum,charPos, IRERROR_NOT_ASSIGNABLE_VAR);				
		}
		else{
			nd->_var=nd->_var;//+scopeName;
		}
	});
	
	
	if(ctx->lvalue_tail() && ctx->lvalue_tail()->expr()){  		
		nd->_hasIndex= true;		
		nd->_index = ASTNode::astStack.back();
		nd->_isLeaf = true;
		ASTNode::astStack.pop_back();
	}

	ASTNode::astStack.push_back(nd);
  }


};

#endif
