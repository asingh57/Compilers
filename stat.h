#ifndef _STAT
#define _STAT
#include "symbol.h"


class Stat{
public:
	static std::vector<std::string> endList;//list of end labels for various condition
	static std::vector<Stat*> statStack;
protected:
	StatType _type;
	static int nameCounter;
	std::string _name;
	Stat(StatType type = STAT_NONE): _type(type),_name("_stat"+std::to_string(nameCounter++)){
		statStack.push_back(this);
		logger("created " + _name);
	}
public:
	std::string getName(){
		return _name;
	}
	
	virtual void printSymbols(){}
	
	virtual void printIR(std::ofstream &outFile){
	
	}
	
	
	static std::string formatIR(std::string a = "",std::string b = "",std::string c = "",std::string d = ""){
		return a + ", " +b+ ", " +c +", " + d;
	}
};




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
		
		logger("printing ast");
		}
};




class StatAssignment : Stat{
public:
	std::vector<std::pair<std::string, ASTNode*>> _lvalues;
	ASTNode* _assignedExpr;
	StatAssignment(ASTNode* assignedExpr):Stat(STAT_ASSIGN),_assignedExpr(assignedExpr),_lvalues(){
		
	}
	
	void printIR(std::ofstream &outFile) override{

		for(int i=_lvalues.size()-1; i>=0 ; i--){
			
			
			if(i==_lvalues.size()-1){
				//TODO resolve expression
				Scope::tabs(outFile);
				outFile << formatIR("assign", _lvalues[i].first, _assignedExpr->_var);
				outFile<<"\n";
			}
			else{
				Scope::tabs(outFile);
				outFile << formatIR("assign", _lvalues[i].first,_lvalues[i+1].first);
				outFile<<"\n";
			}
		}
	}
	
	void printSymbols() override{
		//don't print anything
		logger("printing assignment");
	}

};

class StatIfStmt : Stat{
public:
	ASTNode* _condition;
	Scope* _ifScope;
	StatIfStmt(ASTNode* condition, Scope* ifScope):Stat(STAT_IF), _condition(condition), _ifScope(ifScope){
	
	}
	
	void printIR(std::ofstream &outFile) override{
		Scope::tabs(outFile);
		//TODO output expr
		auto elseLabel = _ifScope->getName()+"if";
		outFile<< formatIR("brneq",_condition->_var,"_true",elseLabel);
		outFile<<"\n";
		_ifScope->generateIR(outFile);
		Scope::tabCounter--;
		Scope::tabs(outFile);
		outFile << elseLabel << ":";
		Scope::tabCounter++;
		outFile<<"\n";
	}
	
	void printSymbols() override{
	
		logger("printing if");
		//print subscope
		_ifScope->printSymbols();		
	}
};

class StatIfElseStmt : Stat{
public:
	ASTNode* _condition;
	Scope* _ifScope;
	Scope* _elseScope;
	StatIfElseStmt(ASTNode* condition, Scope* ifScope, Scope* elseScope):Stat(STAT_IFELSE), _condition(condition), _ifScope(ifScope),_elseScope(elseScope){
	
	}
	
	void printIR(std::ofstream &outFile) override{
		Scope::tabs(outFile);
		//TODO output expr
		auto elseLabel = _ifScope->getName()+"if";
		outFile<< formatIR("brneq",_condition->_var,"_true",elseLabel);
		outFile<<"\n";
		_ifScope->generateIR(outFile);
		Scope::tabCounter--;
		Scope::tabs(outFile);
		outFile << elseLabel << ":";
		Scope::tabCounter++;
		outFile<<"\n";
		_elseScope->generateIR(outFile);
	}
	
	
	
	
	void printSymbols() override{
		
		logger("printing ifelse");
		//print subscopes
		_ifScope->printSymbols();
		_elseScope->printSymbols();
	}
};


class StatWhileStmt : Stat{
public:
	ASTNode* _condition;
	Scope* _whileScope;
	StatWhileStmt(ASTNode* condition, Scope* whileScope):Stat(STAT_WHILE),_condition(condition), _whileScope(whileScope) {
	
	} 
	
