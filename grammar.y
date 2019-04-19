%{
/*
		C++ Compiler		
		Written using C++14, Lex & Yacc
		AUTHORS 	: 		 Hrishikesh S.
							 Adarsha Nayak
							 Jai Agarwal
				  
		DEVELOPER COMMENTS : \/\/  for describing code.
							 \/\*  for removing code or commenting the code out.
							 The above notations are in regex.
							 Do not change the format of writing the code.

*/
	#include <bits/stdc++.h>
	#include "symtab.cpp"
	#include "astgen.cpp"
	// flags for AST
	// if 'if' is detected
	int if_cond_flag = 0;
	// int a = 10;
	int declare_and_assign_flag = 0;
	int nested_flag = 0;
	// if 'while' is detected
	int while_flag = 0;
	// if 'for' is detected
	int for_flag = 0;
	typedef struct EXPRN{
		char *value;
		int type;
	} EXPRN;
	
	typedef struct DECLR{
		char *id;
		EXPRN *exprn;
	} DECLR;
	
	void yyerror(const char *s);
	extern int yylineno;
	extern char* yytext;
	
	using namespace std;
	
	int yylex();
	extern int lineno;
	
	int list_declr_flag = 0;
	int type;
	
	int iset=0,fset=0,sset=0,cset=0;
	
	void reset_globals();
	void check_exists(char* str, int a);
	
	stack <DECLR*> st;
	string value = "", id = "";
%}

/*
struct valtypes{
	char cval;
	int ival;
	float fval;
	char* sval;
} valtypes;
*/


%union{
    	char cval;
		int ival;
		float fval;
		char *sval;
		struct EXPRN *exprn;
		struct DECLR *declr;
		/*
		valtypes *allval;
		*/		
}

%token <sval> T_INCLUDE T_IDH T_TYPE T_RETURN T_COUT T_CIN
%token <sval> T_IDENTIFIER T_ADDEQ T_MINEQ T_MULEQ T_DIVEQ T_FOR T_IF T_ELSE T_LTEQ
%token <sval> T_GTEQ T_NEQEQ T_EQEQ T_OROR T_ANDAND T_OR T_AND T_XOR T_LRSHIFT T_LLSHIFT
%token <sval> T_WHILE T_MAIN T_STRING T_STRUCT T_CLASS T_PRIVATE T_PUBLIC T_PROTECTED T_ADDADD T_MINMIN
%token <sval> T_STRING_VAL 
%token <sval> T_CHAR_VAL 
%token <sval> T_INTEGER_VAL 
%token <sval> T_FLOAT_VAL

%type <exprn> factor term additive_expression simple_expression expression expression_stmt 
%type <declr> var_init init variable

%left '(' ')' '+' '*' '-' '/'

%start P

%%

P 
		: program
  		;

program	
		: external_declaration
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
		| statement
		;
			
main_fun 
		: T_TYPE T_MAIN '(' ')' compound_stmt
	    ;
			
