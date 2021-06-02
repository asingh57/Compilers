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
COMMENT : '/*'[a-zA-Z0-9 \t\r\n]*'*/' -> skip;
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
funct : FUNCTION ID OPENPAREN param_list CLOSEPAREN ret_type BEGIN stat_seq END;
param_list : param param_list_tail | /*empty*/;
param_list_tail : COMMA param param_list_tail | /*empty*/;
ret_type : COLON type | /*empty*/;
param : ID COLON type;
stat_seq : stat | stat stat_seq;
stat : lvalue l_tail ASSIGN expr SEMICOLON |
	IF expr THEN stat_seq ENDIF SEMICOLON |
	IF expr THEN stat_seq ELSE stat_seq ENDIF SEMICOLON |
	WHILE expr DO stat_seq ENDDO SEMICOLON |
	FOR ID ASSIGN expr TO expr DO stat_seq ENDDO SEMICOLON |
	opt_prefix ID OPENPAREN expr_list CLOSEPAREN SEMICOLON |
	BREAK SEMICOLON |
	RETURN opt_return SEMICOLON |
	LET declaration_segment BEGIN stat_seq END;
opt_return : expr | /*empty*/;
opt_prefix : lvalue ASSIGN | /*empty*/;
l_tail : ASSIGN lvalue l_tail | /*empty*/;
expr : constant | lvalue | expr binary_operator expr | OPENPAREN expr CLOSEPAREN;
constant : INTLIT;

//TODO fix binary operator ambiguity

binary_operator : PLUS | MINUS | MULT | DIV | POW  | EQUAL | NEQUAL | LESS | GREAT | LESSEQ | GREATEQ | AND | OR;
expr_list : expr expr_list_tail | /*empty*/;
expr_list_tail : COMMA expr expr_list_tail | /*empty*/;
lvalue : ID lvalue_tail;
lvalue_tail : OPENBRACK expr CLOSEBRACK | /*empty*/;
	


