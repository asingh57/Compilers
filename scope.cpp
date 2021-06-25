#include "symbol.h"
#include "stat.h"
Scope::Scope(std::string name, Scope* parentScope, Stat* associatedStat) : _programName(""), _symbolsMap(), _parentScope(parentScope), _name(name), _stats(), _associatedStat(NULL){
		logger("created scope");
		logger(name);
	}
	
	
Symbol* Scope::getSymbol(std::string name, bool checkParents){
		auto search= _symbolsMap.find(name);
		if(search!=_symbolsMap.end()){
			return search->second;
		}
		
		if(_parentScope && checkParents){
			return _parentScope->getSymbol(name,checkParents);
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
	if(_programName.size()){//this scope is the top level program scope
		outFile << "start_program "+ _programName<< std::endl;	
		outFile << "static-int-list:"	;
		//print all var names
		std::vector<std::pair<std::string,int>> staticList; //pair of name and optionally an array length
		for(auto const& [key, val] : _symbolsMap){
			if(val->getType()==TYPE_VARIABLE){
				/*int arrLen = -1;//not an array
				auto var = dynamic_cast<SymbolVariable>
				if(){
				
				}
				
				staticList.push_back(std::make_pair(val->getName(),arrLen));*/
			}
		}
		outFile<< std::endl;
	}
	else{
	
	}
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

