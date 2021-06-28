#ifndef _ASTNODE
#define _ASTNODE


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
