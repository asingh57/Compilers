
#include "TigerBaseListener.h"

#include <map>
#include <string>
#include <variant>
#include <vector>
#include <cstring>
class Scope;
struct Symbol;

enum DataType{
//uninitialised data type
TYPE_ZERO = 0,
//types
 TYPE_INT,
 TYPE_VOID,
TYPE_ALIAS_ASSIGNED, //this is a var which has been assigned an alias val

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

typedef int Value;

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
	Scope* scope;
	
	//valid only for function calls
	std::vector<Symbol*> inputVariables;
	DataType returnType; 
	
	void print();

	
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



void Symbol::print(){
		
		tabCount++;
		for(int i = 0; i< tabCount; i++){
		    	std::cout <<  "    ";
		}
		if(type==TYPE_INT){
			std::cout << name << ", " << std::string((storageclass==STORAGE_STATIC)?"static":"var")<<", int";
		}
		else if(type == TYPE_ALIAS_ASSIGNED){
			std::cout << name << ", " << std::string((storageclass==STORAGE_STATIC)?"static":"var")<<", "<<alias->name;
			
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
		else if(type==TYPE_FUNCTION){
			std::cout << name<<",Function ,";
			if(returnType==TYPE_ALIAS){
				std::cout << alias->name;
			}
			else if(returnType==TYPE_INT){
				std::cout << "int, ";
			}
			else if(returnType==TYPE_ARRAY){
				std::cout << "array, "<<len;
			}
			else if(returnType==TYPE_VOID){
				std::cout << "void, "<<len;
			}
			
			std::cout <<"\n";
			for(int i = 0; i< tabCount; i++){
			    	std::cout <<  "    ";
			}
			std::cout <<"(";
			for(auto sy : inputVariables){			
				sy->print();
			}
			
			std::cout <<"\n";
			for(int i = 0; i< tabCount; i++){
			    	std::cout <<  "    ";
			}
			std::cout <<"):\n";
			
			scope->printSymbolTable();
		}
		
		std::cout << "\n";
	
		tabCount--;
		
		
	}