/*
type 
		: T_TYPE 
					{ 
						if(strcmp($1,"int")==0) type=1;
                		else if(strcmp($1,"float")==0) type=2;
			    		else if(strcmp($1,"string")==0) type=3;
			 		}
	 ;
*/
		   
			
declaration_statement 
		: T_TYPE list_identifier ';' 
					{
						// AST
						std::cout << "######AST : declaration_statement Type " << $1 << std::endl;

						print_stack_elements();

						value = std::string($1);
						//std::cout << "This is printed first" << std::endl;
						S_ast.push_front(make_ast_leaf(value));
						print_stack_elements();
						std::string op = "DECLR_STAT";
						// if input is 'int a = 10;' and inside loop
						if(declare_and_assign_flag == 1){
							declare_and_assign_branch(if_cond_flag, for_flag, while_flag);
						}
						/*
						if(declare_and_assign_flag == 1 && if_cond_flag != 1){
							declare_and_assign_branch();
						}
						*/
						// if input is int a=10 not in if
						/*
						else if(declare_and_assign_flag == 1 && if_cond_flag == 0){
							declare_assign_node_creation();				
						}
						*/
						else if(declare_and_assign_flag == 0 && (if_cond_flag > 0 || for_flag > 0 || while_flag > 0)){
							// declaration but not assigned
							std::cout << "######STATEMENT IN IF LOOP" << std::endl;
							general_declaration_in_loop();
						}
						// if input is int a=10 not in if
						else if(declare_and_assign_flag == 1 && for_flag > 0){
							std::cout << "######FUDGE" << std::endl;
							declare_assign_node_creation();				
						}
						// if declare_and_assign flag == 0
						else{
							std::cout << "######ELSE PATH" << std::endl;
							std::cout << declare_and_assign_flag << " " << if_cond_flag << std::endl;
							std::cout << for_flag << " " << while_flag << std::endl;
							ast_node *central_node = central_node_creation(op);
							syn_root->children.push_back(central_node);
						}
						declare_and_assign_flag = 0;
						std::cout << "######AST : " << ast_root->symbol << std::endl;								
						// SYMTAB
						while(!st.empty()){
							DECLR *temp = st.top();
							st.pop();
							int t=0;
							if(strcmp("int",$1)==0)
								t=1;
							else if(strcmp("float",$1)==0)
								t=2;
							else if(strcmp("string",$1)==0)
								t=3;
							char *id = temp->id;
							insert(id,strlen(id),t,yylineno);
							if(temp->exprn!=NULL){
								EXPRN *e = temp->exprn;
								int t2 = e->type;
								if (((t==1)||(t==2))&&(t2==3)){
									std::cout<<"Type mismatch at "<<yylineno<<std::endl;
									exit(0);
								}

								auto itr = (current_scope_node->symbolTable).find(id);
								if(t==1){
									(itr->second).st_ival = atoi(e->value);
								}
								else if(t==2){
									(itr->second).st_fval = atof(e->value);
								}
							}
								
						}
					}
		;
		
list_identifier 
		: list_identifier ',' variable 
					{ 
						st.push($3); 
					}
		| list_identifier ',' init 
					{ 
						st.push($3); 
					}
		| init 		{ 
						st.push($1); 
					}
		| variable 
					{ 
						st.push($1); 
					}
		;
				
variable 
		: T_IDENTIFIER 
					{
						//SYMTAB
						check_exists($1,1); 
						DECLR *temp = (DECLR*) malloc(sizeof(DECLR));
						temp->id = (char*) malloc(sizeof(char)*(strlen($1)+1));
						strcpy(temp->id,$1);
						temp->exprn = NULL;
						$$ = temp;
						//AST
						std::cout << "######AST : List identifier "<< $1 << std::endl;
						id = $1;
						S_ast.push_front(make_ast_leaf(id));					
					}
		 | T_IDENTIFIER array 
					{
						check_exists($1,1); 
						DECLR *temp = (DECLR*) malloc(sizeof(DECLR));
						temp->id = (char*) malloc(sizeof(char)*(strlen($1)+1));
						strcpy(temp->id,$1);
						temp->exprn = NULL;
						$$ = temp;
					}
		 ;
		 
array 
		: array '[' T_INTEGER_VAL ']'
	  	| '[' T_INTEGER_VAL ']'
	  	;
	  
init 
		: var_init 
					{ 
						$$ = $1; 
					}
     	| array_init
	 	;
	 
var_init 
		: T_IDENTIFIER '=' expression 
					{ 
						//SYMTAB
						check_exists($1,1); 
						/*
						insert($1,strlen($1),type,yylineno);
						*/
						DECLR *temp = (DECLR*) malloc(sizeof(DECLR));
						temp->id = (char*) malloc(sizeof(char)*(strlen($1)+1));
						strcpy(temp->id,$1);
						temp->exprn = $3;
						$$ = temp;
						//AST
						std::cout << "######AST : var_init Assignment" << std::endl;
						value = std::string($1);
						S_ast.push_front(make_ast_leaf(value));
						std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						print_stack_elements();
						declare_and_assign_flag = 1;
						std::cout << "######DECLARE & ASSIGN FLAG set to 1" << std::endl;
						/*std::string op = "=";
						ast_node *central_node = central_node_creation(op);
						syn_root->children.push_back(central_node);
						std::cout << "AST : " << ast_root->symbol << std::endl;*/
					}
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
					{
						value = std::string($1);
						S_ast.push_front(make_ast_leaf(value));
					}
		| T_STRING_VAL
					{
						value = std::string($1);
						S_ast.push_front(make_ast_leaf(value));
					}
		| T_CHAR_VAL
					{
						value = std::string($1);
						S_ast.push_front(make_ast_leaf(value));
					}
		| T_FLOAT_VAL
					{
						value = std::string($1);
						S_ast.push_front(make_ast_leaf(value));
					}
		;
		 
