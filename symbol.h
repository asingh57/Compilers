#ifndef _SYMBOL
#define _SYMBOL
#include "scope.h"




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
	
	std::string getFinalIR(){
		std::string val = "";
		
		val = _name;
		
		if(_deriveFromType==TYPE_TYPEDEF){
			//TODO resolve type and add array if needed;
			
			
		}
		
		
		return val;
	}
	
	
};


class SymbolTypedef : public Symbol{
public: 
	bool _isArray;
	int _arrayLen; 
	Type _deriveFromType; 
	std::string _deriveFromSymbolName;
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
	
	void getFinalIR(std::ofstream &outFile){
		Scope::tabCounter++;
		Scope::tabs(outFile);
		outFile << "start_function " << _name << std::endl;
		Scope::tabs(outFile);
		if(_returnType == TYPE_VOID){
			outFile <<"void";
		}
		else{ //todo resolve type
			outFile <<"int";
		}
		outFile << " "<< _name <<" (";
		
		for(int i=0; i<_params.size(); i++){
			outFile <<"int ";
			outFile << _params[i]->getFinalIR();
			
			
			if(i!=_params.size()-1){
				outFile << ", ";
			}			
			
		}
		
		outFile <<")\n";
		Scope::tabs(outFile);
		
		outFile << "int-list: "; 
		//get vars from scope and put them here
		auto scopeVars = associatedScope->getVars();
		
		for(int i=0; i<scopeVars.size(); i++){
			outFile << dynamic_cast<SymbolVariable*>(scopeVars[i])->getFinalIR();			
			
			if(i!=scopeVars.size()-1){
				outFile << ", ";
			}
		}
		
		
		outFile <<"\n";
		Scope::tabs(outFile);
		outFile << _name << ":\n";
		
		associatedScope->generateIR(outFile);
		
		Scope::tabs(outFile);
		outFile << "end_function " << _name << "\n" << std::endl;		
		Scope::tabCounter--;
		return;
	}
};

#endif
