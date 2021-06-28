grammar Tiger; // Define a grammar for tiger



//the lexical rules
////KEYWORDS
ARRAY : 'array';
BEGIN : 'begin';
BREAK : 'break';
DO : 'do';
ELSE : 'else';
END : 'end';
ENDDO : 'enddo';
ENDIF : 'endif';
FOR : 'for';
FUNCTION : 'function';
IF : 'if';
INT : 'int';
LET : 'let';
OF : 'of';
PROGRAM : 'program';
RETURN : 'return';
STATIC : 'static';
THEN : 'then';
TO : 'to';
TYPE : 'type';
VAR : 'var';
WHILE : 'while';

////Punctuation
COMMA : ',';
DOT : '.';
COLON : ':';
SEMICOLON : ';';
OPENPAREN : '(';
CLOSEPAREN : ')';
OPENBRACK : '[';
CLOSEBRACK : ']';
OPENCURLY : '{';
CLOSECURLY : '}';

////Binary operators
PLUS : '+';
MINUS : '-';
MULT : '*';
DIV : '/';
POW : '**';
EQUAL : '==';
NEQUAL : '!=';
LESS : '<';
GREAT : '>';
LESSEQ : '<=';
GREATEQ : '>=';
AND : '&';
OR : '|';


////Assignment Operators
ASSIGN : ':=';
TASSIGN : '=';


////Other ops
WS : [ \t\r\n]+ -> skip ; // skip spaces, tabs, newlines, \r (Windows)
COMMENT : '/*'(.*)'*/' -> skip;
ID : [a-zA-Z][a-zA-Z0-9_]*;
INTLIT : ([1-9][0-9]*|[0]);



//The Grammar
tiger_program : PROGRAM ID LET declaration_segment BEGIN funct_list END;
declaration_segment : type_declaration_list var_declaration_list;
type_declaration_list : type_declaration type_declaration_list | /*empty*/;
var_declaration_list : var_declaration var_declaration_list | /*empty*/;
funct_list : funct funct_list | /*empty*/;
type_declaration : TYPE ID TASSIGN type SEMICOLON;
type : type_id | ARRAY OPENBRACK INTLIT CLOSEBRACK OF type_id | ID;
type_id : INT;
var_declaration : storage_class id_list COLON type optional_init SEMICOLON;
storage_class : VAR | STATIC;
id_list : ID | ID COMMA id_list;
optional_init : ASSIGN constant | /*empty*/;
funct : FUNCTION ID OPENPAREN param_list CLOSEPAREN ret_type BEGIN stat_seq_func END;
param_list : param param_list_tail | /*empty*/;
param_list_tail : COMMA param param_list_tail | /*empty*/;
ret_type : COLON type | /*empty*/;
param : ID COLON type;
stat_seq_func: stat_seq;
stat_seq : stat | stat stat_seq;
stat : assignment_stat |
	if_stat |
	if_else_stat |
	while_stat |
	for_stat |
	fncall_stat |
	break_stat |
	return_stat |
	sub_scope_stat;

assignment_stat : lvalue l_tail ASSIGN expr SEMICOLON;
if_stat: if_stat_lhs ENDIF SEMICOLON;
if_else_stat: if_stat_lhs ELSE stat_seq_else ENDIF SEMICOLON;
while_stat: WHILE expr DO stat_seq_while ENDDO SEMICOLON;
for_stat: FOR ID ASSIGN expr TO expr DO stat_seq_for ENDDO SEMICOLON;
fncall_stat: opt_prefix ID OPENPAREN expr_list CLOSEPAREN SEMICOLON;
break_stat: BREAK SEMICOLON;
return_stat: RETURN opt_return SEMICOLON;
sub_scope_stat: LET declaration_segment BEGIN stat_seq END;

if_stat_lhs: IF expr THEN stat_seq_then;
stat_seq_then: stat_seq;
stat_seq_else : stat_seq;
stat_seq_while : stat_seq;
stat_seq_for : stat_seq;
opt_return : expr | /*empty*/;
opt_prefix : lvalue ASSIGN | /*empty*/;
l_tail : ASSIGN lvalue l_tail | /*empty*/;
expr : expr_no_op | unambiguous_expr;


//fix binary operator ambiguity by putting low priority things first in the recursion

unambiguous_expr: logical_op_expr;
logical_op_expr: compare_op_expr logical_op_expr_ext;
logical_op_expr_ext: ( AND | OR ) compare_op_expr logical_op_expr_ext | /*empty*/;
compare_op_expr: add_op_expr compare_op_expr_ext;
compare_op_expr_ext: ( EQUAL | NEQUAL | LESS | GREAT | LESSEQ | GREATEQ ) add_op_expr compare_op_expr_ext | /*empty*/;
add_op_expr: mult_op_expr add_op_expr_ext;
add_op_expr_ext: ( PLUS | MINUS ) mult_op_expr add_op_expr_ext | /*e*/;
mult_op_expr: pow_op_expr mult_op_expr_ext;
mult_op_expr_ext: ( MULT | DIV ) pow_op_expr mult_op_expr_ext | /*e*/;
pow_op_expr: pow_op_expr_ext expr_no_op ;
pow_op_expr_ext : pow_op_expr_ext expr_no_op ( POW ) | /*e*/;
//create expr but without binary operator
expr_no_op: constant | lvalue | OPENPAREN expr CLOSEPAREN;


constant : INTLIT;
expr_list : expr expr_list_tail | /*empty*/;
expr_list_tail : COMMA expr expr_list_tail | /*empty*/;
lvalue : ID lvalue_tail;
lvalue_tail : OPENBRACK expr CLOSEBRACK | /*empty*/;
	