declarator 
		: '(' ')'
		| '(' params ')'
		;

fun_declr 
		: T_TYPE T_IDENTIFIER declarator compound_stmt 
					{ 
						insert($2,strlen($2),4,yylineno); 
					}
		;
		  
/*
var_type 
		: T_INT 
		| T_FLOAT
		| T_DOUBLE
		| T_CHAR
		| T_STRING
		| T_VOID
		;
*/
		 
/*
R_TYPE 
		: T_TYPE
	   	| T_VOID
	   	;
*/
		 
params_list 
		: T_TYPE T_IDENTIFIER 
					{ 
						//SYMTAB
						insert($2,strlen($2),1,yylineno);
						//AST						
						value = $1;
						S_ast.push_front(make_ast_leaf(value));
					}
		| params_list ',' T_TYPE T_IDENTIFIER  
					{ 
						//SYMTAB
						insert($4,strlen($4),1,yylineno);
						//AST
						/*
						value = $1;
						S_ast.push_front(make_ast_leaf(value)); 
						*/					
					}
		;
		 
params 
		: params_list
       	;
		 
compound_stmt 
		: start_paren end_paren
		| start_paren block_item_list end_paren 
		;
			  
start_paren 
		: '{' 
					{
						create_new_scope();
					}
		;

end_paren 
		: '}' 
					{
						exit_scope();
					}
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
		:  T_TYPE class_var_declaration ';'
		|  fun_declr
		|  access_specifier ':'
		;
			
class_var_declaration 
		: T_IDENTIFIER 
					{ 
						insert($1,strlen($1),type,yylineno); 
					}
		| class_var_declaration ',' T_IDENTIFIER 
					{ 
						insert($3,strlen($3),type,yylineno); 
					}
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

if_set_flag
		: 			{ 
						level++;
						if_cond_flag = level;
						id = "if";
						S_ast.push_front(make_ast_leaf(id)); 
					}
		;

else_stmt
		:
					{
						id = "else";
						S_ast.push_front(make_ast_leaf(id)); 
					}
		;

selection_statement 
		: T_IF if_set_flag '(' expression ')' statement
					{
						std::cout << "######IF" <<std::endl;
						print_stack_elements();
						//IF_node_create_branch();
						IF_Alternate(if_cond_flag);
						if_cond_flag--;
						print_stack_elements();
					}
        | T_IF if_set_flag '(' expression ')' statement T_ELSE else_stmt statement
					{
						std::cout << "######IF" <<std::endl;
						print_stack_elements();
						else_creation();
						print_stack_elements();
						//IF_node_create_branch();
						IF_Alternate(if_cond_flag);
						if_cond_flag--;
						print_stack_elements();
					}
        ;
					
iterative_statement 
		: for_loop
		| while_loop
  		;

for_set_flag
		: 			{	 
						level++;
						for_flag = level;
						std::string f = "for";
						S_ast.push_front(make_ast_leaf(f)); 
					}
		;

for_loop 
		: T_FOR  for_set_flag '(' for_assgn_stmt ';' {} expression ';' unary_exprn ')' statement
					{
						std::cout << "######AST : FOR LOOP " << std::endl;
						print_stack_elements();
						for_creation(for_flag);
						print_stack_elements();
						for_flag--;
					}
  	   	;

for_assgn_stmt 
		: T_TYPE for_decl_stmt
					{
						std::cout << "######AST : for_assgn_stmt T_TYPE " << $1 << std::endl;
						value = $1;
						S_ast.push_front(make_ast_leaf(value));	
					}
		| assignment_expression
		;

