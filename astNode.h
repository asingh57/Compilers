#ifndef _ASTNODE
#define _ASTNODE
#include "stat.h"

enum Operator{
	OPERATOR_PLUS,
	OPERATOR_MINUS,
	OPERATOR_MULT,
	OPERATOR_DIV,
	OPERATOR_POW,
	OPERATOR_LT,	
	OPERATOR_GT,	
	OPERATOR_LTE,	
	OPERATOR_GTE,	
	OPERATOR_EQ,
	OPERATOR_NEQ,
	OPERATOR_AND,
	OPERATOR_OR
};

class ASTNode{
	public:
		static std::vector<ASTNode*> astStack;
		
		std::string _var; //(output) variable of ast node
		bool _hasIndex; 
		ASTNode* _index;//index of var determined by an expression
		bool _isLeaf; //is this a leaf node?
		//if not leaf node, following apply
		ASTNode* _left;//left child
		ASTNode* _right;// right child
		Operator _op; //operator between left and right child that output to this var
		ASTNode* _parent; //parent AST node
		Scope* _scope;
		
		static std::string formatIR(std::string a = "",std::string b = "",std::string c = "",std::string d = ""){
			return a + ", " +b+ ", " +c +", " + d;
		}
		
		static int branchCounter;
		
		static void outputCondition(std::string outVar, std::string left, std::string right, std::string branch, std::ofstream &outFile){
		
						
			std::string brct = std::to_string(branchCounter++);
			std::string notTrue = "_"+branch+"false"+brct;
			std::string end = "_"+branch+"end"+brct;
			
			Scope::tabs(outFile);
			outFile << formatIR(branch,  left ,right, notTrue)<<"\n";
			
			Scope::tabs(outFile);
			outFile << formatIR("assign", outVar ,"1") << "\n";
			
			Scope::tabs(outFile);
			outFile << formatIR("goto",end)<<"\n"	;					
			
			outFile << notTrue << ":" << "\n";
			
			Scope::tabs(outFile);
			outFile << formatIR("assign", outVar ,"0") << "\n";
			
			outFile << end << ":" << "\n";
			
			//outFile << formatIR("or", _left->_var, _right->_var, _var);
			outFile <<std::endl;
		}
		
		
		void printIR(std::ofstream &outFile){
			//todo handle _index
		
			if(!_isLeaf && _left && _right){
				_left->printIR(outFile);
				_right->printIR(outFile);
			
				switch(_op){
					case OPERATOR_PLUS:
					{
						Scope::tabs(outFile);
						outFile << formatIR("add", _left->_var, _right->_var, _var);
						outFile <<std::endl;
						
						break;
					};
					case OPERATOR_MINUS:
					{
						
						Scope::tabs(outFile);
						outFile << formatIR("sub", _left->_var, _right->_var, _var);
						outFile <<std::endl;
						break;
					};
					case OPERATOR_MULT:
					{
						
						Scope::tabs(outFile);
						outFile << formatIR("mult", _left->_var, _right->_var, _var);
						outFile <<std::endl;
						break;
					};
					case OPERATOR_DIV:
					{
						
						Scope::tabs(outFile);
						outFile << formatIR("div", _left->_var, _right->_var, _var);
						outFile <<std::endl;
						break;
					};
					case OPERATOR_AND:
					{
						
						Scope::tabs(outFile);
						outFile << formatIR("and", _left->_var, _right->_var, _var);
						outFile <<std::endl;
						break;
					};
					case OPERATOR_OR:
					{
						
						Scope::tabs(outFile);
						outFile << formatIR("or", _left->_var, _right->_var, _var);
						outFile <<std::endl;
						break;
					};
					
					
					case OPERATOR_LT:
					{
						outputCondition(_var, _left->_var, _right->_var, "brlt" ,outFile);
						break;
					};
					case OPERATOR_GT:
					{
						outputCondition(_var, _left->_var, _right->_var, "brgt" ,outFile);
						break;
					};
					case OPERATOR_LTE:
					{
						outputCondition(_var, _left->_var, _right->_var, "brleq" ,outFile);
						break;
					};
					case OPERATOR_GTE:
					{
						outputCondition(_var, _left->_var, _right->_var, "brgeq" ,outFile);
						break;
					};
					case OPERATOR_EQ:
					{
						outputCondition(_var, _left->_var, _right->_var, "breq" ,outFile);
						break;
					};
					case OPERATOR_NEQ:
					{
						outputCondition(_var, _left->_var, _right->_var, "brneq" ,outFile);
						break;
					};
					
				};
			}
		
		}
		
		void mangle(){
		
		
			//std::cout <<"mangling astnode "<<_var << std::endl; 
			if(_var.size()){
				_var=Scope::getMangledName(_var);			
			}
			//std::cout <<"left "<<_var << std::endl;
			if(_left){
				_left->mangle();
			}
			//std::cout <<"right "<<_var << std::endl;
			
			if(_right){
				_right->mangle();
			}
			
			//std::cout <<"index "<<_var << std::endl;
			if(_index){
				_index->mangle();
			}
			
			//std::cout <<"done "<<_var << std::endl;
		}
		
		ASTNode(ASTNode* parent=NULL): _var("") ,_parent(parent), _index(NULL), _hasIndex(false), _left(NULL), _right(NULL), _isLeaf(false), _scope(Scope::scopeStack.back()){
		
		}
		
		bool isIntegerChain(bool &indexOnNonArray, int* arraySz=NULL){
			
			
			//std::cout << "check if " << _var << "is array" << std::endl;
			
			bool res=true;
			std::string scopeName;


			if(dynamic_cast<SymbolVariable*>(_scope->getSymbol(_var,scopeName))->isArray(arraySz)){
				if(_hasIndex){
				
					//std::cout << _var << "has index" << std::endl;
					res = true;
				}
				else{
					//std::cout << _var << "has no index" << std::endl;

					res = false;				
				}
			}
			else if(_hasIndex){

				//has an index on an integer type
				indexOnNonArray=true;
			}
			

			if(_left){



				res = res &&  _left->isIntegerChain(indexOnNonArray,arraySz);

			}
			if(_right){

				res = res &&  _right->isIntegerChain(indexOnNonArray,arraySz);

			}
			
			

			return res;
		}
		
		
		virtual void printSymbols(){
		
		logger("printing ast");
		}
		
		
		
		
};







































#endif
