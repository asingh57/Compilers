#include "TigerBaseListener.h"

#include <map>
#include <string>
#include <variant>
#include <vector>
#include <cstring>


class Stat;//statements type (ifelse, return, loop etc...)
class Symbol;//symbol type (function. typedef, var (user defined as well as generated), static)

class Scope{
private:
	std::map<std::string, Symbol*> _symbolsMap;//list of symbols in scope
	Scope* _parentScope;//parent scope
	std::string _name;//scope name (auto generated
	Stat* _associatedStat;//associated parent statement if applicable
	std::vector<Stat*> _stats; //sub-statements inside scope
	Scope(std::string name, Scope* parentScope=NULL, Stat* associatedStat=NULL) : _symbolsMap(), _parentScope(parentScope), _name(name), _stats(), _associatedStat(NULL){
		
	}
public:
	static int scopeCounter;//counter for creating new scopes
	static int tabCounter;//keeps count of scope tabs
	static void tabs(){//print tabs
		for(int i=0;i<tabCounter;i++){
			std::cout << "    ";
		}
	}
	//scope factory
	static Scope* create(Scope* parent=NULL){
		return new Scope("Scope " + std::to_string(scopeCounter++), parent);
	}
	
	
public:
	//get parent
	Scope* parent(){
		return _parentScope;
	}
	
	//add symbol to scope
	void addSymbol(Symbol* value){
		_symbolsMap.insert(std::make_pair(value->_name,value));
	}
	
	//get symbol by name
	Symbol* getSymbol(std::string name, bool checkParents=true){
		auto search= _symbolsMap.find(name);
		if(search!=_symbolsMap.end()){
			return search->second;
		}
		
		if(_parentScope && checkParents){
			return _parentScope->getSymbol(name,checkParents);
		}
		
		return nullptr;
	}
	
	//print all symbols
	void printSymbols(){
		tabs();
		std::cout<< _name <<":" <<std::endl;
		tabCounter++;
		for(auto const& [key, val] : _symbolsMap){
			val->print();
		}
		tabCounter--;
	}
	
};

class SymbolTableGenerator : public TigerBaseListener{
public:
	Scope* globalScope;
	std::vector<Scope*> scopes;
	std::vector<Stat>* stats;
	SymbolTableGenerator(): scopes(),stats(){
		globalScope= Scope::create();
		scopes.push_back(globalScope);
	}
	

  virtual void enterType_declaration(TigerParser::Type_declarationContext * ctx) override {
  	//add type declarations to last scope
  
  }
  

  virtual void enterVar_declaration(TigerParser::Var_declarationContext * ctx) override { 
  	//add var declarations to last scope
  }


  virtual void enterFunct(TigerParser::FunctContext * ctx) override { 
  	//add function and scope associated with it
  
  }
  virtual void exitFunct(TigerParser::FunctContext * /*ctx*/) override { 
  	//pop scope
  }

  virtual void enterRet_type(TigerParser::Ret_typeContext * /*ctx*/) override { 
  	//add return type to last scope
  }

  virtual void enterParam(TigerParser::ParamContext * /*ctx*/) override {  
  	//add param to last function
  	//add param to scope
   }
  
  virtual void exitStat_seq(TigerParser::Stat_seqContext * /*ctx*/) override { 
  	//count number of stats and pop that many from stats, then add them to scope
  }

  virtual void exitAssignment_stat(TigerParser::Assignment_statContext * /*ctx*/) override {
  	//create stat and push to stats
  	
  	//assign stat rval = last astnode and pop that node
   }

  virtual void exitIf_stat(TigerParser::If_statContext * /*ctx*/) override { 
  	//pop num stats equal to number of stats in stat_seq_then: this is the THEN statements
  	//pop astnode: this is the expr condition
  	//create stat and add the above two as well as the last scope (popped)
  }

  virtual void exitIf_else_stat(TigerParser::If_else_statContext * /*ctx*/) override { 
  	//pop num stats equal to number of stats in stat_seq_else: this is the ELSE statements
  	//pop num stats equal to number of stats in stat_seq_then: this is the THEN statements
  	//pop astnode: this is the expr
  	//create stat and add the above two as well as last 2 scopes (popped)
  }

  virtual void exitWhile_stat(TigerParser::While_statContext * /*ctx*/) override {  	
  	//pop num stats equal to number of stats in stat_seq_while: these are the statements
  	//pop last astnode, this is the expr
  	//create stat and add the above, as well as the last scope  (popped)	
  }


  virtual void exitFor_stat(TigerParser::For_statContext * /*ctx*/) override { 
  	//pop ast: to
  	//pop ast: from
  	//ID: name of var in for
  	//pop count of stat_seq_for  	
  	//create stat and add the above, as well as the last scope (popped)
  
  }

  virtual void exitFncall_stat(TigerParser::Fncall_statContext * /*ctx*/) override { 
  	//pop ast count equal to expr_list-> function params
  	//ID function name
  	//opt_prefix Lval assignment
  	//create stat and add the above  
  }

  virtual void exitBreak_stat(TigerParser::Break_statContext * /*ctx*/) override { 
  	//create stat
  }

  virtual void exitReturn_stat(TigerParser::Return_statContext * /*ctx*/) override { 
  	//if opt_return-> take last astnode
  	//create stat with above
  }

  virtual void enterSub_scope_stat(TigerParser::Sub_scope_statContext * /*ctx*/) override { 
  	//create scope
  }
  virtual void exitSub_scope_stat(TigerParser::Sub_scope_statContext * /*ctx*/) override { 
  	//exit scope, pop
  }
  
  virtual void enterStat_seq_then(TigerParser::Stat_seq_thenContext * /*ctx*/) override { 
  	//create scope
  }

  virtual void enterStat_seq_else(TigerParser::Stat_seq_elseContext * /*ctx*/) override { 
  	//create scope
  }

  virtual void enterStat_seq_while(TigerParser::Stat_seq_whileContext * /*ctx*/) override {
  	//create scope
   }

  virtual void enterStat_seq_for(TigerParser::Stat_seq_forContext * /*ctx*/) override { 
  	//create scope
  }


// the following create ast nodes
  virtual void exitLogical_op_expr(TigerParser::Logical_op_exprContext * /*ctx*/) override { }

  virtual void exitCompare_op_expr(TigerParser::Compare_op_exprContext * /*ctx*/) override { }

  virtual void exitAdd_op_expr(TigerParser::Add_op_exprContext * /*ctx*/) override { }

  virtual void exitMult_op_expr(TigerParser::Mult_op_exprContext * /*ctx*/) override { }

  virtual void exitPow_op_expr(TigerParser::Pow_op_exprContext * /*ctx*/) override { }

  virtual void exitExpr_no_op(TigerParser::Expr_no_opContext * /*ctx*/) override { 
  	//handle lvalue here
  	
  }

  virtual void exitConstant(TigerParser::ConstantContext * /*ctx*/) override { 
  
  }


}
