
#include "TigerBaseListener.h"

#include <map>
#include <string>
#include <variant>
#include <vector>
#include <cstring>


enum Type{
TYPE_TYPEDEF = 0,
TYPE_VARIABLE = 1,
TYPE_FUNC = 2,
TYPE_INT= 3,
TYPE_VOID
};

enum StorageClass{
	STORAGE_VAR,
	STORAGE_STATIC
};

class Scope;


class Symbol{
protected:
	Type _baseType;
	std::string _name;
	Scope* _scope;
public:
	static int tempCounter;
public: 
	Symbol(std::string name, Scope* scope, Type baseType): 
		_name(name), 
		_scope(scope), 
		_baseType(baseType){}
		
	virtual void print() {};

};

class Scope{
private:
	std::map<std::string, Symbol*> _symbolsMap;
	Scope* _parentScope;	
	std::string _name;
	Scope(std::string name, Scope* parentScope=NULL) : _symbolsMap(), _parentScope(parentScope), _name(name){
	
	}
public:

	static int scopeCounter;
	static int tabCounter;
	static void tabs(){
		for(int i=0;i<tabCounter;i++){
			std::cout << "    ";
		}
	}
public:
	//scope factory
	static Scope* create(Scope* parent=NULL){
		return new Scope("Scope " + std::to_string(scopeCounter++), parent);
	}
	
	
	void addSymbol(std::string name, Symbol* value){
		_symbolsMap.insert(std::make_pair(name,value));
	}
	Symbol* searchSymbol(std::string name, bool checkParents){
		auto search= _symbolsMap.find(name);
		if(search!=_symbolsMap.end()){
			return search->second;
		}
		
		if(_parentScope && checkParents){
			return _parentScope->searchSymbol(name,checkParents);
		}
		
		return nullptr;
	}
	
	
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

class SymbolVariable : public Symbol{
private:
	Type _deriveFromType;
	std::string _deriveFromSymbolName;
	StorageClass _storageclass;
	bool _hasValue;
	int _defaultValue;
public: 
	SymbolVariable(
	std::string name, 
	Scope* scope, 
	Type deriveFromType=TYPE_INT, 
	std::string deriveFromSymbolName="" /*used if deriveFromType is TYPE_TYPEDEF*/, 
	StorageClass storageclass=STORAGE_VAR, 
	bool hasValue=false ,
	int defaultValue=0/*gets assigned to zero if StorageClass  static*/)
	: 
		Symbol(name,scope, TYPE_VARIABLE),
		_deriveFromType(deriveFromType), 
		_deriveFromSymbolName(deriveFromSymbolName), 
		_storageclass(storageclass),
		_hasValue(hasValue), 
		_defaultValue(defaultValue){}
		
		
		
	void print() override {
		
		Scope::tabs();
		
		std::cout << _name <<", " <<std::string(_storageclass==STORAGE_VAR? "var":"static");
		if(_deriveFromType == TYPE_INT){
			std::cout << ", int";
		}
		else if(_deriveFromType == TYPE_TYPEDEF){
			std::cout << ", " << _deriveFromSymbolName;
		}
		
		std::cout << std::endl;
	
	};
};

class SymbolTypedef : public Symbol{
	bool _isArray;
	int _arrayLen; 
	Type _deriveFromType; 
	std::string _deriveFromSymbolName;
public: 
	SymbolTypedef(
	std::string name, 
	Scope* scope, 
	bool isArray = false, 
	int arrayLen=0, 
	Type deriveFromType=TYPE_INT, 
	std::string deriveFromSymbolName=""
	)
	: 
		Symbol(name,scope,TYPE_TYPEDEF), 
		_isArray(isArray),
		_arrayLen(arrayLen),
		_deriveFromType(deriveFromType),
		_deriveFromSymbolName(deriveFromSymbolName)
		{}
		
		
	
	void print() override {
		
		Scope::tabs();
		
		std::cout << _name <<", type";
		if(_deriveFromType == TYPE_INT){
			std::cout << ", int";
		}
		else if(_deriveFromType == TYPE_TYPEDEF){
			std::cout << ", " << _deriveFromSymbolName;
		}
		
		if(_isArray){
			std::cout << ",array , " << _arrayLen;
		}
		
		std::cout << std::endl;
	
	};
};

class SymbolFunc : public Symbol{

	Type _returnType; 
	std::string _returnSymbol;
public: 
	SymbolFunc(std::string name, 
	Scope* scope, 
	Type returnType=TYPE_VOID, 
	std::string returnSymbol=""/*fill this if return type is TYPE_TYPEDEF*/
	)
	: 
	Symbol(name,scope,TYPE_FUNC), 
	_returnType(returnType), 
	_returnSymbol(returnSymbol){
	}
	
	
	void print() override {
		
		Scope::tabs();
		
		std::cout << _name <<", func";
		if(_returnType == TYPE_INT){
			std::cout << ", int";
		}
		else if(_returnType == TYPE_TYPEDEF){
			std::cout << ", " << _returnSymbol;
		}
		
		std::cout << std::endl;
	
	};
};



int Scope::tabCounter=0;
int Scope::scopeCounter=1;
int Symbol::tempCounter=1;
