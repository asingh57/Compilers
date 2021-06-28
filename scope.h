#ifndef _SCOPE
#define _SCOPE
#include "TigerBaseListener.h"
#include "symbol.h"

#include <iostream>
#include <fstream>  
//#define DEBUG

void logger(std::string s);

class Symbol;
class Stat;

enum Type{
	TYPE_NONE,
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



class Scope{
	friend class Symbol;
public:
	std::string _programName;
	static Scope* topLevelScope;
	
private:
	std::map<std::string, Symbol*> _symbolsMap;//list of symbols in scope
	Scope* _parentScope;//parent scope
	std::vector<Scope*> _childrenScope;
	std::string _name;//scope name (auto generated
	Stat* _associatedStat;//associated parent statement if applicable
	std::vector<Stat*> _stats; //sub-statements inside scope
	Scope(std::string name, Scope* parentScope=NULL, Stat* associatedStat=NULL);
	
public:

	static std::map<std::string,std::vector<std::string>> nameMangling;

	static bool hasEnding (std::string const &fullString, std::string const &ending) {
	    if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
	    } else {
		return false;
	    }
	}


	static void pushToNameMangling(std::string varName, std::string scopeName){
		auto it = nameMangling.find(varName);
		if(it == nameMangling.end()){
			nameMangling[varName]=std::vector<std::string>();
		}
		nameMangling[varName].push_back(scopeName);		
	}
	
	static void popScopeFromNameMangling(std::string scopeName){
		for (auto const& [varName, varStack] : nameMangling)
		{
			if (varStack.size() && varStack.back().compare(scopeName) == 0){
				//scope value is present for var name
				nameMangling[varName].pop_back();
			}
		}		
	}
	
	static std::string getMangledName(std::string name){
		return name+nameMangling[name].back();
	}
	

	static Scope* currentFunctionParent;
	static std::vector<Scope*>scopeStack;
	static int scopeCounter;//counter for creating new scopes
	static int tabCounter;//keeps count of scope tabs
	static void tabs(){//print tabs
		for(int i=0;i<tabCounter;i++){
			std::cout << "    ";
		}
	}
	static void tabs(std::ofstream &outfile){
		for(int i=0;i<tabCounter;i++){
			outfile << "    ";
		}
	}
	//scope factory
	static Scope* create(Scope* parent=NULL){
		auto sc = new Scope("_Scope" + std::to_string(scopeCounter++), parent);
		scopeStack.push_back(sc);
		return sc;
	}
	
	
	void mangle();
	
	
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
	Symbol* getSymbol(std::string name, std::string &scopeName ,bool checkParents=true);
	
	
	//print all symbols
	void printSymbols();
	
	void generateIR(std::ofstream &outFile);
	
	
	 std::vector<Symbol*> getVars();
	 
	 
	void mangleNames();
	
	void mangleVars();
};



#endif

