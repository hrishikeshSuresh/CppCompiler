%{
	/*
		AUTHORS 	: 		 Hrishikesh S.
							 Adarsha Nayak
							 Jai Agarwal
				  
		DEVELOPER COMMENTS : \/\*  for describing code
							 \/\/  for removing code
							 vn	   v - version, n - version number

	*/
	#include<bits/stdc++.h>
	#include "symtab.cpp"
	#include "astgen.cpp"
	void yyerror(const char *s);
	extern int yylineno;
	extern char* yytext;
	using namespace std;
	int yylex();
	// declare yywarp here, if you want to use it
	extern int lineno;
	//ASTNode *ast_root;
	int list_declr_flag = 0;
%}

%union{
    	char char_val;
		int int_val;
		double double_val;
		char* str_val;
}
%token T_INCLUDE T_IDH T_EXPRN T_ARGS T_FUNC_ID T_DEFINE T_INT T_VOID
%token T_FLOAT T_CHAR T_DOUBLE T_LONG T_LINT T_LDOUBLE T_LLINT T_UNSIGNED T_RETURN
%token T_IDENTIFIER T_INTEGER_VAL T_FLOAT_VAL T_ADDEQ T_MINEQ T_MULEQ T_DIVEQ T_FOR T_IF T_ELSE T_LTEQ
%token T_GTEQ T_NEQEQ T_EQEQ T_OROR T_ANDAND T_OR T_AND T_XOR T_LRSHIFT T_LLSHIFT
%token T_WHILE T_MAIN T_STRING T_STRUCT T_CLASS T_PRIVATE T_PUBLIC T_PROTECTED T_ADDADD T_MINMIN
%token T_STRING_VAL T_CHAR_VAL T_COUT T_CIN

%type <str_val> T_INT
%type <str_val> T_VOID
%type <str_val> T_FLOAT
%type <str_val> T_CHAR
%type <str_val> T_STRING
%type <str_val> T_DOUBLE
%type <str_val>	T_IDENTIFIER
%type <str_val> var_type

%type <int_val> expression
%type <int_val> simple_expression
%type <int_val> additive_expression
%type <int_val> term
%type <int_val>	factor
%type <int_val> T_INTEGER_VAL

%left '(' ')' '+' '*' '-' '/'

%start P	

%%

P : program			
					{ 	
						// AST code
						//push_into_AST(ast_root, "P");
						//move_to_next_level("P");
						move_to_next_level("program");
					}
  ;

program	
		: external_declaration	
					{
						// AST code
						move_to_next_level("external_declaration");
					}
		| program external_declaration
					{
						//AST code
						move_to_next_level("program external_declaration");
					}
		;

external_declaration 
		: header_stmt
					{
						// AST code
						move_to_next_level("header_stmt");
					}
		| global_stmt
					{
						// AST code
						move_to_next_level("global_stmt");
					}
		| main_fun
					{
						// AST code
						move_to_next_level("main_fun");
					}
		;
					 
header_stmt 
		: '#' T_INCLUDE '<' T_IDH '>'
					{
						//AST code
						push_into_AST("#");
						push_into_AST("include");
						push_into_AST("<");
						push_into_AST("header file");
						push_into_AST(">");
					}
        | '#' T_INCLUDE  T_IDH
					{
						//AST code
						push_into_AST("#");
						push_into_AST("include");
						push_into_AST("header file");
					}
		;

global_stmt 
		: declaration_statement
					{
						// AST code
						move_to_next_level("declaration");
					}
		| fun_declr
					{
						// AST code
						move_to_next_level("fun_declr");
					}
		| user_defined_ds
					{
						// AST code
						move_to_next_level("user_defined_ds");
					}
		;
			
main_fun 
		: subroutine T_INT T_MAIN '(' ')' compound_stmt
					{
						// AST code
						push_into_AST("subroutine");
						push_into_AST("int");
						push_into_AST("main");
						push_into_AST("(");
						push_into_AST(")");
						push_into_AST("compound_stmt");
					}
	    ;
			