for_decl_stmt 
		: T_IDENTIFIER '=' expression 
					{
						//AST
						std::cout << "######AST : for_decl_stmt T_IDENTIFIER " << $1 << std::endl;
						value = std::string($1);
						S_ast.push_front(make_ast_leaf(value));						
					} 
		| for_decl_stmt ',' T_IDENTIFIER '=' expression
		;

while_set_flag
		: 			{	
						level++;
						while_flag = level;
						std::string f = "while";
						S_ast.push_front(make_ast_leaf(f)); 
					}
		;

while_loop 
		: T_WHILE while_set_flag '(' expression ')' statement
					{
						std::cout << "######AST : FOR LOOP " << std::endl;
						print_stack_elements();
						while_creation(while_flag);
						print_stack_elements();
						while_flag--;
					}
  		;
		   
return_stmt 
		: T_RETURN ';' 
					{
						//AST
						ast_node *return_stmt = new ast_node;
						return_stmt->symbol = "RETURN_STMT";
						return_stmt->children.push_back(make_ast_leaf("return"));
						syn_root->children.push_back(return_stmt);						
					}
		| T_RETURN expression ';'
		;
			
expression 
		: assignment_expression
		| simple_expression 
					{ 
						$$ = $1; 
					}
		;
		   
assignment_expression 
		: T_IDENTIFIER '=' expression 
					{ 
						//AST
						std::cout << "######AST : assignment_exp Assignment" << std::endl;
						print_stack_elements();
						std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;	
						value = std::string($1);
						S_ast.push_front(make_ast_leaf(value));
						std::string op = "=";
						ast_node *central_node = central_node_creation(op);
						/*
						if(for_flag){
							std::cout << "######FOR flag detected" << std::endl;				
						}
						*/
						if(if_cond_flag == 0 && for_flag == 0 && while_flag == 0){
							std::cout << "######IF/FOR/WHILE flag not detected" << std::endl;
							syn_root->children.push_back(central_node);	
						}
						else{
							std::cout << "######IF/FOR/WHILE flag detected" << std::endl;
							S_ast.push_front(central_node);
						}
						std::cout << ast_root->symbol << std::endl;				
						//SYMTAB
						check_exists($1,2);
													  
					  	auto itr = (current_scope_node->symbolTable).find($1);
					  	EXPRN *temp = $3;
					  	int t = temp->type;
					  	/*
						std::cout<<"Type is "<<t<<" Value is "<<temp->value<<std::endl;
						*/
					  	int t2 = (itr->second).type;
					  	/*
						std::cout<<"Type of var found is "<<t2<<std::endl;
						*/
					  	if((t2==1||t2==2)&&(t==3)){
							std::cout << "Type mismatch at " << yylineno << std::endl;
							exit(0);
					  	}
					  	if(t2==1)
							(itr->second).st_ival = atoi(temp->value);
					  	else if(t2==2)
							(itr->second).st_fval = atof(temp->value);
					}									  
		| unary_exprn
		;
					  
unary_exprn 
		: T_ADDADD T_IDENTIFIER
					{
						std::cout << "######AST :  IDENTIFIER " << $1 << " UNARYOP " << $2 << std::endl;
						unary_expression_branch($1, "++");
												 		
					}
		| T_MINMIN T_IDENTIFIER
					{
						std::cout << "######AST :  IDENTIFIER " << $1 << " UNARYOP " << $2 << std::endl;
						unary_expression_branch($1, "--");
												 		
					}
       	| postfix_expression
      	| T_IDENTIFIER uop_shorthd expression
		;
			
postfix_expression 
		: T_IDENTIFIER T_ADDADD
					{
						std::cout << "######AST :  IDENTIFIER " << $1 << " UNARYOP " << $2 << std::endl;
						unary_expression_branch($1, "++");
												 		
					}
		| T_IDENTIFIER T_MINMIN
					{
						std::cout << "######AST :  IDENTIFIER " << $1 << " UNARYOP " << $2 << std::endl;
						unary_expression_branch($1, "--"); 		
					}
		;

