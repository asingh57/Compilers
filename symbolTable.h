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
		logger("global scope created");
		globalScope= Scope::create();
	}
	

void printSymbolTable(){
	logger("printing symbol table");
	globalScope->printSymbols();

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
  
  
  virtual void exitStat_seq_func(TigerParser::Stat_seq_funcContext * ctx) override { 
  	//count number of stats and pop that many from stats, then add them to scope
  	//auto cnt = countStats(ctx->stat_seq());
  	//TODO add to scope
  }

  virtual void exitAssignment_stat(TigerParser::Assignment_statContext * ctx) override {
  	//create stat and push to stats
  	//StatAssignment *st = new StatAssignment();
  	
  	
  	//assign stat rval = last astnode and pop that node
   }

  virtual void exitIf_stat(TigerParser::If_statContext * ctx) override { 
  	//pop num stats equal to number of stats in stat_seq_then: this is the THEN statements
  	//pop astnode: this is the expr condition
  	//create stat and add the above two as well as the last scope (popped)
  	//make sure parent of this scope is correct
  }

  virtual void exitIf_else_stat(TigerParser::If_else_statContext * ctx) override { 
  	//pop num stats equal to number of stats in stat_seq_else: this is the ELSE statements
  	//pop num stats equal to number of stats in stat_seq_then: this is the THEN statements
  	//pop astnode: this is the expr
  	//create stat and add the above two as well as last 2 scopes (popped)
  }

  virtual void exitWhile_stat(TigerParser::While_statContext * ctx) override {  	
  	//pop num stats equal to number of stats in stat_seq_while: these are the statements
  	//pop last astnode, this is the expr
  	//create stat and add the above, as well as the last scope  (popped)	
  }


  virtual void exitFor_stat(TigerParser::For_statContext * ctx) override { 
  	//pop ast: to
  	//pop ast: from
  	//ID: name of var in for
  	//pop count of stat_seq_for  	
  	//create stat and add the above, as well as the last scope (popped)
  
  }

  virtual void exitFncall_stat(TigerParser::Fncall_statContext * ctx) override { 
  	//pop ast count equal to expr_list-> function params
  	//ID function name
  	//opt_prefix Lval assignment
  	//create stat and add the above  
  }

  virtual void exitBreak_stat(TigerParser::Break_statContext * ctx) override { 
  	//create stat
  }

  virtual void exitReturn_stat(TigerParser::Return_statContext * ctx) override { 
  	//if opt_return-> take last astnode
  	//create stat with above
  }

  virtual void enterSub_scope_stat(TigerParser::Sub_scope_statContext * ctx) override { 
  	//create scope
  }
  virtual void exitSub_scope_stat(TigerParser::Sub_scope_statContext * ctx) override { 
  	//exit scope, pop
  }
  
  virtual void enterStat_seq_then(TigerParser::Stat_seq_thenContext * ctx) override { 
  	//create scope
  }

  virtual void enterStat_seq_else(TigerParser::Stat_seq_elseContext * ctx) override { 
  	//create scope
  }

  virtual void enterStat_seq_while(TigerParser::Stat_seq_whileContext * ctx) override {
  	//create scope
   }

  virtual void enterStat_seq_for(TigerParser::Stat_seq_forContext * ctx) override { 
  	//create scope
  }


// the following create ast nodes and associated temp vars
  virtual void exitLogical_op_expr(TigerParser::Logical_op_exprContext * ctx) override { 
  	
  }

  virtual void exitCompare_op_expr(TigerParser::Compare_op_exprContext * ctx) override { 
  
  }

  virtual void exitAdd_op_expr(TigerParser::Add_op_exprContext * ctx) override { 
  
  }

  virtual void exitMult_op_expr(TigerParser::Mult_op_exprContext * ctx) override { 
  
  }

  virtual void exitPow_op_expr(TigerParser::Pow_op_exprContext * ctx) override { 
  
  }

  virtual void exitExpr_no_op(TigerParser::Expr_no_opContext * ctx) override { 
  	//handle lvalue here
  	
   	if(ctx->constant()){
   		//create temp with assigned value
   		auto nd = new ASTNode();
   		auto v= new SymbolVariable(TYPE_INT,"",STORAGE_VAR,true,std::stoi(ctx->constant()->INTLIT()->getText()));
   		nd->_var= v->getName();
   		nd->_isLeaf = true;
   		ASTNode::astStack.push_back(nd);
   	
   	}
  	
  }
  
  
  void exitLvalue(TigerParser::LvalueContext * ctx) override { 
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
