%{
	/*
		AUTHORS 	: 		 Hrishikesh S.
							 Adarsha Nayak
							 Jai Agarwal
				  
		DEVELOPER COMMENTS : /*  	for describing code
							 //    	for removing code
							 vn		 v - version, n - version number

	*/
	
	#include<bits/stdc++.h>
	#include "symtab.cpp"
	
	void yyerror(const char *s);
	extern int yylineno;
	extern char* yytext;
	
	using namespace std;
	
	int yylex();
	//int yywrap();
	extern int lineno;
	string type;
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

%%

program		
			:	external_declr 
			|   external_declr program
			|   main_fun { cout << type; }
			;

external_declr		
			:	header_stmt
			| 	global_stmt
			;

global_stmt 
			: fun_declr
            | user_defined_ds
            | declaration_statement ';'
			;

fun_declr 	
			: var_type T_IDENTIFIER { create_new_scope(); } declarator compound_stmt
			;

compound_stmt 
			: '{' '}'
			| '{' block_items '}' { exit_scope(); }
			;

block_items 
			: block_item
			| block_items block_item
			;

block_item 
			: statement
			;

declarator 
			: '(' ')'
			| '(' params ')'
			;

user_defined_ds 
			: class
			| structure
			;

class 		
			: T_CLASS T_IDENTIFIER body_stmt ';'
			;

structure 
			: T_STRUCT T_IDENTIFIER body_stmt ';'
			;

body_stmt  
			: '{' '}'
			| '{' { create_new_scope(); } mem_items '}' { exit_scope(); }
			;	

mem_items 	
			: struct_mems
			| class_mems
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
			: declaration_statement ';'
			| fun_declr
			;

class_mem	
			:  var_type class_var_declaration ';'
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

params 
			: var_type T_IDENTIFIER
			| params ',' var_type T_IDENTIFIER
			;

main_fun 
			: T_INT T_MAIN '(' ')' compound_stmt
			;

header_stmt 
			: '#' T_INCLUDE '<' T_IDH '>'
            | '#' T_INCLUDE  T_IDH
			;

statement 
			: declaration_statement ';'
			| assignment_expression ';'
			| expression ';'
			| compound_stmt
			| input_output_statements ';'
			| iterative_statement
			| selection_statement
			| error_statement
			| return_stmt
			;

input_output_statements 
			: T_COUT T_LLSHIFT expression
			| T_CIN T_LRSHIFT T_IDENTIFIER
			;

return_stmt 
			: T_RETURN ';'
		    | T_RETURN expression ';'
			;

iterative_statement 
			: for_loop
			| while_loop
			;

for_loop 
			: T_FOR '(' { create_new_scope(); } for_assgn_stmt ';' expression ';' unary_exprn ')' statement
			;

for_assgn_stmt 
			: var_type for_decl_stmt
			| assignment_expression
			;

for_decl_stmt 
			: T_IDENTIFIER '=' expression {declare=0;}
			| for_decl_stmt ',' T_IDENTIFIER '=' expression
			;

while_loop 
			: T_WHILE '(' expression ')' statement
			;

declaration_statement 
			: var_type list_identifier { cout << "type is " << $1 << endl;}
	        ;

list_identifier 
			: T_IDENTIFIER { /*cout<<"identifier is "<<$1<<endl;
								 string s($1);
								 cout << "HELLO " << s <<endl; 
								 size_t pos = s.find(";");
    							 s = s.substr(0,pos);
								 pos = s.find(",");
    							 s = s.substr(0,pos);
								 pos = s.find(";");
    							 s = s.substr(0,pos);
								 cout << "HELLO " << s <<endl;
								 insert_entry(s, curr_scope, type,"0", 0, 0);*/{declare=0;}}
			| array_declr
			| T_IDENTIFIER '=' expression { cout<<"identifier is "<< $1 << "expression is "<< $3 <<endl; 
											 	/*string s($1); 
												cout << "HELLO " << s <<endl; 
												size_t pos = s.find("=");
    											s = s.substr(0,pos);
												pos = s.find(",");
    							 				s = s.substr(0,pos);
												pos = s.find(";");
    							 				s = s.substr(0,pos);
												cout << "HELLO " << s <<endl;
												insert_entry(s, curr_scope, type,to_string($3), 0, 0);*/ {declare=0;}}
			| list_identifier ',' T_IDENTIFIER { cout<<"identifier is "<< $3 << endl; 
													 /*string s($3);
													 cout << "HELLO " << s <<endl; 
													 size_t pos = s.find("=");
    												 s = s.substr(0,pos);
													 pos = s.find(",");
    							 					 s = s.substr(0,pos);
													 pos = s.find(";");
    							 					 s = s.substr(0,pos);
													 cout << "HELLO " << s <<endl;
													 insert_entry(s, curr_scope, type,"0", 0, 0);*/{declare=0;}}

			| list_identifier ',' T_IDENTIFIER '=' expression  { cout << "identifier is " << $3 << "expression is "<<$5<<endl;
																   	 string s($3);
																	 cout << "HELLO " << s <<endl; 
																	 size_t pos = s.find("=");
    												 				 s = s.substr(0,pos);
																	 cout << "HELLO " << s <<endl;
																	 //insert_entry(s, curr_scope,type,to_string($5), 0, 0);
																}
			| list_identifier ',' array_declr
			;

array_declr 
			: T_IDENTIFIER '[' T_INTEGER_VAL ']'
			| array_declr '[' T_INTEGER_VAL ']'
			;

selection_statement 
			: T_IF '(' expression ')' statement
			| T_IF '(' expression ')' statement T_ELSE statement
			;


assignment_expression 
			: T_IDENTIFIER '=' expression 
			| assignment_expression ',' T_IDENTIFIER '=' expression
			| T_IDENTIFIER '=' T_CHAR
			| T_IDENTIFIER '=' T_STRING
			| assignment_expression ',' T_IDENTIFIER '=' T_CHAR
			| assignment_expression ',' T_IDENTIFIER '=' T_STRING
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

expression 
			: assignment_expression  
			| simple_expression {$$=$1;}
			;


simple_expression 
			: additive_expression {$$=$1;}
			| additive_expression relop additive_expression
			| additive_expression logop additive_expression
			;

additive_expression 
			: additive_expression '+' term {$$=$1+$3;}
			| additive_expression '-' term {$$=$1-$3;}
			| additive_expression bitop term
			| term {$$=$1;}
			;

term 
			: term '*' factor {$$=$1*$3;}
			| term '/' factor {$$=$1/$3;}
			| factor {$$=$1;}
			;

factor 
			: '(' expression ')' {$$=$2;}
			| call
			| T_INTEGER_VAL  {$$=$1;}
			| T_STRING_VAL
			| T_CHAR_VAL
			| T_IDENTIFIER
			;

call 
			: T_IDENTIFIER '(' ')'
			| T_IDENTIFIER '(' args ')'
			;

args 		
			: expression
			| expression ',' args
			;

relop 		: '<'
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

bitop 		: T_OR
			| T_AND
			| T_XOR
			| T_LRSHIFT
			| T_LLSHIFT
			;

var_type 
			: T_INT 				{/*type = "int";*/		{declare=1;}}
			| T_FLOAT 				{/*type = "float";*/	{declare=1;}}
			| T_CHAR 				{/*type = "char";*/		{declare=1;}}
			| T_DOUBLE 				{/*type = "double";*/	{declare=1;}}
			| T_STRING 				{/*type = "string";*/	{declare=1;}}
			| T_VOID 				{/*type = "void";*/		{declare=1;}}
		 ;



error_statement 
			: T_IF '(' expression statement		{cout << "missing closing bracket at line "; exit(0);}
			;
%%

void yyerror(const char *str){
	printf("line no :%d  %s near %s\n", yylineno, str, yytext );
}

//int yywrap()
//{
	//return 1;
//}

extern FILE *yyin;

/* Input should passed an argument */
int main(int argc, char *argv[]){

    ++argv, --argc;  /* Skip over program name. */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }

    if(yyparse() == 0) { printf("Parsing successful!\n");}

	//print_symbolTable();
	LevelOrderTraversal(root);
    return 0;
}
