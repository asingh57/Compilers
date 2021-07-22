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
		case IRERROR_NOT_ASSIGNABLE_VAR:
		{
		desc = "types and functions cannot be assigned as rval";
		break;
		}
		case IRERROR_SYMBOL_ALREADY_EXISTS:
		{
		desc = "Symbol already defined in this scope";
		break;
		}
		case IRERROR_ILLEGAL_BREAK_STATEMENT:
		{
		desc = "Illegal break statement, no parent loop present";
		break;
		}
		case IRERROR_COMPARATORS_NON_ASSOCIATIVE:
		{
		desc = "comparison operators are non associative";
		break;
		}
		case IRERROR_PROCEDURE_NON_NULL_RETURN:
		{
		desc = "Procedure cannot have return value";
		break;
		}
		case IRERROR_FUNCTION_NO_RETURN_VAL:
		{
		desc = "Function cannot return without return value";
		break;
		}
		case IRERROR_ARRAY_OPERATOR:
		{
		desc = "binary operators not allowed on array type";
		break;
		}
		case IRERROR_INDEX_ON_NON_ARRAY:
		{
		desc = "index on a non array type";
		break;
		}
		case IRERROR_TYPE_MISMATCH:
		{
		desc = "arrays of different sizes cannot be assigned to each other";
		break;
		}
		case IRERROR_FOR_TO_CONDITIONS_NOT_INT:
		{
		desc = "for and to values for for statement must be integer values";
		break;
		}
		
	
	}
	
	std::cerr << "line " <<line <<":" <<col<< " " << desc<<std::endl;
	exit(SEMANTIC_ERROR);
}