subroutine 
		: %empty {}
		;
		   	
declaration_statement 
		: subroutine var_type list_identifier ';'
					{
						// AST code
						push_into_AST("subroutine");
						push_into_AST("int");
						push_into_AST("main");
						push_into_AST("(");
						push_into_AST(")");
						push_into_AST("compound_stmt");
					}
	    ;
		
list_identifier 
		: list_identifier ',' variable 
					{
						// AST code
						push_into_AST("list_identifier");
						push_into_AST(",");
						push_into_AST("variable");;
					}
		| list_identifier ',' init
					{
						// AST code
						push_into_AST("list_identifier");
						push_into_AST(",");
						push_into_AST("init");;
					}
		| init
					{
						// AST code
						push_into_AST("init");
					}
		| variable
					{
						// AST code
						push_into_AST("variable");
					}
		;
				
variable 
		: T_IDENTIFIER
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
					}
		| T_IDENTIFIER array
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("array");
					}
		;
		 
array 
		: array '[' T_INTEGER_VAL ']'
					{
						// AST code
						push_into_AST("array");
						push_into_AST("[");
						push_into_AST("T_INTEGER_VAL");
						push_into_AST("]");
					}
		| '[' T_INTEGER_VAL ']'
					{
						// AST code
						push_into_AST("[");
						push_into_AST("T_INTEGER_VAL");
						push_into_AST("]");
					}
	  	;
	  
init 
		: var_init
					{
						// AST code
						push_into_AST("var_init");
					}
     	| array_init
					{
						// AST code
						push_into_AST("array_init");
					}
	 	;
	 
var_init 
		: T_IDENTIFIER '=' expression
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("=");
						push_into_AST("expression");
					}
		;
		 
array_init 
		: T_IDENTIFIER array '=' '{' values '}'
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("array");
						push_into_AST("=");
						push_into_AST("{");
						push_into_AST("values");
						push_into_AST("}");
					}
		;
		   
values 
		: values ',' constant
					{
						// AST code
						push_into_AST("values");
						push_into_AST(",");
						push_into_AST("constant");
					}
       	| constant
					{
						// AST code
						push_into_AST("constant");
					}
	   	;
	   
constant 
		: T_INTEGER_VAL
					{
						// AST code
						push_into_AST("T_INTEGER_VAL");
					}
		| T_STRING_VAL
					{
						// AST code
						push_into_AST("T_STRING_VAL");
					}
		| T_CHAR_VAL
					{
						// AST code
						push_into_AST("T_CHAR_VAL");
					}
		| T_FLOAT_VAL
					{
						// AST code
						push_into_AST("T_FLOAT_VAL");
					}
		;
		 
declarator 
		: '(' ')'
					{
						// AST code
						push_into_AST("(");
						push_into_AST(")");
					}
		| '(' params ')'
					{
						// AST code
						push_into_AST("(");
						push_into_AST("params");
						push_into_AST(")");
					}
		;

fun_declr 
		: subroutine var_type T_IDENTIFIER declarator compound_stmt
					{
						// AST code
						push_into_AST("sub_routine");
						push_into_AST("var_type");
						push_into_AST("T_IDENTIFIER");
						push_into_AST("declarator");
						push_into_AST(")");
					}
		;
		  
var_type 
		: T_INT
					{
						// AST code
						push_into_AST("T_INT");
					}
		| T_FLOAT
					{
						// AST code
						push_into_AST("T_FLOAT");
					}
		| T_DOUBLE
					{
						// AST code
						push_into_AST("T_DOUBLE");
					}
		| T_CHAR
					{
						// AST code
						push_into_AST("T_CHAR");
					}
		| T_STRING
					{
						// AST code
						push_into_AST("T_STRING");
					}
		| T_VOID
					{
						// AST code
						push_into_AST("T_VOID");
					}
		;
		 
