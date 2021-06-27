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
		Scope::tabCounter++;	
	if(_programName.size()){//this scope is the top level program scope
		outFile << "start_program "+ _programName<< std::endl;
		
		Scope::tabs(outFile);
		outFile << "static-int-list: "	;
		//print all var names
		std::vector<std::string> staticList; //pair of name and optionally an array length

		for(auto const& [key, val] : _symbolsMap){
			if(val->getType()==TYPE_VARIABLE){
				auto var = dynamic_cast<SymbolVariable*>(val);//TODO VAR SIZES
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
		//print stats
		for (auto st = _stats.rbegin(); st != _stats.rend(); ++st)
		{
			(*st)->printIR(outFile);
		}
		
		
		
	
	}
		Scope::tabCounter--;
}



 std::vector<Symbol*> Scope::getVars(){
 	std::vector<Symbol*> ret;
 	
 	for(auto const& [key, val] : _symbolsMap){
		if(val->getType()==TYPE_VARIABLE){
			ret.push_back(val);
		}
	}
 	return ret;
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

