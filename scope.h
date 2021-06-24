#include "TigerBaseListener.h"

#define DEBUG

void logger(std::string s){

#ifdef DEBUG
//std::cout << s << std::endl;
#endif
}


class Stat;//statements type (ifelse, return, loop etc...)
class Symbol;//symbol type (function. typedef, var (user defined as well as generated), static)
class Scope;

enum Type{
	TYPE_VARIABLE,
	TYPE_TYPEDEF,
	TYPE_INT,
	TYPE_FUNC,
	TYPE_VOID
};

class Symbol{
protected:
std::string _name;
Scope* _scope;
Type _type;
public:
static int counter;
	Symbol(std::string name, Type type);
	Symbol(Type type);
	std::string getName(){
		return _name;
	}
	Scope* scope(){
		return _scope;
	}
	Type getType(){
		return _type;
	}
	virtual void print(){};
};
int Symbol::counter=0;


class Scope{
	friend class Symbol;
private:
	std::map<std::string, Symbol*> _symbolsMap;//list of symbols in scope
	Scope* _parentScope;//parent scope
	std::string _name;//scope name (auto generated
	Stat* _associatedStat;//associated parent statement if applicable
	std::vector<Stat*> _stats; //sub-statements inside scope
	Scope(std::string name, Scope* parentScope=NULL, Stat* associatedStat=NULL) : _symbolsMap(), _parentScope(parentScope), _name(name), _stats(), _associatedStat(NULL){
		logger("created scope");
		logger(name);
	}
public:
	static std::vector<Scope*>scopeStack;
	static int scopeCounter;//counter for creating new scopes
	static int tabCounter;//keeps count of scope tabs
	static void tabs(){//print tabs
		for(int i=0;i<tabCounter;i++){
			std::cout << "    ";
		}
	}
	//scope factory
	static Scope* create(Scope* parent=NULL){
		auto sc = new Scope("Scope" + std::to_string(scopeCounter++), parent);
		scopeStack.push_back(sc);
		return sc;
	}
	
	
public:
	//get parent
	Scope* parent(){
		return _parentScope;
	}
	
	/*
	//add symbol to scope
	void addSymbol(Symbol* value){
		_symbolsMap.insert(std::make_pair(value->_name,value));
	}*/
	
	void addStat(Stat* stat){
		_stats.push_back(stat);
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
		
		logger("printing scope table");
	
		logger(_name);
		tabs();
		std::cout<< _name <<":" <<std::endl;
		tabCounter++;
		for(auto const& [key, val] : _symbolsMap){
			val->print();
		}
		tabCounter--;
	}
	
};
std::vector<Scope*> Scope::scopeStack= std::vector<Scope*>();
int Scope::scopeCounter=0;
int Scope::tabCounter=0;