params_list 
		: T_INT T_IDENTIFIER 
					{
						// AST code
						push_into_AST("T_INT");
						push_into_AST("T_IDENTIFIER");
					}
		| T_FLOAT T_IDENTIFIER 
					{
						// AST code
						push_into_AST("T_FLOAT");
						push_into_AST("T_IDENTIFIER");
					}
		| params_list ',' T_INT T_IDENTIFIER 
					{
						// AST code
						push_into_AST("params_list");
						push_into_AST(",");
						push_into_AST("T_INT");
						push_into_AST("T_IDENTIFIER");
					}
		| params_list ',' T_FLOAT T_IDENTIFIER
					{
						// AST code
						push_into_AST("params_list");
						push_into_AST(",");
						push_into_AST("T_FLOAT");
						push_into_AST("T_IDENTIFIER");
					} 
		;
		 
params 
		: params_list
					{
						// AST code
						push_into_AST("params_list");
					}
	  	| T_VOID
					{
						// AST code
						push_into_AST("T_VOID");
					}
       	;
		 
compound_stmt 
		: start_paren end_paren
					{
						// AST code
						push_into_AST("start_paren");
						push_into_AST("end_paren");
					}
		| start_paren block_item_list end_paren 
					{
						// AST code
						push_into_AST("start_paren");
						push_into_AST("block_item_list");
						push_into_AST("end_paren");
					}
		;
			  
start_paren 
		: '{' {create_new_scope();}
					{
						// AST code
						push_into_AST("{");
					}
		;

end_paren 
		: '}' {exit_scope();}
					{
						// AST code
						push_into_AST("}");
					}
		;
			  
block_item_list 
		: block_item
					{
						// AST code
						push_into_AST("block_item");
					}
		| block_item_list block_item
					{
						// AST code
						push_into_AST("block_item_list");
						push_into_AST("block_item");
					}
		;

block_item 
		: declaration_statement
					{
						// AST code
						push_into_AST("declaration_statement");
					}
		| statement
					{
						// AST code
						push_into_AST("statement");
					}
		;
   
user_defined_ds 
		: class
					{
						// AST code
						push_into_AST("class");
					}
		| structure
					{
						// AST code
						push_into_AST("structure");
					}
		;
				
class 
		: T_CLASS T_IDENTIFIER class_body_stmt ';'
					{
						// AST code
						push_into_AST("T_CLASS");
						push_into_AST("T_IDENTIFIER");
						push_into_AST("class_body");
						push_into_AST(";");
					}
		;

structure 
		: T_STRUCT T_IDENTIFIER struct_body_stmt ';'
					{
						// AST code
						push_into_AST("T_STRUCT");
						push_into_AST("T_IDENTIFIER");
						push_into_AST("struct_body");
						push_into_AST("stmt");
						push_into_AST(";");
					}
		;

class_body_stmt  
		: start_paren end_paren
					{
						// AST code
						push_into_AST("start_paren");
						push_into_AST("end_paren");
					}
		| start_paren class_mems end_paren
					{
						// AST code
						push_into_AST("start_paren");
						push_into_AST("class_mems");
						push_into_AST("end_paren");
					} 
		;
				 
struct_body_stmt  
		: start_paren end_paren
					{
						// AST code
						push_into_AST("start_paren");
						push_into_AST("end_paren");
					}
		| start_paren struct_mems end_paren 
					{
						// AST code
						push_into_AST("start_paren");
						push_into_AST("struct_mems");
						push_into_AST("end_paren");
					} 
		;

struct_mems 
		: struct_mem
					{
						// AST code
						push_into_AST("struct_mem");
					}
		| struct_mems struct_mem
					{
						// AST code
						push_into_AST("struct_mems");
						push_into_AST("struct_mem");
					}
		;

class_mems 
		: class_mem
					{
						// AST code
						push_into_AST("class_mem");
					}
		| class_mems class_mem
					{
						// AST code
						push_into_AST("class_mems");
						push_into_AST("class_mem");
					}
		;

