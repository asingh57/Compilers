#ifndef _STAT
#define _STAT
#include "symbol.h"
#include "astNode.h"

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
	
	virtual void mangle(){
	
	}
	
	static std::string formatIR(std::string a = "",std::string b = "",std::string c = "",std::string d = ""){
		return a + ", " +b+ ", " +c +", " + d;
	}
};



class StatAssignment : Stat{
public:
	std::vector<std::pair<std::string, ASTNode*>> _lvalues;
	ASTNode* _assignedExpr;
	StatAssignment(ASTNode* assignedExpr):Stat(STAT_ASSIGN),_assignedExpr(assignedExpr),_lvalues(){
		
	}
	
	void printIR(std::ofstream &outFile) override{

		//std::cout <<"printing assignment " << _name << " _lvalues.size() "<<_lvalues.size()<<std::endl; 

		if(_assignedExpr){
			//std::cout << "printing assign _assignedExpr "<<_assignedExpr->_var<<std::endl;
			_assignedExpr->printIR(outFile);
		}

		for(int i=_lvalues.size()-1; i>=0 ; i--){
			
			
				//TODO resolve second
			if(i==_lvalues.size()-1){
				//std::cout <<"----- " << _name <<std::endl; 
				Scope::tabs(outFile);
				outFile << formatIR("assign", _lvalues[i].first, _assignedExpr->_var);
				outFile<<"\n";
			}
			else{
				//std::cout <<"222" << _name <<std::endl; 
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
	
	
	void mangle() override{
		
		//std::cout << "mangle assignment stat " <<_name <<std::endl;	
	
		std::vector<std::pair<std::string, ASTNode*>> newlvalues;
		
		
		//std::cout << "mangle lvalues " <<_name <<std::endl;	
		
		for(auto pair : _lvalues){
		
			//std::cout << "mangle lval " <<_name << "pair first " << pair.first <<std::endl;	
			if(pair.second){
				pair.second->mangle();
			}
			
			
			
			//std::cout << "pair lvalu " <<_name <<std::endl;	
			newlvalues.push_back(std::make_pair( Scope::getMangledName(pair.first), pair.second ));
		}
		_lvalues.clear();
		
		for( auto p : newlvalues){
		
			//std::cout << "transfer new lvalues " <<_name <<std::endl;	
			_lvalues.push_back(p);
		}
		
		
		if(_assignedExpr){
		
			//std::cout << "assigned expr mangle  " <<_name <<std::endl;	
			_assignedExpr->mangle();		
		}
		
		
		//std::cout << "mangle done for  " <<_name <<std::endl;	
	}

};

class StatIfStmt : Stat{
public:
	ASTNode* _condition;
	Scope* _ifScope;
	StatIfStmt(ASTNode* condition, Scope* ifScope):Stat(STAT_IF), _condition(condition), _ifScope(ifScope){
	
	}
	
	void printIR(std::ofstream &outFile) override{
		_condition->printIR(outFile);
		Scope::tabs(outFile);
		auto elseLabel = _ifScope->getName()+"ifFailed";
		outFile<< formatIR("breq",_condition->_var,"1",elseLabel);
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
	
	
	void mangle() override{
		if(_condition){
		
		//std::cout << "mangle condition ifstm " <<_name <<std::endl;	
			_condition->mangle();
		}
		if(_ifScope){
		
		//std::cout << "mangle scope ifstmt " <<_name <<std::endl;	
			_ifScope->mangle();
		}
		
		
		//std::cout << "mangle done ifstm " <<_name <<std::endl;	
		
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
		_condition->printIR(outFile);
		Scope::tabs(outFile);

		auto elseLabel = _ifScope->getName()+"iffailed";
		auto end = _ifScope->getName()+"ifend";
		outFile<< formatIR("breq",_condition->_var,"1",elseLabel);
		outFile<<"\n";
		_ifScope->generateIR(outFile);
		outFile<< formatIR("goto",end);
		outFile<<"\n";
		Scope::tabCounter--;
		Scope::tabs(outFile);
		outFile << elseLabel << ":";
		outFile<<"\n";
		Scope::tabCounter++;
		_elseScope->generateIR(outFile);
		
		Scope::tabCounter--;		
		outFile << end << ":";
		outFile<<"\n";
		Scope::tabCounter++;
	}
	
	
	
	
	void printSymbols() override{
		
		logger("printing ifelse");
		//print subscopes
		_ifScope->printSymbols();
		_elseScope->printSymbols();
	}
	
	
	
	void mangle() override{
		if(_condition){
		
		//std::cout << "mangle cond ifelse " <<_name <<std::endl;	
			_condition->mangle();
		}
		if(_ifScope){
		
		//std::cout << "mangle if of ifelse " <<_name <<std::endl;	
			_ifScope->mangle();
		}
		if(_elseScope){
		
		//std::cout << "mangle else ifelse " <<_name <<std::endl;	
			_elseScope->mangle();
		}
		
		//std::cout << "mangle ifelse done " <<_name <<std::endl;	
		
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
		
		_condition->printIR(outFile);
		
		Scope::tabs(outFile);
		outFile<< formatIR("breq",_condition->_var,"1",whileEnd) <<"\n";
		
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
	
	
	void mangle() override{
	
		//std::cout << "mangle while " <<_name <<std::endl;	
		if(_condition){
		
		//std::cout << "mangle cond while " <<_name <<std::endl;	
			_condition->mangle();
		
		}
		if(_whileScope){
		
		//std::cout << "mangle while scope " <<_name <<std::endl;	
			_whileScope->mangle();
		
		}
		
		//std::cout << "mangle while done " <<_name <<std::endl;	
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
	
	
	void mangle() override{
	
		//std::cout << "mangle for " <<_name <<std::endl;	
		if(_from){
		
		//std::cout << "mangle from " <<_name <<std::endl;	
			_from->mangle();
		}
		if(_to){
		
		//std::cout << "mangle to " <<_name <<std::endl;	
			_to->mangle();
		
		}
		if(_assignVar.size()){
		
		//std::cout << "mangle for assign " <<_name <<std::endl;	
			_assignVar = Scope::getMangledName(_assignVar);
		}
		
		if(_forScope){
		
		//std::cout << "mangle for scope " <<_name <<std::endl;	
			_forScope->mangle();
		}
		
		
		//std::cout << "mangle for done " <<_name <<std::endl;	
		
	}
	
	
	void printSymbols() override{
		
		logger("printing for");
		_forScope->printSymbols();
	}
	
	void printIR(std::ofstream &outFile) override{
		auto forStart = _forScope->getName() +"forCondition";
		auto forEnd = _forScope->getName() +"forEnd";
		
		
		_from->printIR(outFile);
		Scope::tabs(outFile);
		outFile << formatIR("assign",_assignVar, _from->_var) << "\n";
		
		Scope::tabCounter--;
		Scope::tabs(outFile);
		outFile << forStart <<":\n";	
		Scope::tabCounter++;
		
		_to->printIR(outFile);
		Scope::tabs(outFile);
		outFile<< formatIR("brgt",_assignVar,_to->_var,forEnd) <<"\n";
		
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
	
	
	void mangle() override{
	
		//std::cout << "mangle fncall " <<_name <<std::endl;	
		for(auto par : _fnCallParams){
		
			//std::cout << "mangle fnpar " <<_name <<std::endl;	
			par->mangle();
		}
		if(_lvalue.size()){
		
			
		//std::cout << "mangle lval of call " <<_name <<std::endl;	
			_lvalue = Scope::getMangledName(_lvalue);
		}
		if(_lvalueIndex){	
		
		//std::cout << "mangle lval idx call " <<_name <<std::endl;		
			_lvalueIndex->mangle();
		}
		
		
		//std::cout << "mangle fn call done " <<_name <<std::endl;	
		
	
	}
	
	void printIR(std::ofstream &outFile) override{
		
		
		for (auto par :_fnCallParams)
		{
			par->printIR(outFile);
		
		}
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
	static int loopCounter;

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
	
	
	void mangle() override{
	
		//std::cout << "mangle ret " <<_name <<std::endl;	
		if(_retVal){
		
		//std::cout << "mangle retval " <<_name <<std::endl;	
			_retVal->mangle();
		
		}	
		//std::cout << "mangle done " <<_name <<std::endl;	
	}
	
	void printIR(std::ofstream &outFile) override{
		Scope::tabs(outFile);
		if(_retVal){
			_retVal->printIR(outFile);
			outFile<< formatIR("return", _retVal->_var)<<"\n";
		}
		else{
			outFile<< formatIR("return")<<"\n";		
		}
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
	
	void mangle() override{
	
		//std::cout << "mangle subscope " <<_name <<std::endl;	
		if(_scope){
			_scope->mangle();
		}	
		
		//std::cout << "mangle done subscope " <<_name <<std::endl;	
	}
	
	void printIR(std::ofstream &outFile) override{
		//TODO transfer vars to parent scopes
		_scope->generateIR(outFile);
	}
	
	void printSymbols() override{
		
		logger("printing subscope");
		_scope->printSymbols();
	}
};



#endif
