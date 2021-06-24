#include "scope.h"


Symbol::Symbol(std::string name,Type type){
		_name = name;
		_scope = Scope::scopeStack.back();
		_scope->_symbolsMap.insert(std::make_pair(_name,this));
		_type=type;
	}
Symbol::Symbol(Type type){
	_name="_t"+std::to_string(counter++);
	_scope = Scope::scopeStack.back();
	_scope->_symbolsMap.insert(std::make_pair(_name,this));
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
	Type deriveFromType=TYPE_INT, 
	std::string deriveFromSymbolName="" /*used if deriveFromType is TYPE_TYPEDEF*/, 
	StorageClass storageclass=STORAGE_VAR, 
	bool hasValue=false ,
	int defaultValue=0/*gets assigned to zero if StorageClass  static*/)
	: 
		Symbol(name, TYPE_VARIABLE),
		_deriveFromType(deriveFromType), 
		_deriveFromSymbolName(deriveFromSymbolName), 
		_storageclass(storageclass),
		_hasValue(hasValue), 
		_defaultValue(defaultValue){}
		
	SymbolVariable(
	Type deriveFromType=TYPE_INT, 
	std::string deriveFromSymbolName="" /*used if deriveFromType is TYPE_TYPEDEF*/, 
	StorageClass storageclass=STORAGE_VAR, 
	bool hasValue=false ,
	int defaultValue=0/*gets assigned to zero if StorageClass  static*/)
	: 
		Symbol( TYPE_VARIABLE),
		_deriveFromType(deriveFromType), 
		_deriveFromSymbolName(deriveFromSymbolName), 
		_storageclass(storageclass),
		_hasValue(hasValue), 
		_defaultValue(defaultValue){}
		
		
	void printSymbol() override {
		
		logger("print var");
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


class SymbolTypedef : public Symbol{
	bool _isArray;
	int _arrayLen; 
	Type _deriveFromType; 
	std::string _deriveFromSymbolName;
public: 
	SymbolTypedef(
	std::string name,
	bool isArray = false, 
	int arrayLen=0, 
	Type deriveFromType=TYPE_INT, 
	std::string deriveFromSymbolName=""
	)
	: 
		Symbol(name,TYPE_TYPEDEF), 
		_isArray(isArray),
		_arrayLen(arrayLen),
		_deriveFromType(deriveFromType),
		_deriveFromSymbolName(deriveFromSymbolName)
		{}
		
		
	
	void printSymbol() override {
		
		logger("print typedef");
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
	std::vector<SymbolVariable* > _params;
	Scope* associatedScope;
public: 
	SymbolFunc(std::string name,
	Type returnType=TYPE_VOID, 
	std::string returnSymbol=""/*fill this if return type is TYPE_TYPEDEF*/
	)
	: 
	Symbol(name,TYPE_FUNC), 
	_returnType(returnType), 
	_returnSymbol(returnSymbol),
	_params(),
	associatedScope(NULL)
	{
	}
	
	void addParam(SymbolVariable* sy){
		_params.push_back(sy);
	}
	void setAssociatedScope(Scope* sc){
		associatedScope=sc;
	}
	Scope* getAssociatedScope(){
		return associatedScope;
	}
	
	void printSymbol() override {
		
		
		logger("print func");
		
		Scope::tabs();
		
		std::cout << _name <<", func";
		if(_returnType == TYPE_INT){
			std::cout << ", int";
		}
		else if(_returnType == TYPE_TYPEDEF){
			std::cout << ", " << _returnSymbol;
		}
		std::cout << std::endl;
		Scope::tabCounter++;
		associatedScope->printSymbols();		
		Scope::tabCounter--;
	
	};
};