struct_mem 
		: declaration_statement
					{
						// AST code
						push_into_AST("declaration_statement");
					}
		| fun_declr
					{
						// AST code
						push_into_AST("fun_declr");
					}
		;

class_mem	
		: subroutine var_type class_var_declaration ';'
					{
						// AST code
						push_into_AST("subroutine");
						push_into_AST("var_type");
						push_into_AST("class_var_declaration");
						push_into_AST(";");
					}
		|  fun_declr
					{
						// AST code
						push_into_AST("fun_declr");
					}
		|  access_specifier ':'
					{
						// AST code
						push_into_AST("access_specifier");
						push_into_AST(":");
					}
		;
			
class_var_declaration 
		: T_IDENTIFIER
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
					}
		| class_var_declaration ',' T_IDENTIFIER
					{
						// AST code
						push_into_AST("class_var_declaration");
						push_into_AST(";");
						push_into_AST("T_IDENTIFIER");
					}
		;

access_specifier 
		: T_PRIVATE
					{
						// AST code
						push_into_AST("T_PRIVATE");
					}
        | T_PUBLIC
					{
						// AST code
						push_into_AST("T_PUBLIC");
					}
        | T_PROTECTED
					{
						// AST code
						push_into_AST("T_PROTECTED");
					}
		;
		     
statement 
		: expression_stmt
					{
						// AST code
						push_into_AST("expression_stmt");
					}
		| compound_stmt
					{
						// AST code
						push_into_AST("compound_stmt");
					}
  		| iterative_statement
					{
						// AST code
						push_into_AST("iterative_statement");
					}
  		| selection_statement
					{
						// AST code
						push_into_AST("selection_stmt");
					}
		| input_output_statements
					{
						// AST code
						push_into_AST("input_output_statements");
					}
        | return_stmt
					{
						// AST code
						push_into_AST("return_stmt");
					}
  		;
		  
expression_stmt
    	: ';' 
					{
						// AST code
						push_into_AST(";");
					}
    	| expression ';'
					{
						// AST code
						push_into_AST("expression");
						push_into_AST(";");
					}
    	;

selection_statement 
		: T_IF '(' expression ')' statement
					{
						// AST code
						push_into_AST("T_IF");
						push_into_AST("(");
						push_into_AST("expression");
						push_into_AST(")");
						push_into_AST("statement");
					}
        | T_IF '(' expression ')' statement T_ELSE statement
					{
						// AST code
						push_into_AST("T_IF");
						push_into_AST("(");
						push_into_AST("expression");
						push_into_AST(")");
						push_into_AST("T_ELSE");
						push_into_AST("statement");
					}
        ;
					
iterative_statement 
		: for_loop
					{
						// AST code
						push_into_AST("for_loop");
					}
		| while_loop
					{
						// AST code
						push_into_AST("while_loop");
					}
  		;

for_loop 
		: T_FOR '(' for_assgn_stmt ';' expression ';' unary_exprn ')' statement
					{
						// AST code
						push_into_AST("T_FOR");
						push_into_AST("(");
						push_into_AST("for_assgn_stmt");
						push_into_AST(";");
						push_into_AST("expression");
						push_into_AST(";");
						push_into_AST("unary_exprn");
						push_into_AST(")");
						push_into_AST("statement");
					}
  	   	;

for_assgn_stmt 
		: var_type for_decl_stmt
					{
						// AST code
						push_into_AST("var_type");
						push_into_AST("for_decl_stmt");
					}
		| assignment_expression
					{
						// AST code
						push_into_AST("assignment_expression");
					}
		;

for_decl_stmt 
		: T_IDENTIFIER '=' expression
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("=");
						push_into_AST("expression");
					} 
		| for_decl_stmt ',' T_IDENTIFIER '=' expression
					{
						// AST code
						push_into_AST("for_decl_stmt");
						push_into_AST(",");
						push_into_AST("T_IDENTIFIER");
						push_into_AST("=");
						push_into_AST("expression");
					}
		;