uop_shorthd  
		: T_ADDEQ
					{
						std::cout << "######AST :  Short Hand Unary Op " << $1 << std::endl; 		
					}
        | T_MINEQ
					{
						std::cout << "######AST :  Short Hand Unary Op " << $1 << std::endl; 		
					}
        | T_MULEQ
					{
						std::cout << "######AST :  Short Hand Unary Op " << $1 << std::endl; 		
					}
        | T_DIVEQ
					{
						std::cout << "######AST :  Short Hand Unary Op " << $1 << std::endl; 		
					}
		;
			 
simple_expression 
		: additive_expression 
					{ 
						$$ = $1; 
					}
		| additive_expression relop additive_expression
					{
						print_stack_elements();
						std::cout << "######AST : relop " << std::endl;
						std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						ast_node *branch1 = S_ast.front();
						S_ast.pop_front();
						ast_node *branch2 = S_ast.front();
						S_ast.pop_front();
						ast_node *branch3 = S_ast.front();
						S_ast.pop_front();
						ast_node *central_node = make_ast_node(branch2->symbol, branch1, branch3);
						S_ast.push_front(central_node);
					}
		| additive_expression logop additive_expression
					{
						print_stack_elements();
						std::cout << "######AST : logop " << std::endl;
						std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						ast_node *branch1 = S_ast.front();
						S_ast.pop_front();
						ast_node *branch2 = S_ast.front();
						S_ast.pop_front();
						ast_node *branch3 = S_ast.front();
						S_ast.pop_front();
						ast_node *central_node = make_ast_node(branch2->symbol, branch1, branch3);
						S_ast.push_front(central_node);
					}
		| additive_expression bitop additive_expression
					{
						print_stack_elements();
						std::cout << "######AST : bitop " << std::endl;
						std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						ast_node *branch1 = S_ast.front();
						S_ast.pop_front();
						ast_node *branch2 = S_ast.front();
						S_ast.pop_front();
						ast_node *branch3 = S_ast.front();
						S_ast.pop_front();
						ast_node *central_node = make_ast_node(branch2->symbol, branch1, branch3);
						S_ast.push_front(central_node);
					}
		;
				  
