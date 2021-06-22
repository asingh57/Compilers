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
	OPERATOR_EQ
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
};

std::vector<ASTNode*> ASTNode::astStack={};

enum StatType{
	STAT_NONE,
	STAT_ASSIGN,
};

class Stat{
public:
	std::vector<Stat*> statStack;
protected:
	StatType _type;

	Stat(StatType type = STAT_NONE):statStack(), _type(type){
		statStack.push_back(this);
	}
public:
	Stat* create(){
		return new Stat();
	}
};

class StatAssignment : Stat{
public:
	StatAssignment():Stat(STAT_ASSIGN){
	
	}

};