while_loop 
		: T_WHILE '(' expression ')' statement
					{
						// AST code
						push_into_AST("T_WHILE");
						push_into_AST("(");
						push_into_AST("expression");
						push_into_AST(")");
						push_into_AST("statement");
					} 
  		;
		   
return_stmt 
		: T_RETURN ';'
					{
						// AST code
						push_into_AST("T_RETURN");
						push_into_AST(";");
					}
		| T_RETURN expression ';'
					{
						// AST code
						push_into_AST("T_RETURN");
						push_into_AST("expression");
						push_into_AST(";");
					}
		;
			
expression 
		: assignment_expression
					{
						// AST code
						push_into_AST("assignment_expression");
					}
		| simple_expression
					{
						// AST code
						push_into_AST("simple_expression");
					}
		;
		   
assignment_expression 
		: T_IDENTIFIER '=' expression
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("=");
						push_into_AST("expression");
					}
	    | unary_exprn
					{
						// AST code
						push_into_AST("unary_exprn");
					}
		;
					  
unary_exprn 
		: T_ADDADD T_IDENTIFIER
					{
						// AST code
						push_into_AST("T_ADDADD");
						push_into_AST("T_IDENTIFIER");
					}
		| T_MINMIN T_IDENTIFIER
					{
						// AST code
						push_into_AST("T_MINMIN");
						push_into_AST("T_IDENTIFIER");
					}
        | postfix_expression
					{
						// AST code
						push_into_AST("postfix_expression");
					}
        | T_IDENTIFIER uop_shorthd expression
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("uop_shorthd");
						push_into_AST("expression");
					}
		;
			
postfix_expression 
		: T_IDENTIFIER T_ADDADD
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("T_ADDADD");
					}
		| T_IDENTIFIER T_MINMIN
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("T_MINMIN");
					}
		;

uop_shorthd  
		: T_ADDEQ
					{
						// AST code
						push_into_AST("T_ADDEQ");
					}
        | T_MINEQ
					{
						// AST code
						push_into_AST("T_MINEQ");
					}
        | T_MULEQ
					{
						// AST code
						push_into_AST("T_MULEQ");
					}
        | T_DIVEQ
					{
						// AST code
						push_into_AST("T_DIVEQ");
					}
		;
			 
simple_expression 
		: additive_expression
					{
						// AST code
						push_into_AST("additive_expression");
					}
		| additive_expression relop additive_expression
					{
						// AST code
						push_into_AST("additive_expression");
						push_into_AST("relop");
						push_into_AST("additive_expression");
					}
		| additive_expression logop additive_expression
					{
						// AST code
						push_into_AST("additive_expression");
						push_into_AST("logop");
						push_into_AST("additive_expression");
					}
		| additive_expression bitop additive_expression
					{
						// AST code
						push_into_AST("additive_expression");
						push_into_AST("bitop");
						push_into_AST("additive_expression");
					}
		;
				  
bitop 
		: T_OR
					{
						// AST code
						push_into_AST("T_OR");
					}
		| T_AND
					{
						// AST code
						push_into_AST("T_AND");
					}
		| T_XOR
					{
						// AST code
						push_into_AST("XOR");
					}
	  	| T_LRSHIFT
					{
						// AST code
						push_into_AST("T_LRSHIFT");
					}
	  	| T_LLSHIFT
					{
						// AST code
						push_into_AST("T_LLSHIFT");
					}
	  	;
				  
relop 
		: '<'
					{
						// AST code
						push_into_AST("<");
					}
      	| '>'
					{
						// AST code
						push_into_AST("<");
					}
	  	| T_LTEQ
					{
						// AST code
						push_into_AST("T_LTEQ");
					}
	  	| T_GTEQ
					{
						// AST code
						push_into_AST("T_GTEQ");
					}
	  	| T_NEQEQ
					{
						// AST code
						push_into_AST("T_NEQEQ");
					}
	  	| T_EQEQ
					{
						// AST code
						push_into_AST("T_EQEQ");
					}
	  	;

