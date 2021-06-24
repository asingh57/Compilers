#include "TigerBaseListener.h"

#include <iostream>
#include <fstream>  
//#define DEBUG

void logger(std::string s);


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


enum StatType{
	STAT_NONE,
	STAT_ASSIGN,
	STAT_IF,
	STAT_IFELSE,
	STAT_WHILE,
	STAT_FOR,
	STAT_FNCALL,
	STAT_BREAK,
	STAT_RETURN,
	STAT_SUBSCOPE
};

class Stat{
public:
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
};

int Stat::nameCounter=0;


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
	virtual void printSymbol(){};
};
int Symbol::counter=0;


class Scope{
	friend class Symbol;
public:
	std::string _programName;
	
private:
	std::map<std::string, Symbol*> _symbolsMap;//list of symbols in scope
	Scope* _parentScope;//parent scope
	std::string _name;//scope name (auto generated
	Stat* _associatedStat;//associated parent statement if applicable
	std::vector<Stat*> _stats; //sub-statements inside scope
	Scope(std::string name, Scope* parentScope=NULL, Stat* associatedStat=NULL) : _programName(""), _symbolsMap(), _parentScope(parentScope), _name(name), _stats(), _associatedStat(NULL){
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
	
	std::string getName(){
		return _name;
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
			val->printSymbol();
		}
		
		logger("printing stat");
		logger(std::to_string(_stats.size()));
		for(auto st : _stats){
			if(st==NULL){
			
				logger("NULL st");
			}
			st->printSymbols();
			logger("print--");
		}
		
		
		logger("printed");
		
		tabCounter--;
	}
	
	void generateIR(std::ofstream &outFile){
		
	}
	
};


void logger(std::string s){

#ifdef DEBUG
Scope::tabs();
std::cout << s << std::endl;
#endif
}


std::vector<Scope*> Scope::scopeStack= std::vector<Scope*>();
int Scope::scopeCounter=0;
int Scope::tabCounter=0;



