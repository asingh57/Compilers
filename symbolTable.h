#include "stat.h"

#include <map>
#include <string>
#include <variant>
#include <vector>
#include <cstring>



class SymbolTableGenerator : public TigerBaseListener{
public:
	Scope* globalScope;
	SymbolTableGenerator(){
	}
	

void printSymbolTable(){
	logger("printing symbol table");
		std::cout << Scope::scopeStack.size() << std::endl;
		std::cout << ASTNode::astStack.size() << std::endl;
		std::cout << Stat::statStack.size() << std::endl;
	globalScope->printSymbols();

}

  virtual void enterTiger_program(TigerParser::Tiger_programContext * /*ctx*/) override { 
  
	logger("global scope created");
	globalScope= Scope::create();
  }
  virtual void exitTiger_program(TigerParser::Tiger_programContext * /*ctx*/) override { 
  	Scope::scopeStack.pop_back();
  }



  virtual void enterType_declaration(TigerParser::Type_declarationContext * ctx) override {
  	//add type declarations to last scope
  }
  

  virtual void enterVar_declaration(TigerParser::Var_declarationContext * ctx) override { 
  	//add var declarations to last scope
  }


  virtual void enterFunct(TigerParser::FunctContext * ctx) override {
  	//add function and scope associated with it
  	  	
	  	auto name= ctx->ID()->getText();	  	
	  	//create symbol for function	
	  	auto retType = TYPE_VOID;
	  	std::string aliasName = "";
	  	if(ctx->ret_type() && ctx->ret_type()->type()){
			auto type = ctx->ret_type()->type();
			if(type->INTLIT()){
					//integer literal: this is an array NOT ALLOWED TODO move to semantic analysis
					/*					
					auto lineNum = type->ARRAY()->getSymbol()->getLine();
					auto colNum = type->ARRAY()->getSymbol()->getCharPositionInLine();
					printErrorAndExit(lineNum,colNum, IRERROR_NO_ARRAY_ALLOWED_VAR);
					*/
			}		
			else if(type->type_id()){
				//type is int
				retType=TYPE_INT;
			}
			else if(type->ID()){
				//another type
				//look this up in current symbol table move to semantic analysis
				/*
				auto rvalSymbol = currentScope->getSymbol();
				if(!rvalSymbol){
				
					auto lineNum = type->ID()->getSymbol()->getLine();
					auto colNum = type->ID()->getSymbol()->getCharPositionInLine();
					printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
				}*/
				retType=TYPE_TYPEDEF;
				aliasName = type->ID()->getText();
				
			}
		}
	  	SymbolFunc * sym = new SymbolFunc(name,retType,aliasName);
	  	sym->setAssociatedScope(Scope::create(Scope::scopeStack.back()));
	  	
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
					//TODO move to semantic analysis
					//integer literal: this is an array NOT ALLOWED
					/*
					auto lineNum = type->ARRAY()->getSymbol()->getLine();
					auto colNum = type->ARRAY()->getSymbol()->getCharPositionInLine();
					printErrorAndExit(lineNum,colNum, IRERROR_NO_ARRAY_ALLOWED_VAR);
					*/
				}		
				else if(type->type_id()){
					//type is int
					deriveFromType=TYPE_INT;
				}
				else if(type->ID()){
					//todo move to semantic analysis
					/*auto rvalSymbol = currentScope->getSymbol(type->ID()->getText());
					if(!rvalSymbol){
					
						auto lineNum = type->ID()->getSymbol()->getLine();
						auto colNum = type->ID()->getSymbol()->getCharPositionInLine();
						printErrorAndExit(lineNum,colNum, IRERROR_NO_SUCH_TYPE);
					}*/				
					//another type
					deriveFromType=TYPE_TYPEDEF;
					deriveFromSymbolName = type->ID()->getText();					
				}		
				//now add this symbol
				SymbolVariable *var = new SymbolVariable(
				name, 
				deriveFromType, 
				deriveFromSymbolName , 
				storageclass, 
				hasValue ,
				0);
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
  		Scope::scopeStack.back()->addStat(Stat::statStack.back());
  		Stat::statStack.pop_back();
  }
  
  virtual void exitStat_seq_func(TigerParser::Stat_seq_funcContext * ctx) override { 
  
  	//count number of stats and pop that many from stats, then add them to scope
  	auto cnt = countStats(ctx->stat_seq());
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}
  }

  virtual void exitAssignment_stat(TigerParser::Assignment_statContext * ctx) override {
  	//create stat and AUTO push to stats
  	StatAssignment *st = new StatAssignment(ASTNode::astStack.back());
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
  	
  	while(tail && tail->lvalue()){
  		index= NULL;
  		if(tail->lvalue()->lvalue_tail()){
			index=ASTNode::astStack.back();
			ASTNode::astStack.pop_back();
		}
  		st->_lvalues.push_back(std::make_pair(tail->lvalue()->ID()->getSymbol()->getText(),index));  		
  		tail = tail->l_tail();
  	}
  	
   }

  virtual void exitIf_stat(TigerParser::If_statContext * ctx) override {
  	
   	//pop num stats equal to number of stats in stat_seq_then: this is the THEN statements
   	auto cnt = countStats(ctx->if_stat_lhs()->stat_seq_then()->stat_seq());
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

  virtual void exitWhile_stat(TigerParser::While_statContext * ctx) override {  	
  	//pop num stats equal to number of stats in stat_seq_while: these are the statements
  	auto cnt = countStats(ctx->stat_seq_while()->stat_seq());
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}
  	
  	//create stat and last ast node and the last scope
  	StatWhileStmt(ASTNode::astStack.back(), Scope::scopeStack.back());
  	
  	
  	ASTNode::astStack.pop_back();   
  	Scope::scopeStack.pop_back();
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
  	//pop count of stat_seq_for  	
  	auto cnt = countStats(ctx->stat_seq_for()->stat_seq());
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}  	
  	
  	//create stat and add the nodes, as well as the last scope
  	auto stFor= StatFor(varName, from, to, Scope::scopeStack.back());
  	
  	Scope::scopeStack.pop_back();
  
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
  }

  virtual void exitReturn_stat(TigerParser::Return_statContext * ctx) override { 
  	ASTNode* returnVal = NULL;
  	
  	//if opt_return-> take last astnode
  	if(ctx->opt_return() && ctx->opt_return()->expr()){
  		returnVal=ASTNode::astStack.back();
  		ASTNode::astStack.pop_back();
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
  	for(int i=0; i< cnt; i++){
  		popLastStatAndAddToCurrentScope();
  	}  	
  	//create stat and associate last scope with it
  	StatSubScope(Scope::scopeStack.back());
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
   		 ASTNode::astStack.push_back(nd); 
   		 if(logicalExt->AND()){
   		 	nd->_op = OPERATOR_AND;   	
  		}
  		else{
   		 	nd->_op = OPERATOR_OR;  
  			
  		}
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 nd->_left = v2;
   		 nd->_right = v1;   		 
   		 		 		
   		 logicalExt= logicalExt->logical_op_expr_ext();
   	}  	
  	
  }

  virtual void exitCompare_op_expr(TigerParser::Compare_op_exprContext * ctx) override { 
  	TigerParser::Compare_op_expr_extContext * compareExt=ctx->compare_op_expr_ext();  

  	//EQUAL | NEQUAL | LESS | GREAT | LESSEQ | GREATEQ
  
  	while(compareExt && compareExt->add_op_expr() ){//then we have power operators
   		 logger("creating compare op");
   		 auto nd = new ASTNode();
   		 ASTNode::astStack.push_back(nd); 
   		 if(compareExt->EQUAL()){
   		 	nd->_op = OPERATOR_EQ;   	
  		}
  		else if(compareExt->NEQUAL()){
   		 	nd->_op = OPERATOR_NEQ;   	
  		}
  		else if(compareExt->LESS()){
   		 	nd->_op = OPERATOR_LT;   	
  		}
  		else if(compareExt->GREAT()){
  			nd->_op = OPERATOR_GT; 
  		}
  		else if(compareExt->LESSEQ()){
  			nd->_op = OPERATOR_LTE;  		
  		}
  		else if(compareExt->GREATEQ()){
  			nd->_op = OPERATOR_GTE;    		
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
   	}
  }

  virtual void exitAdd_op_expr(TigerParser::Add_op_exprContext * ctx) override { 
  	TigerParser::Add_op_expr_extContext * addExt=ctx->add_op_expr_ext();  

  	
  
  	while(addExt && addExt->mult_op_expr() ){//then we have power operators
   		 logger("creating add/sub op");
   		 auto nd = new ASTNode();
   		 ASTNode::astStack.push_back(nd); 
   		 if(addExt->PLUS()){
   		 	nd->_op = OPERATOR_PLUS;   	
  		}
  		else{
  			nd->_op = OPERATOR_MINUS; 
  		}
   		 
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 nd->_left = v2;
   		 nd->_right = v1;   		 
   		 		 		
   		 addExt= addExt->add_op_expr_ext();
   	}
  
  
  }

  virtual void exitMult_op_expr(TigerParser::Mult_op_exprContext * ctx) override { 
  	TigerParser::Mult_op_expr_extContext * mulExt=ctx->mult_op_expr_ext();  
  	auto op = OPERATOR_MULT;
  	
  
  	while(mulExt && mulExt->pow_op_expr() ){//then we have power operators
   		 logger("creating mul/div op");
   		 auto nd = new ASTNode();
   		 ASTNode::astStack.push_back(nd); 
   		 if(mulExt->MULT()){
   		 	nd->_op = OPERATOR_MULT;   	
  		}
  		else{
  			nd->_op = OPERATOR_DIV; 
  		}
   		 
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
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
   		 ASTNode::astStack.push_back(nd);  
   		 auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,false,0);
   	  	 nd->_var= v->getName(); 
   		 auto v1 =  ASTNode::astStack.back();
   		 ASTNode::astStack.pop_back();
   		 auto v2 =  ASTNode::astStack.back();   
   		 ASTNode::astStack.pop_back();
   		 nd->_left = v2;
   		 nd->_right = v1;
   		 
   		 		 		
   		 powExt= powExt->pow_op_expr_ext();
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
   		nd->_isLeaf = true;
   		ASTNode::astStack.push_back(nd);
   	
   	}
  	
  }
  
  
  void exitLvalue(TigerParser::LvalueContext * ctx) override { 
   	logger("creating lvalue");
  	auto nd = new ASTNode();
	//use existing var
	nd->_var = ctx->ID()->getText();
	
	if(ctx->lvalue_tail() && ctx->lvalue_tail()->expr()){  		
		nd->_hasIndex= true;		
		nd->_index = ASTNode::astStack.back();
		nd->_isLeaf = true;
		ASTNode::astStack.pop_back();
	}
	ASTNode::astStack.push_back(nd);
  }


};