logop 
		: T_OROR
					{
						// AST code
						push_into_AST("T_OROR");
					}
	  	| T_ANDAND
					{
						// AST code
						push_into_AST("T_ANDAND");
					}
	  	;
	  
additive_expression 
		: term
					{
						// AST code
						push_into_AST("term");
					}
		| additive_expression '+' term
					{
						// AST code
						push_into_AST("additive_expression");
						push_into_AST("+");
						push_into_AST("term");
					}
		| additive_expression '-' term
					{
						// AST code
						push_into_AST("additive_expression");
						push_into_AST("-");
						push_into_AST("term");
					}
		| '+' additive_expression %prec '*'
					{
						// AST code
						push_into_AST("+");
						push_into_AST("additive_expression");
						push_into_AST("*");
					}
		| '-' additive_expression %prec '*'
					{
						// AST code
						push_into_AST("-");
						push_into_AST("additive_expression");
						push_into_AST("*");
					}
		;

term 
		: factor
					{
						// AST code
						push_into_AST("factor");
					}
	 	| term '*' factor
					{
						// AST code
						push_into_AST("term");
						push_into_AST("*");
						push_into_AST("factor");
					}
     	| term '/' factor
					{
						// AST code
						push_into_AST("term");
						push_into_AST("/");
						push_into_AST("factor");
					}
  	 	;

factor 
		: '(' expression ')'
					{
						// AST code
						push_into_AST("(");
						push_into_AST("expression");
						push_into_AST(")");
					}
	   	| T_IDENTIFIER
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
					}
	   	| call
					{
						// AST code
						push_into_AST("call");
					}
	   	| T_INTEGER_VAL
					{
						// AST code
						push_into_AST("T_INTEGER_VAL");
					}
	   	| T_FLOAT_VAL
					{
						// AST code
						push_into_AST("T_FLOAT_VAL");
					}
	   	| T_STRING_VAL
					{
						// AST code
						push_into_AST("T_STRING_VAL");
					}
	   	| T_CHAR_VAL
					{
						// AST code
						push_into_AST("T_CHAR_VAL");
					}
	   	;

call 	
		: T_IDENTIFIER '(' ')'
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("(");
						push_into_AST(")");
					}
	 	| T_IDENTIFIER '(' args ')'
					{
						// AST code
						push_into_AST("T_IDENTIFIER");
						push_into_AST("(");
						push_into_AST("args");
						push_into_AST(")");
					}
	 	;

args 	
		: expression
					{
						// AST code
						push_into_AST("expression");
					}
	 	| expression ',' args
					{
						// AST code
						push_into_AST("expression");
						push_into_AST(",");
						push_into_AST("args");
					}
	 	;

input_output_statements 
		: T_COUT T_LLSHIFT expression ';'
					{
						// AST code
						push_into_AST("T_COUT");
						push_into_AST("T_LLSHIFT");
						push_into_AST("args");
					}
		| T_CIN T_LRSHIFT T_IDENTIFIER ';'
					{
						// AST code
						push_into_AST("T_CIN");
						push_into_AST("T_LRSHIFT");
						push_into_AST("T_IDENTIFIER");
						push_into_AST(";");
					}
		;

%%

void yyerror(const char *str)
{
	printf("line no :%d  %s near %s\n", yylineno, str, yytext );
}

/* if you need yywrap, declare it here */

extern FILE *yyin;

int main(int argc, char *argv[])
{

    ++argv, --argc;  /* Skip over program name. */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }

    if(yyparse() == 0) { printf("Parsing successful!\n");}
	
	// symbol table traversal
	LevelOrderTraversal(root);

	// abstract syntax tree traversal
	LevelOrderTraversalAST(c_root);
    return 0;
}
