#include "symbol.h"
#include "stat.h"
#include "astNode.h"
Scope::Scope(std::string name, Scope* parentScope, Stat* associatedStat) : _programName(""), _symbolsMap(), _childrenScope(), _parentScope(parentScope), _name(name), _stats(), _associatedStat(associatedStat){
		logger("created scope");
		logger(name);
		
		if(parentScope){
			parentScope->_childrenScope.push_back(this);
		}
	}
	
	
Symbol* Scope::getSymbol(std::string name, std::string &scopeName, bool checkParents){
		auto search= _symbolsMap.find(name);
		if(search!=_symbolsMap.end()){
			scopeName = _name;
			return search->second;
		}
		
		if(_parentScope && checkParents){
			return _parentScope->getSymbol(name,scopeName,checkParents);
		}
		
		return nullptr;
	}
	

void Scope::printSymbols(){
	
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


void Scope::generateIR(std::ofstream &outFile){
		Scope::tabCounter++;	
	if(_programName.size()){//this scope is the top level program scope
		outFile << "start_program "+ _programName<< std::endl;
		
		Scope::tabs(outFile);
		outFile << "static-int-list: "	;
		//print all var names
		std::vector<std::string> staticList; //pair of name and optionally an array length

		staticList.push_back(Symbol::powStart);
		staticList.push_back(Symbol::powEnd);
		staticList.push_back(Symbol::arrayLoad);

		for(auto const& [key, val] : _symbolsMap){
			if(val->getType()==TYPE_VARIABLE){
				auto var = dynamic_cast<SymbolVariable*>(val);
				std::string name= var->getFinalIR();
				staticList.push_back(name);
			}
		}
		
		for(int i=0; i<staticList.size(); i++){
			outFile<<staticList[i];
			if(i!=staticList.size()-1){
				outFile<<", ";
			}
		}
		
		outFile <<"\n"<< std::endl;
		
		//iterate through functions
		for(auto const& [key, val] : _symbolsMap){
			if(val->getType()==TYPE_FUNC){
				auto fn = dynamic_cast<SymbolFunc*>(val);
				//call function IR
				
				fn->getFinalIR(outFile);
			}
		}
		
		
		outFile << "end_program "+ _programName<< std::endl;
	}
	else{
		//if vars have assigned values, output them
		for(auto const& [key, val] : _symbolsMap){
			if(val->getType()==TYPE_VARIABLE){
				auto var = dynamic_cast<SymbolVariable*>(val);
				std::string name= var->_name;
				//staticList.push_back(name);
				
				int len = -1;
				if(var->_hasValue){
					if(var->isArray(&len)){
						//todo handle assignment of array
					}
					else{
						tabs(outFile);
						outFile << Stat::formatIR("assign", name, std::to_string(var->_defaultValue));
						outFile << "\n";
					}
				}
				
			}
		}
		
		//print stats
		for (auto st = _stats.rbegin(); st != _stats.rend(); ++st)
		{
			(*st)->printIR(outFile);
		}
		
		
		
	
	}
		Scope::tabCounter--;
}


Scope* Scope::currentFunctionParent = NULL;

 std::vector<Symbol*> Scope::getVars(){
 	std::vector<Symbol*> ret;
 	
 	for(auto const& [key, val] : _symbolsMap){
		if(val->getType()==TYPE_VARIABLE){
			ret.push_back(val);
		}
	}
 	return ret;
 }



void Scope::mangle(){
	//std::cout <<"mangling " << _name << std::endl;
	
	if( _programName.size() /*main*/){
	
		//std::cout << "set top scope" <<_name <<std::endl;
		topLevelScope= this;
	}

	std::vector<std::string> unmangledSymbols;	
	for(auto const& [symbolName, symbol] : _symbolsMap){
		if(symbol->getType()==TYPE_VARIABLE){
			//std::cout << "collect symbols for mangling in var,scope" << symbolName << " " <<_name <<std::endl;
			pushToNameMangling(symbolName, _name);
			unmangledSymbols.push_back(symbolName);				
		}		
	}
	
	for(auto unmng : unmangledSymbols){
		//std::cout << "find unmangled sym scope"<< unmng << " " <<_name <<std::endl;		
		auto it=_symbolsMap.find(unmng);	
		topLevelScope->_symbolsMap[getMangledName(unmng)]=_symbolsMap[unmng];
		_symbolsMap[unmng]->_name = getMangledName(unmng);
		_symbolsMap.erase (it); 
	}
	
	//iterate through functions and mangle their scopes
	for(auto const& [key, val] : _symbolsMap){
		if(val->getType()==TYPE_FUNC){				
			auto fn = dynamic_cast<SymbolFunc*>(val);
			topLevelScope = fn->associatedScope;
			topLevelScope->mangle();				
		}
	}
	
		//std::cout << "mangle stats in" <<_name <<std::endl;	
	for(auto st: _stats){
		
		st->mangle();		
	}
	//std::cout << "mangle stats done, now pop" <<_name <<std::endl;	
	
	
	
	popScopeFromNameMangling(_name);
	
	//std::cout << "popped name" <<_name <<std::endl;	
}









void logger(std::string s){

#ifdef DEBUG
Scope::tabs();
std::cout << s << std::endl;
#endif
}


std::vector<Scope*> Scope::scopeStack= std::vector<Scope*>();
int Scope::scopeCounter=0;
int Scope::tabCounter=0;


std::map<std::string,std::vector<std::string>> Scope::nameMangling = {};


Scope* Scope::topLevelScope = nullptr;
