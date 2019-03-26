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

P : program			{ 	
						// AST code
						ast_root = newASTNode("P"); 
						push_into_AST(ast_root, "program");
						std::cout << "AST " << ast_root->symbol << std::endl; 
					}
  ;

program	
		: external_declaration	
					{
						// AST code
						//std::cout << "AST " << ast_root->symbol << std::endl;
					}
		| program external_declaration
		;

external_declaration 
		: header_stmt
		| global_stmt
		| main_fun
		;
					 
header_stmt 
		: '#' T_INCLUDE '<' T_IDH '>'
        | '#' T_INCLUDE  T_IDH
		;

global_stmt 
		: declaration_statement 
		| fun_declr
		| user_defined_ds
		;
			
main_fun 
		: subroutine T_INT T_MAIN '(' ')' compound_stmt
	    ;
			
subroutine 
		: %empty {}
		;
		   	
declaration_statement 
		: subroutine var_type list_identifier ';'
	    ;
		
list_identifier 
		: list_identifier ',' variable 
		| list_identifier ',' init
		| init
		| variable
		;
				
variable 
		: T_IDENTIFIER
		| T_IDENTIFIER array
		;
		 
array 
		: array '[' T_INTEGER_VAL ']'
		| '[' T_INTEGER_VAL ']'
	  	;
	  
init 
		: var_init
     	| array_init
	 	;
	 
var_init 
		: T_IDENTIFIER '=' expression
		;
		 
array_init 
		: T_IDENTIFIER array '=' '{' values '}'
		;
		   
values 
		: values ',' constant
       	| constant
	   	;
	   
constant 
		: T_INTEGER_VAL
		| T_STRING_VAL
		| T_CHAR_VAL
		| T_FLOAT_VAL
		;
		 
declarator 
		: '(' ')'
		| '(' params ')'
		;

fun_declr 
		: subroutine var_type T_IDENTIFIER declarator compound_stmt
		;
		  
var_type 
		: T_INT 
		| T_FLOAT
		| T_DOUBLE
		| T_CHAR
		| T_STRING
		| T_VOID
		;
		 
params_list 
		: T_INT T_IDENTIFIER 
		| T_FLOAT T_IDENTIFIER 
		| params_list ',' T_INT T_IDENTIFIER 
		| params_list ',' T_FLOAT T_IDENTIFIER 
		;
		 
params 
		: params_list
	  	| T_VOID
       	;
		 
compound_stmt 
		: start_paren end_paren
		| start_paren block_item_list end_paren 
		;
			  
start_paren 
		: '{' {create_new_scope();}
		;

end_paren 
		: '}' {exit_scope();}
		;
			  
block_item_list 
		: block_item
		| block_item_list block_item
		;

block_item 
		: declaration_statement
		| statement
		;
   
user_defined_ds 
		: class
		| structure
		;
				
class 
		: T_CLASS T_IDENTIFIER class_body_stmt ';'
		;

structure 
		: T_STRUCT T_IDENTIFIER struct_body_stmt ';'
		;

class_body_stmt  
		: start_paren end_paren
		| start_paren class_mems end_paren 
		;
				 
struct_body_stmt  
		: start_paren end_paren
		| start_paren struct_mems end_paren 
		;

struct_mems 
		: struct_mem
		| struct_mems struct_mem
		;

class_mems 
		: class_mem
		| class_mems class_mem
		;

struct_mem 
		: declaration_statement
		| fun_declr
		;

class_mem	
		: subroutine var_type class_var_declaration ';'
		|  fun_declr
		|  access_specifier ':'
		;
			
class_var_declaration 
		: T_IDENTIFIER
		| class_var_declaration ',' T_IDENTIFIER
		;

access_specifier 
		: T_PRIVATE
        | T_PUBLIC
        | T_PROTECTED
		;
		     
statement 
		: expression_stmt
		| compound_stmt
  		| iterative_statement
  		| selection_statement
		| input_output_statements
        | return_stmt
  		;
		  
expression_stmt
    	: ';' 
    	| expression ';'
    	;

selection_statement 
		: T_IF '(' expression ')' statement
        | T_IF '(' expression ')' statement T_ELSE statement
        ;
					
iterative_statement 
		: for_loop
		| while_loop
  		;

for_loop 
		: {} T_FOR '(' {} for_assgn_stmt ';' {} expression ';' {} unary_exprn ')' {} statement
  	   	;

for_assgn_stmt 
		: var_type for_decl_stmt
		| assignment_expression
		;

for_decl_stmt 
		: T_IDENTIFIER '=' expression 
		| for_decl_stmt ',' T_IDENTIFIER '=' expression
		;

while_loop 
		: T_WHILE '(' expression ')' statement
  		;
		   
return_stmt 
		: T_RETURN ';'
		| T_RETURN expression ';'
		;
			
expression 
		: assignment_expression
		| simple_expression
		;
		   
assignment_expression 
		: T_IDENTIFIER '=' expression
	    | unary_exprn
		;
					  
unary_exprn 
		: T_ADDADD T_IDENTIFIER
		| T_MINMIN T_IDENTIFIER
        | postfix_expression
        | T_IDENTIFIER uop_shorthd expression
		;
			
postfix_expression 
		: T_IDENTIFIER T_ADDADD
		| T_IDENTIFIER T_MINMIN
		;

uop_shorthd  
		: T_ADDEQ
        | T_MINEQ
        | T_MULEQ
        | T_DIVEQ
		;
			 
simple_expression 
		: additive_expression
		| additive_expression relop additive_expression
		| additive_expression logop additive_expression
		| additive_expression bitop additive_expression
		;
				  
bitop 
		: T_OR
		| T_AND
		| T_XOR
	  	| T_LRSHIFT
	  	| T_LLSHIFT
	  	;
				  
relop 
		: '<'
      	| '>'
	  	| T_LTEQ
	  	| T_GTEQ
	  	| T_NEQEQ
	  	| T_EQEQ
	  	;

logop 
		: T_OROR
	  	| T_ANDAND
	  	;
	  
additive_expression 
		: term
		| additive_expression '+' term
		| additive_expression '-' term
		| '+' additive_expression %prec '*'
		| '-' additive_expression %prec '*'
		;

term 
		: factor
	 	| term '*' factor
     	| term '/' factor
  	 	;

factor 
		: '(' expression ')'
	   	| T_IDENTIFIER
	   	| call
	   	| T_INTEGER_VAL
	   	| T_FLOAT_VAL
	   	| T_STRING_VAL
	   	| T_CHAR_VAL
	   	;

call 	
		: T_IDENTIFIER '(' ')'
	 	| T_IDENTIFIER '(' args ')'
	 	;

args 	
		: expression
	 	| expression ',' args
	 	;

input_output_statements 
		: T_COUT T_LLSHIFT expression ';'
		| T_CIN T_LRSHIFT T_IDENTIFIER ';'
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
	LevelOrderTraversalAST(ast_root);
    return 0;
}
