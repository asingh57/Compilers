#include "symbolTable.h"


class SemanticEnforcer : public TigerBaseListener{
	Scope* globalScope;
public:
	SemanticEnforcer(SymbolTableGenerator* symTable):globalScope(symTable->getTopLevelScope()){
		for(auto tsk: ErrorCheckingTask::tasks){
			tsk();
		}
	}

};

class IRGenerator{
private:
	Scope* globalScope;
	std::ofstream _outfile;

public:
	IRGenerator(SymbolTableGenerator* symTable):globalScope(symTable->getTopLevelScope()){
		//first we must mangle all symbols
		//std::cout << "start global mangle" <<std::endl;
		globalScope->mangle();
		//std::cout << "mangle done" <<std::endl;
	}
	
	void run(std::string outFile){
		_outfile = std::ofstream(outFile);  
		globalScope ->generateIR(_outfile);
		_outfile.close();
	}
};