bitop 
		: T_OR
					{
						std::cout << "######BITOP : " << " | " << std::endl;
						value = "|";
						S_ast.push_front(make_ast_leaf(value));		
					}
   	  	| T_AND
					{
						std::cout << "######BITOP : " << " & " << std::endl;
						value = "&";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_XOR
					{
						std::cout << "######BITOP : " << " ^ " << std::endl;
						value = "^";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_LRSHIFT
					{
						std::cout << "######BITOP : " << " >> " << std::endl;
						value = ">>";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_LLSHIFT
					{
						std::cout << "######BITOP : " << " << " << std::endl;
						value = "<<";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	;
				  
relop 
		: '<'
					{
						std::cout << "######RELOP : " << "< " << std::endl;
						value = "<";
						S_ast.push_front(make_ast_leaf(value));		
					}
      	| '>'
					{
						std::cout << "######RELOP : " << ">" << std::endl;
						value = ">";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_LTEQ
					{
						std::cout << "######RELOP : " << "<=" << std::endl;
						value = "<=";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_GTEQ
					{
						std::cout << "######RELOP : " << ">=" << std::endl;
						value = ">=";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_NEQEQ
					{
						std::cout << "######RELOP : " << "!=" << std::endl;
						value = "!=";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_EQEQ
					{
						std::cout << "######RELOP : " << "==" << std::endl;
						value = "==";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	;

logop 
		: T_OROR
					{
						std::cout << "######LOGOP : " << "||" << std::endl;
						value = "||";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	| T_ANDAND
					{
						std::cout << "######LOGOP : " << "&&" << std::endl;
						value = "&&";
						S_ast.push_front(make_ast_leaf(value));		
					}
	  	;
	  
additive_expression 
		: term 
					{ 
						$$ = $1;
					}
		| additive_expression '+' term 
					{
						 //AST
						 std::cout << "######AST : addition" << std::endl;
						 std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						 std::string op = "+";
						 ast_node *central_node = central_node_creation_exp(op);
						 S_ast.push_front(central_node);
						 std::cout << ast_root->symbol << std::endl;
						 //SYMTAB
						 EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						 char res[50];
						 int t;
						 if(($1->type)==1 && ($3->type)==1){
							int a = atoi($1->value);
							int b = atoi($3->value);
							sprintf(res,"%d",a+b);
							t=1;
						 }
						 else if(($1->type)==1 && ($3->type)==2){
							int a = atoi($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a+b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==1){
							float a = atof($1->value);
							int b = atoi($3->value);
							sprintf(res,"%f",a+b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==2){
							float a = atof($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a+b);
							t=2;
						 }
						
						 temp->value = (char*) malloc(sizeof(char)*(strlen(res)+1));
						 strcpy(temp->value,res);
						 temp->type = t;
						 $$ = temp;
					}
		| additive_expression '-' term 
					{
						 //AST
						 std::cout << "######AST : subtraction" << std::endl;
						 std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						 std::string op = "-";
						 ast_node *central_node = central_node_creation_exp(op);
						 S_ast.push_front(central_node);
						 std::cout << ast_root->symbol << std::endl;
						 //SYMTAB
						 EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						 char res[50];
						 int t;
						 if(($1->type)==1 && ($3->type)==1){
							int a = atoi($1->value);
							int b = atoi($3->value);
							sprintf(res,"%d",a-b);
							t=1;
						 }
						 else if(($1->type)==1 && ($3->type)==2){
							int a = atoi($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a-b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==1){
							float a = atof($1->value);
							int b = atoi($3->value);
							sprintf(res,"%f",a-b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==2){
							float a = atof($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a-b);
							t=2;
						 }
						
						 temp->value = (char*) malloc(sizeof(char)*(strlen(res)+1));
						 strcpy(temp->value,res);
						 temp->type = t;
						 $$ = temp;
					}
		| '+' additive_expression %prec '*'
		| '-' additive_expression %prec '*'
		;

term 
		: factor 
					{ 
						$$ = $1; 
					}
	 	| term '*' factor 
					{
						 //AST
						 std::cout << "######AST : multiplication" << std::endl;
						 std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						 std::string op = "*";
						 ast_node *central_node = central_node_creation(op);
						 S_ast.push_front(central_node);
						 std::cout << ast_root->symbol << std::endl;
						 //SYMTAB
						 EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						 char res[50];
						 int t;
						 if(($1->type)==1 && ($3->type)==1){
							int a = atoi($1->value);
							int b = atoi($3->value);
							sprintf(res,"%d",a*b);
							t=1;
						 }
						 else if(($1->type)==1 && ($3->type)==2){
							int a = atoi($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a*b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==1){
							float a = atof($1->value);
							int b = atoi($3->value);
							sprintf(res,"%f",a*b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==2){
							float a = atof($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a*b);
							t=2;
						 }
							
						 temp->value = (char*) malloc(sizeof(char)*(strlen(res)+1));
						 strcpy(temp->value,res);
						 temp->type = t;
						 $$ = temp;
					}
							
     	| term '/' factor
					{
						 //AST
						 std::cout << "######AST : division" << std::endl;
						 std::cout << "######AST : $1 : " << $1 << " $3 : " << $3 << std::endl;
						 std::string op = "/";
						 ast_node *central_node = central_node_creation(op);
						 S_ast.push_front(central_node);
						 std::cout << ast_root->symbol << std::endl;
						 //SYMTAB
						 EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						 char res[50];
						 int t;
						 if(($1->type)==1 && ($3->type)==1){
							int a = atoi($1->value);
							int b = atoi($3->value);
							sprintf(res,"%d",a/b);
							t=1;
						 }
						 else if(($1->type)==1 && ($3->type)==2){
							int a = atoi($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a/b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==1){
							float a = atof($1->value);
							int b = atoi($3->value);
							sprintf(res,"%f",a/b);
							t=2;
						 }
						 else if(($1->type)==2 && ($3->type)==2){
							float a = atof($1->value);
							float b = atof($3->value);
							sprintf(res,"%f",a/b);
							t=2;
						 }
							
						 temp->value = (char*) malloc(sizeof(char)*(strlen(res)+1));
						 strcpy(temp->value,res);
						 temp->type = t;
						 $$ = temp;
					}
  	 	;

factor 
		: '(' expression ')' 
					{ 
						$$ = $2;
					}
	   	| T_IDENTIFIER 
					{ 
						//SYMTAB
						check_exists($1,2);
						auto itr = (current_scope_node->symbolTable).find($1);
						EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						char res[50];
						if((itr->second).type==1)
							sprintf(res,"%d",(itr->second).st_ival);
						else if((itr->second).type==2)
							sprintf(res,"%f",(itr->second).st_fval);
						temp->value = (char*) malloc(sizeof(char)*(strlen(res)+1));
						strcpy(temp->value,res);
						temp->type = (itr->second).type;
						$$ = temp;
						//AST
						std::cout << "######AST : List identifier "<< $1 << std::endl;
						id = $1;
						S_ast.push_front(make_ast_leaf(id));				
					 }	
	   	| call
	   	| T_INTEGER_VAL 
					{ 
						//SYMTAB
						EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						temp->value = (char*) malloc(sizeof(char)*(strlen($1)+1));
						strcpy(temp->value,$1);
						temp->type = 1;
						$$ = temp;
						//AST
						std::cout << "######AST : T_INT " << $1 << std::endl;
						value = $1;
						S_ast.push_front(make_ast_leaf(value));
					}
	   	| T_FLOAT_VAL 
					{ 	
						//SYMTAB 
						EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						temp->value = (char*) malloc(sizeof(char)*(strlen($1)+1));
						strcpy(temp->value,$1);
						temp->type = 2;
						$$ = temp;
						//AST
						std::cout << "######AST : T_FLOAT " << $1 << std::endl;
						value = $1;
						S_ast.push_front(make_ast_leaf(value));
					}
	   	| T_STRING_VAL 
					{  
						//SYMTAB
						EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						temp->value = (char*) malloc(sizeof(char)*(strlen($1)+1));
						strcpy(temp->value,$1);
						temp->type = 3;
					 	$$ = temp;
						//AST
						std::cout << "######AST : T_STRING " << $1 << std::endl;
						value = $1;
						S_ast.push_front(make_ast_leaf(value));
					}
	   	| T_CHAR_VAL 
					{ 	
						//SYMTAB
						EXPRN *temp = (EXPRN*) malloc(sizeof(EXPRN));
						temp->value = (char*) malloc(sizeof(char)*(strlen($1)+1));
						strcpy(temp->value,$1);
						temp->type = 3;
						$$ = temp;
						//AST
						std::cout << "######AST : T_CHAR " << $1 << std::endl;
						value = $1;
						S_ast.push_front(make_ast_leaf(value));
					}
	   	;

call 
		: T_IDENTIFIER '(' ')'
	 	| T_IDENTIFIER '(' args ')'
	 	;

args 	: expression
	 	| expression ',' args
	 	;

input_output_statements 
		: T_COUT T_LLSHIFT expression ';' 
					{ 
						std::cout<<"Printing "<<$3->value<<std::endl; 
					}
		| T_CIN T_LRSHIFT T_IDENTIFIER ';'
		;

%%

void yyerror(const char *str)
{
	printf("line no :%d  %s near %s\n", yylineno, str, yytext );
}

/*
int yywrap()
{
	return 1;
}
*/

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
	LevelOrderTraversal(root);

	std::cout << "Checking stack" << std::endl;
	print_stack_elements();
	ast_node *remains = new ast_node;
	while(S_ast.size() > 0){
		remains = S_ast.front();
		syn_root->children.push_back(remains);
		S_ast.pop_front();
	}
	LevelOrderTraversalAST();
    return 0;
}

/*
void reset_globals(){
	type = 0;
	iset = 0;
	fset = 0;
	sset = 0;
	cset = 0; 
}
*/

void check_exists(char *ID, int statement_type){

	if (((current_scope_node->symbolTable).find(ID) != (current_scope_node->symbolTable).end()) && (statement_type==1)) {
		std::cout<<"Identifier "<<ID<<" redefined at line "<<yylineno<<std::endl;
		exit(0);
	}
	else if (((current_scope_node->symbolTable).find(ID) == (current_scope_node->symbolTable).end()) && (statement_type==2)) {
		std::cout<<"Identifier used without declaration at line "<<yylineno<<std::endl;
		exit(0);
	}
}
