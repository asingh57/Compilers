#include "scope.h"


Symbol::Symbol(std::string name,Scope* scope, Type type){
		_name = name;
		_scope = scope;
		scope->_symbolsMap.insert(std::make_pair(_name,this));
		_type=type;
	}
Symbol::Symbol(Scope* scope, Type type){
	_name="_t"+std::to_string(counter++);
	_scope = scope;
	scope->_symbolsMap.insert(std::make_pair(_name,this));
		_type=type;
}	



enum StorageClass{
	STORAGE_VAR,
	STORAGE_STATIC
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
		
	SymbolVariable(
	Scope* scope,
	Type deriveFromType=TYPE_INT, 
	std::string deriveFromSymbolName="" /*used if deriveFromType is TYPE_TYPEDEF*/, 
	StorageClass storageclass=STORAGE_VAR, 
	bool hasValue=false ,
	int defaultValue=0/*gets assigned to zero if StorageClass  static*/)
	: 
		Symbol(scope, TYPE_VARIABLE),
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
		if(_hasValue){
			std::cout << ", "<< _defaultValue;
		}
		
		std::cout << std::endl;
	
	};
};

