#include "symbol.h"



enum Operator{
	OPERATOR_PLUS,
	OPERATOR_MINUS,
	OPERATOR_MULT,
	OPERATOR_DIV,
	OPERATOR_POW,
	OPERATOR_LT,	
	OPERATOR_GT,	
	OPERATOR_LTE,	
	OPERATOR_GTE,	
	OPERATOR_EQ,
	OPERATOR_NEQ,
	OPERATOR_AND,
	OPERATOR_OR
};

class ASTNode{
	public:
		static std::vector<ASTNode*> astStack;
		
		std::string _var; //(output) variable of ast node
		bool _hasIndex; 
		ASTNode* _index;//index of var determined by an expression
		bool _isLeaf; //is this a leaf node?
		//if not leaf node, following apply
		ASTNode* _left;//left child
		ASTNode* _right;// right child
		Operator _op; //operator between left and right child that output to this var
		ASTNode* _parent; //parent AST node
		
		ASTNode(ASTNode* parent=NULL): _parent(parent), _hasIndex(false), _left(NULL), _right(NULL), _isLeaf(false){
		
		}
		
		virtual void printSymbols(){
		
		}
};

std::vector<ASTNode*> ASTNode::astStack={};




class StatAssignment : Stat{
public:
	std::vector<std::pair<std::string, ASTNode*>> _lvalues;
	ASTNode* _assignedExpr;
	StatAssignment(ASTNode* assignedExpr):Stat(STAT_ASSIGN),_assignedExpr(assignedExpr),_lvalues(){
		
	}
	
	void printSymbols() override{
		
	}

};

class StatIfStmt : Stat{
public:
	ASTNode* _condition;
	Scope* _ifScope;
	StatIfStmt(ASTNode* condition, Scope* ifScope):Stat(STAT_IF), _condition(condition), _ifScope(ifScope){
	
	}
	
	void printSymbols() override{
		
	}
};

class StatIfElseStmt : Stat{
public:
	ASTNode* _condition;
	Scope* _ifScope;
	Scope* _elseScope;
	StatIfElseStmt(ASTNode* condition, Scope* ifScope, Scope* elseScope):Stat(STAT_IFELSE), _condition(condition), _ifScope(ifScope),_elseScope(elseScope){
	
	}
	
	void printSymbols() override{
		
	}
};


class StatWhileStmt : Stat{
public:
	ASTNode* _condition;
	Scope* _whileScope;
	StatWhileStmt(ASTNode* condition, Scope* whileScope):Stat(STAT_WHILE),_condition(condition), _whileScope(whileScope) {
	
	} 
	
	void printSymbols() override{
		
	}

};

class StatFor :Stat{
public:
	ASTNode* _from;	
	ASTNode* _to;
	std::string _assignVar;
	StatFor(std::string assignVar, ASTNode* from, ASTNode* to, Scope* _forScope):Stat(STAT_FOR),_from(from),_to(to),_assignVar(assignVar){
	
	}
};


class StatFnCall :Stat{
public:
	std::vector<ASTNode*> _fnCallParams;
	std::string _lvalue;
	ASTNode* _lvalueIndex;
	std::string _fnName;

	StatFnCall(std::string fnName):Stat(STAT_FNCALL), _fnCallParams(), _lvalue(""), _lvalueIndex(NULL), _fnName(fnName){
	
	}
	
	void printSymbols() override{
		
	}

};

class StatBreak :Stat{
public:

	StatBreak():Stat(STAT_BREAK){
	
	}
	
	void printSymbols() override{
		
	}
};

class StatReturn :Stat{
public:
	ASTNode* _retVal;
	StatReturn(ASTNode* retVal):Stat(STAT_RETURN),_retVal(retVal){
	
	}
	
	void printSymbols() override{
		
	}
};

class StatSubScope :Stat{
public:
	Scope* _scope;
	StatSubScope(Scope* scope):Stat(STAT_SUBSCOPE),_scope(scope){
	
	}
	
	void printSymbols() override{
		
	}
};

std::vector<Stat*> Stat::statStack = {};
