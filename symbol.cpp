#include "symbol.h"

int Symbol::counter=0;

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


