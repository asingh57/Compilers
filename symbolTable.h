
#include "TigerBaseListener.h"

#include <map>
#include <string>
#include <variant>
#include <vector>

class Scope;
struct Symbol;

enum DataType{
//uninitialised data type
TYPE_ZERO = 0,
//types
 TYPE_INT,
 TYPE_VOID,

//type array
 TYPE_ARRAY,

//type alias
 TYPE_ALIAS,

//function
 TYPE_FUNCTION,
 
};

enum StorageClass{
	STORAGE_STATIC,
	STORAGE_VAR
};


union Value{
	int intval;
};

struct Symbol{
	static int tabCount;
	
	
	DataType type;
	StorageClass storageclass;
	Value val;
	std::string name;
	
	//valid for arrays
	DataType arrayItemType;
	std::vector<Symbol> symbolArray;
	int len;
	
	//valid for aliases
	DataType aliasType;	
	Symbol* alias;//alias assigned to alias
	
	//valid for loops and functions
	std::vector<Scope> childScopes;
	
	//valid only for function calls
	std::vector<Symbol> inputVariables;
	DataType returnType; 
	
	void print(){
		
		tabCount++;
		for(int i = 0; i< tabCount; i++){
		    	std::cout << "\t";
		}
		if(type==TYPE_INT){
			std::cout << name << ", " << std::string((storageclass==STORAGE_STATIC)?"static":"var")<<", int";
		}
		else if(type==TYPE_ALIAS){
			std::cout << name << ", type, ";
			if(aliasType==TYPE_ALIAS){
				std::cout << alias->name;
			}
			else if(aliasType==TYPE_INT){
				std::cout << "int";
			}
			else if(aliasType==TYPE_ARRAY){
				std::cout << "array, "<<len;
			}
		}
		
		std::cout << "\n";
	
		tabCount--;
		
		
	}

	Symbol():type(TYPE_ZERO){
	
	}
};



class Scope{
	private:
	std::string _name;
	Scope* _parent;
	std::map<std::string, Symbol*> _symbols;
	static int scopeCounter;
	public:
	Scope(std::string name, Scope* parent=nullptr): _name(name), _parent(parent), _symbols(){}
	void addSymbol(std::string name, Symbol* property){
		_symbols.insert(std::make_pair(name,property));
		property->name = name;	
	}
	
	Scope* getParent(){
		return _parent;
	}
	
	Symbol* getSymbol(std::string name,bool checkParents=true){
		auto fnd = _symbols.find(name);
		if(fnd != _symbols.end()){
			return fnd->second;
			
		}
		if(_parent){
			return _parent->getSymbol(name);
		}
		return NULL;
	}
		
		
	
  void printSymbolTable(){
  
	for (auto const& [key, val] : _symbols)
	{
	    val->print();	    
	} 
	
  }
};

int Scope::scopeCounter=0;
int Symbol::tabCount=0;








