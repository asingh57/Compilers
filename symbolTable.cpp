#include "symbolTable.h"
std::vector<std::function<void()>> ErrorCheckingTask::tasks = {};

void printErrorAndExit(int line, int col, IRErrorMessageID msg){
	
	
	std::string desc;
	switch(msg){
		case IRERROR_NO_SUCH_TYPE:
		{
		desc = "type does not exist";
		break;
		}
		case IRERROR_NO_ARRAY_ALLOWED_VAR:
		{
		desc = "arrays are not allowed to be assigned directly to var. Must define as type first";
		break;
		}
		case IRERROR_NO_SUCH_VARIABLE:
		{
		desc = "variable doesn't exist";
		break;
		}
		case IRERROR_ZERO_SIZED_ARRAY:
		{
		desc = "non positive sized array not allowed";
		break;
		}
		case IRERROR_NOT_ASSIGNABLE_TYPE:
		{
		desc = "not an assignable type (cannot be a var or function)";
		break;
		}
		case IRERROR_NONSTATICVAR_NOT_ALLOWED_MAIN:
		{
		desc = "non static vars not allowed in main scope";
		break;
		}
	
	}
	
	std::cerr << "line " <<line <<":" <<col<< " " << desc<<std::endl;
	exit(SEMANTIC_ERROR);
}