	void printIR(std::ofstream &outFile) override{
		
		auto whileStart = _whileScope->getName() +"whileCondition";
		auto whileEnd = _whileScope->getName() +"whileEnd";
		
		
		Scope::tabCounter--;
		Scope::tabs(outFile);
		outFile << whileStart <<":\n";	
		//TODO put condition here and skip if condition not met
		Scope::tabs(outFile);
		outFile<< formatIR("brneq",_condition->_var,"_true",whileEnd) <<"\n";
		
		//push end
		endList.push_back(whileEnd);
		//output scope
		_whileScope->generateIR(outFile);
		//pop end		
		endList.pop_back();
		
		Scope::tabCounter++;
				
		Scope::tabs(outFile);
		outFile<< formatIR("goto",whileStart) <<"\n";
		
		Scope::tabCounter--;	
		Scope::tabs(outFile);	
		outFile << whileEnd <<":\n";
		Scope::tabCounter++;
		
		
		
	}
	
	
	void printSymbols() override{
		
		logger("printing while");
		_whileScope->printSymbols();
	}

};

class StatFor :Stat{
public:
	ASTNode* _from;	
	ASTNode* _to;
	std::string _assignVar;
	Scope* _forScope;
	StatFor(std::string assignVar, ASTNode* from, ASTNode* to, Scope* forScope):Stat(STAT_FOR),_from(from),_to(to),_assignVar(assignVar),_forScope(forScope){
	
	}
	
	
	void printSymbols() override{
		
		logger("printing for");
		_forScope->printSymbols();
	}
	
	void printIR(std::ofstream &outFile) override{
		
		auto forStart = _forScope->getName() +"forCondition";
		auto forEnd = _forScope->getName() +"forEnd";
		
		
		//TODO put precondition here
		Scope::tabs(outFile);
		outFile << formatIR("assign",_assignVar, _from->_var) << "\n";
		
		Scope::tabCounter--;
		Scope::tabs(outFile);
		outFile << forStart <<":\n";	
		Scope::tabCounter++;
		//TODO put condition here and skip if condition not met
		Scope::tabs(outFile);
		outFile<< formatIR("brneq",_to->_var,_assignVar,forEnd) <<"\n";
		
		//push to endlist
		endList.push_back(forEnd);
		//output scope
		_forScope->generateIR(outFile);
				
		//pop from endlist
		endList.pop_back();
		
		//post condition here, which is ++
		Scope::tabs(outFile);
		outFile << formatIR("add",_assignVar, "1", _assignVar) << "\n";
		
		//jump to start
		Scope::tabs(outFile);
		outFile<< formatIR("goto",forStart) <<"\n";
		
		Scope::tabCounter--;	
		Scope::tabs(outFile);	
		outFile << forEnd <<":\n";
		Scope::tabCounter++;
		
		
		
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
	
	
	void printIR(std::ofstream &outFile) override{
		
		
		Scope::tabs(outFile);
		if(_lvalue.size()>0){
			//TODO resolve _lvalueIndex
			outFile << "callr, " << _lvalue;
		}
		else{
			outFile << "call";			
		}
		outFile <<", " << _fnName;
		
		for (auto par = _fnCallParams.rbegin(); par != _fnCallParams.rend(); ++par)
		{
			outFile << ", " << (*par)->_var;
		
		}
		
		
		outFile<< "\n";
	}
	
	
	void printSymbols() override{
		
		logger("printing fn call");
	}

};

class StatBreak :Stat{
public:

	StatBreak():Stat(STAT_BREAK){
	
	}
	
	void printIR(std::ofstream &outFile) override{
		Scope::tabs(outFile);
		outFile<< formatIR("goto",Stat::endList.back() )<<"\n";
	}
	
	void printSymbols() override{
		
		logger("printing break");
	}
};

class StatReturn :Stat{
public:
	ASTNode* _retVal;
	StatReturn(ASTNode* retVal):Stat(STAT_RETURN),_retVal(retVal){
	
	}
	
	void printSymbols() override{
		
		logger("printing return");
	}
};

class StatSubScope :Stat{
public:
	Scope* _scope;
	StatSubScope(Scope* scope):Stat(STAT_SUBSCOPE),_scope(scope){
	
	}
	
	void printSymbols() override{
		
		logger("printing subscope");
		_scope->printSymbols();
	}
};



#endif
