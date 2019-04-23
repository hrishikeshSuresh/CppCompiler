%{
	#include<stdio.h>
	#include<string.h>
	#include<bits/stdc++.h>
	using namespace std;
	void yyerror(const char *s);
	extern int yylineno;
	extern char* yytext;
	int yylex();
	//int yywrap();
	
	extern int lineno;
	int list_declr_flag = 0;
	int type;
	int iset=0,fset=0,sset=0,cset=0;
	void reset_globals();
	void check_exists(char* str, int a);

	char* temp_func();
	int temp=0;
	char* ret;
	int label = 0;
	int global_next=0;
	int args_count=0;
	char* label_func();
	char* global_func();
	vector < map<string,string> > v;
%}

/*struct valtypes{
	char cval;
	int ival;
	float fval;
	char* sval;
}valtypes;*/


%union{
    	char cval;
		int ival;
		float fval;
		char *sval;
		//valtypes *allval;
		struct{
			char* next;
			char code[1500];
			char addr[50]; 
			char* true_label;
			char* false_label;
		}node;		
};

%token <sval> T_INCLUDE T_IDH T_TYPE T_RETURN T_COUT T_CIN
%token <sval> T_IDENTIFIER T_ADDEQ T_MINEQ T_MULEQ T_DIVEQ T_FOR T_IF T_ELSE T_LTEQ
%token <sval> T_GTEQ T_NEQEQ T_EQEQ T_OROR T_ANDAND T_OR T_AND T_XOR T_LRSHIFT T_LLSHIFT
%token <sval> T_WHILE T_MAIN T_STRING T_STRUCT T_CLASS T_PRIVATE T_PUBLIC T_PROTECTED T_ADDADD T_MINMIN
%token <sval> T_STRING_VAL 
%token <sval> T_CHAR_VAL 
%token <sval> T_INTEGER_VAL 
%token <sval> T_FLOAT_VAL

%type <node> P program factor external_declaration main_fun declaration_statement
list_identifier  array values constant declarator fun_declr params_list params compound_stmt block_item_list block_item user_defined_ds class term additive_expression simple_expression expression expression_stmt var_init init variable  array_init  global_stmt statement assignment_expression while_loop iterative_statement  bitop relop logop for_loop for_assgn_stmt return_stmt unary_exprn postfix_expression uop_shorthd selection_statement for_decl_stmt call args

%left '(' ')' '+' '*' '-' '/'

%start P

%%

P : program 
	{ 
		FILE *fptr = fopen("output/icg_output.txt", "w");
		fprintf(fptr,"%s\n",$1.code); 
		fclose(fptr);
	}
  ;

program	: external_declaration {$$ = $1;}
		| program external_declaration 
			{
				//ICG
				strcpy($$.code,$1.code);
				strcat($$.code,"\n");
				strcat($$.code,$2.code);
			}
		;

external_declaration : header_stmt {}
					 | global_stmt 
					 	{
					 		//ICG
					 		$$ = $1;
					 	}
					 | main_fun
					 	{
					 		//ICG
					 		strcpy($$.code,$1.code);
					 	}
					 ;
					 
header_stmt : '#' T_INCLUDE '<' T_IDH '>'
            | '#' T_INCLUDE  T_IDH
			;

global_stmt : declaration_statement 
			{
				strcpy($$.code,$1.code);
			}
		    | fun_declr 
		    {
				strcpy($$.code,$1.code);
			}
			| user_defined_ds 
			{
				strcpy($$.code,$1.code);
			}
			| statement 
			{
				strcpy($$.code,$1.code);
			}
			;
			
main_fun : T_TYPE T_MAIN '(' ')' compound_stmt 
		 {
		 	//ICG
		 	strcpy($$.code,"main:\n");
		 	strcat($$.code,$5.code);
		 	strcat($$.code,"\n");
		 	//printf("in main_func\n %s",$$.code);
		 }
	     ;
			  
			
declaration_statement : T_TYPE list_identifier ';' 
				 {
				   		//ICG
				   		sprintf($$.code,"%s %s",$1,$2.code);
				   }
	        		  ;
		
list_identifier : list_identifier ',' variable 
				 {	//ICG
				 	sprintf($$.code,"%s,%s",$1.code,$3.code);
				 }
				| list_identifier ',' init 
				{
					//ICG
					sprintf($$.code,"%s,%s",$1.code,$3.code);
				}
				| init 
				{
					//ICG
					sprintf($$.code,"%s",$1.code);
				}
				| variable 
				{
					//ICG
					sprintf($$.code,"%s",$1.code);
				}
				;
				
variable : T_IDENTIFIER
					    {
					    	//ICG
					    	//strcpy($$.addr,$1);
	   						strcpy($$.code,$1);
					    }
		 | T_IDENTIFIER array 
				          {
				          	//ICG
				              //strcpy($$.addr,$1);
							  sprintf($$.code,"%s %s",$1,$2.code);
				          }
		 ;
		 
array : array '[' T_INTEGER_VAL ']'
	  {
	  	//ICG
	  	sprintf($$.code,"%s [ %s ]",$1.code,$3);
	  }
	  | '[' T_INTEGER_VAL ']' 
	  {
	  	  //ICG
	      sprintf($$.code,"[ %s ]",$2);
	  }
	  ;
	  
init : var_init 
	 { 
	 	strcpy($$.code,$1.code); 
	 }
     | array_init 
     {
     	strcpy($$.code,$1.code);	
     }
	 ;
	 
var_init : T_IDENTIFIER '=' expression 
		{
		 	strcat($$.code,$3.code); 
		   	strcat($$.code,$1);
		   	strcat($$.code," = ");
		   	strcat($$.code,$3.addr);
		   	//strcat($$.code,"\n");
		}
		;
array_init : T_IDENTIFIER array '=' '{' values '}'
			{
				sprintf($$.code,"%s %s = { %s }",$1,$2.code,$5.code);
			}
		   ;
		   
values : values ',' constant 
		{
			sprintf($$.code,"%s , %s",$1.code,$3.code);
		} 
       | constant 
       	{
       		strcpy($$.code,$1.code);
       	}
	   ;
	   
constant : T_INTEGER_VAL {strcpy($$.code,$1);}
		 | T_STRING_VAL {strcpy($$.code,$1);}
		 | T_CHAR_VAL {strcpy($$.code,$1);}
		 | T_FLOAT_VAL {strcpy($$.code,$1);}
		 ;
		 
declarator : '(' ')' {strcpy($$.code,"");}
		   | '(' params ')' {strcpy($$.code,"");}
		   ;

fun_declr : T_TYPE T_IDENTIFIER declarator compound_stmt 
		{
			sprintf($$.code,"%s:\n%s",$2,$4.code);
		}
		  ;
		  
/*var_type : T_INT 
		 | T_FLOAT
		 | T_DOUBLE
		 | T_CHAR
		 | T_STRING
		 | T_VOID
		 ;*/
		 
/*R_TYPE : T_TYPE
	   | T_VOID
	   ;*/
		 
params_list : T_TYPE T_IDENTIFIER {strcpy($$.code,"");}
			| params_list ',' T_TYPE T_IDENTIFIER  {strcpy($$.code,"");}
			;
		 
params : params_list  {strcpy($$.code,"");}
       ;
		 
compound_stmt : start_paren end_paren {strcpy($$.code,"");}
			  | start_paren block_item_list end_paren {strcpy($$.code,$2.code);}
			  ;
			  
start_paren : '{'

end_paren : '}'
			  
block_item_list : block_item 
				{
					strcpy($$.code,$1.code);
					//printf("block item %s",$$.code);
				}
				| block_item_list block_item  	
				{
					sprintf($$.code,"%s\n %s",$1.code,$2.code);
					//printf("blocks %s",$$.code);
				}
				;

block_item : declaration_statement
			{
				strcpy($$.code,$1.code);
			}
		   | statement
		   {
				strcpy($$.code,$1.code);
		    }
		   ;

		   
		   
user_defined_ds : class 
				{
					strcpy($$.code,"");
				}
				| structure
				{
					strcpy($$.code,"");
				}
				;
				
class : T_CLASS T_IDENTIFIER class_body_stmt ';'
		{
					strcpy($$.code,"");
		}

structure : T_STRUCT T_IDENTIFIER struct_body_stmt ';'

class_body_stmt  : start_paren end_paren
				 | start_paren class_mems end_paren 
				 ;
				 
struct_body_stmt  : start_paren end_paren
				  | start_paren struct_mems end_paren 
				  ;

struct_mems : struct_mem
			| struct_mems struct_mem
			;

class_mems : class_mem
		   | class_mems class_mem
		   ;

struct_mem : declaration_statement
		   | fun_declr
		   ;

class_mem	:  T_TYPE class_var_declaration ';'
			|  fun_declr
			|  access_specifier ':'
			;
			
class_var_declaration : T_IDENTIFIER 
					  | class_var_declaration ',' T_IDENTIFIER 
					  ;

access_specifier : T_PRIVATE
                 | T_PUBLIC
                 | T_PROTECTED
				 ;
		     
statement : expression_stmt 
			{
				strcpy($$.code,$1.code);
			}
		  | compound_stmt
		  {
		  	strcpy($$.code,$1.code);
		  }
  		  | iterative_statement
  		  {
  		  	strcpy($$.code,$1.code);
  		  }
  		  | selection_statement
  		  {
  		  	map <string,string> m = v.back();
			v.pop_back();
			sprintf($$.code,"%s\n%s:\n",$1.code,m["next"].c_str());
  		  }
		  | input_output_statements
		  {

		  }
          | return_stmt
          {
          	strcpy($$.code,$1.code);
          }
  		  ;
		  
expression_stmt
    : ';' {}
    | expression ';'
    {
    	strcpy($$.code,$1.code);
    }
    ;

if_stack : {
			map <string,string> m;
			char *begin = label_func();
			m["true"] = string(begin);
			free(begin);
			m["type"] = "if";
			m["false"] = string(global_func());
			m["next"] = m["false"];
			v.push_back(m);
			//printf("if");
			//printf("true %s  false  %s  next  %s",m["true"].c_str(),m["false"].c_str(),m["next"].c_str());

		}
		;

if_else_stack :
			{
				map <string,string> m = v.back();
				v.pop_back();

				//m["next"] = m["false"];
				
				char *begin = label_func();
				m["false"] = string(begin);
				m["type"] = "if_else";
				free(begin);
				v.push_back(m);
				//printf("if else");
				//printf("true %s  false  %s  next  %s",m["true"].c_str(),m["false"].c_str(),m["next"].c_str());
			}
			;

selection_statement : T_IF '(' if_stack expression ')' statement
					{
						map <string,string> m = v.back();
					sprintf($$.code,"%s\nif %s goto %s\n goto %s\n%s:\n%s",$4.code,$4.addr,m["true"].c_str(),m["false"].c_str(),m["true"].c_str(),$6.code);		
					}
                    | T_IF '(' if_stack expression ')' statement T_ELSE if_else_stack  statement
                    {
                    	map <string,string> m = v.back();
                    	sprintf($$.code,"%s\nif %s goto %s\ngoto %s\n%s:\n%s\n%s:\n%s",$4.code,$4.addr,m["true"].c_str(),m["false"].c_str(),m["true"].c_str(),$6.code,m["false"].c_str(),$9.code);
                    }
                    ;
					
iterative_statement : for_loop
					{
						map <string,string> m = v.back();
						v.pop_back();
						sprintf($$.code,"%s\n%s:\n",$1.code,m["false"].c_str());
						if(!v.empty())
						{
							map <string,string> m = v.back();
							if(m["type"]=="if")
							{
								strcat($$.code,"\n");
								strcat($$.code,"goto ");
								strcat($$.code,m["false"].c_str());
								strcat($$.code,"\n");
							}
						}

					}
					| while_loop 
					{
						map <string,string> m = v.back();
						v.pop_back();
						sprintf($$.code,"%s\n%s:\n",$1.code,m["false"].c_str());
					}
  					;

for_stack : 
		{
			map <string,string> m;
			char *begin = label_func();
			m["begin"] = string(begin);
			m["type"] = "for";
			free(begin);
			m["true"] = string(label_func());
			m["false"] = string(global_func());
			m["next"] = m["begin"];
			v.push_back(m);
			//printf("for loop");
			//printf("true %s  false  %s  next  %s",m["true"].c_str(),m["false"].c_str(),m["next"].c_str());
		}

for_loop :  T_FOR '('  for_assgn_stmt ';' for_stack  expression ';'  unary_exprn ')'  statement
			{
				map <string,string> m = v.back();
				/*init 
				  begin: cond.code

				  cond.true: stat.code
				  			 incr
							 goto begin
				  cond.false:
				*/
				sprintf($$.code,"%s\n%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s\n%s\ngoto %s",$3.code,m["begin"].c_str(),$6.code,$6.addr,m["true"].c_str(),m["false"].c_str(),m["true"].c_str(),$10.code,$8.code,m["begin"].c_str());
			}
  	   	 ;

for_assgn_stmt : T_TYPE for_decl_stmt 
				{
					sprintf($$.code,"%s %s",$1,$2.code);
				}
			   | assignment_expression
			   {
			   	strcpy($$.code,$1.code);
			   }
			   ;

for_decl_stmt : T_IDENTIFIER '=' expression 
				{
					strcat($$.code,$3.code); 
				   	strcat($$.code,$1);
				   	strcat($$.code," = ");
				   	strcat($$.code,$3.addr);
				   	//strcat($$.code,"\n");
				}
			  | for_decl_stmt ',' T_IDENTIFIER '=' expression
			  {
			  	sprintf($$.code,"%s , ",$1.code);
			  	strcat($$.code,$5.code); 
				strcat($$.code,$3);
			   	strcat($$.code," = ");
			   	strcat($$.code,$5.addr);
			   	//strcat($$.code,"\n");
			  }
			  ;

while_stack : 
			{
				map <string,string> m;
				char *begin = label_func();
				m["begin"] = string(begin);
				m["type"] = "while";
				free(begin);
				m["true"] = string(label_func());
				m["false"] = string(global_func());
				m["next"] = m["begin"];
				v.push_back(m);
			}
			;

while_loop : T_WHILE '(' while_stack expression ')' statement
			{
				map <string,string> m = v.back();
				sprintf($$.code,"%s:\n%sif %s goto %s\ngoto %s\n \n%s:\n%s\ngoto %s",  m["begin"].c_str(), $4.code,  $4.addr,m["true"].c_str(),m["false"].c_str(),  m["true"].c_str(),     $6.code,m["begin"].c_str());
			}
  		   ;
		   
return_stmt : T_RETURN ';'
			{
				strcpy($$.code,"return ");
			}
		    | T_RETURN expression ';'
		    {
		    	sprintf($$.code,"return %s",$2.code);
		    }
			;
			
expression : assignment_expression
			{
				strcpy($$.code,$1.code);
			}
		   | simple_expression 
		   { 
		   		strcpy($$.code,$1.code); 
	  		 	strcpy($$.addr,$1.addr); 
	  	   }
		   ;
		   
assignment_expression : T_IDENTIFIER '=' expression		
						{
							strcat($$.code,$3.code); 
						   	strcat($$.code,$1);
						   	strcat($$.code," = ");
						   	strcat($$.code,$3.addr);
						   	strcat($$.code,"\n");
						}						  
	          		  | unary_exprn
	          		  {
	          		  	strcpy($$.code,$1.code);
	          		  }
					  ;
					  
unary_exprn : T_ADDADD T_IDENTIFIER
			{
				ret = temp_func();
				sprintf($$.code,"%s = %s + 1\n%s = %s",ret,$2,$2,ret);
				free(ret);
			}
			| T_MINMIN T_IDENTIFIER
			{
				ret = temp_func();
				sprintf($$.code,"%s = %s - 1\n%s = %s",ret,$2,$2,ret);
				free(ret);
			}
            | postfix_expression
            {
            	strcpy($$.code,$1.code);
            }
            | T_IDENTIFIER uop_shorthd expression
            {
            	sprintf($$.code,"%s %s %s",$1,$2.code,$3.code);
            }
			;
			
postfix_expression : T_IDENTIFIER T_ADDADD
				{
					ret = temp_func();
					sprintf($$.code,"%s = %s + 1\n%s = %s",ret,$2,$2,ret);
					free(ret);

				}
				   | T_IDENTIFIER T_MINMIN
				 {
					ret = temp_func();					
					sprintf($$.code,"%s = %s - 1\n%s = %s",ret,$2,$2,ret);
					free(ret);
				 }
				   ;

uop_shorthd  : T_ADDEQ
			{
				strcpy($$.code,"+=");
			}
             | T_MINEQ
             {
				strcpy($$.code,"-=");
			 }
             | T_MULEQ
             {
				strcpy($$.code,"*=");
			 }
             | T_DIVEQ
             {
				strcpy($$.code,"/=");
			 }
			 ;
			 
simple_expression : additive_expression 
					{
						strcpy($$.code,$1.code); 
	  					strcpy($$.addr,$1.addr);
					}
				  | additive_expression relop additive_expression
				  {
				  	ret = temp_func();
					strcpy($$.addr,ret);
					free(ret);
					strcat($$.code,$1.code);
					strcat($$.code,$3.code);

					strcat($$.code,"\n");
					strcat($$.code,$$.addr); 
					strcat($$.code," = ");
					strcat($$.code,$1.addr);
					strcat($$.code,$2.addr);
					strcat($$.code,$3.addr);
					strcat($$.code,"\n"); 
				  	//sprintf($$.code,"%s %s %s",$1.addr,$2.addr,$3.addr);
				  }
				  | additive_expression logop additive_expression
				  {
				  	ret = temp_func();
					strcpy($$.addr,ret);
					free(ret);
					strcat($$.code,$1.code);
					strcat($$.code,$3.code);

					strcat($$.code,"\n");
					strcat($$.code,$$.addr); 
					strcat($$.code," = ");
					strcat($$.code,$1.addr);
					strcat($$.code,$2.addr);
					strcat($$.code,$3.addr);
					strcat($$.code,"\n"); 
				  	//sprintf($$.code,"%s %s %s",$1.addr,$2.addr,$3.addr);
				  }
				  | additive_expression bitop additive_expression
				  {
				  	ret = temp_func();
					strcpy($$.addr,ret);
					free(ret);
					strcat($$.code,$1.code);
					strcat($$.code,$3.code);

					strcat($$.code,"\n");
					strcat($$.code,$$.addr); 
					strcat($$.code," = ");
					strcat($$.code,$1.addr);
					strcat($$.code,$2.addr);
					strcat($$.code,$3.addr);
					strcat($$.code,"\n"); 
				  	//sprintf($$.code,"%s %s %s",$1.addr,$2.addr,$3.addr);
				  }
				  ;
				  
bitop : T_OR
		{
			strcpy($$.addr,"||");
		}
   	  | T_AND
   	  	{
			strcpy($$.addr,"&&");
		}   	  
	  | T_XOR
	  	{
			strcpy($$.addr,"^");
		}
	  | T_LRSHIFT
	  	{
			strcpy($$.addr,"<<");
		}
	  | T_LLSHIFT
	  	{
			strcpy($$.addr,">>");
		}
	  ;
				  
relop : '<'
		{
			strcpy($$.addr,"<");
		}
      | '>'
      {
			strcpy($$.addr,">");
	   }
	  | T_LTEQ
	  {
			strcpy($$.addr,"<=");
	  }
	  | T_GTEQ
	  {
			strcpy($$.addr,">=");
	  }
	  | T_NEQEQ
	  {
			strcpy($$.addr,"!=");
	  }
	  | T_EQEQ
	  {
			strcpy($$.addr,"==");
	  }
	  ;

logop : T_OROR
		{
			strcpy($$.addr,"||");
		}
	  | T_ANDAND
	  {
	  	strcpy($$.addr,"&&");
	  }
	  ;
	  
additive_expression : term 
					{
						strcpy($$.code,$1.code); 
	  					strcpy($$.addr,$1.addr);
					}
					| additive_expression '+' term 
					{
						ret = temp_func();
					  	strcpy($$.addr,ret);
					  	free(ret);
					  	strcat($$.code,$1.code);
					  	strcat($$.code,$3.code);

					  	strcat($$.code,"\n");
					  	strcat($$.code,$$.addr); 
					  	strcat($$.code," = ");
					  	strcat($$.code,$1.addr);
					  	strcat($$.code," + ");
					  	strcat($$.code,$3.addr);
					  	strcat($$.code,"\n"); 
					}
					| additive_expression '-' term 
					{
						ret = temp_func();
					  	strcpy($$.addr,ret);
					  	free(ret);
					  	strcat($$.code,$1.code);
					  	strcat($$.code,$3.code);

					  	strcat($$.code,"\n");
					  	strcat($$.code,$$.addr); 
					  	strcat($$.code," = ");
					  	strcat($$.code,$1.addr);
					  	strcat($$.code," - ");
					  	strcat($$.code,$3.addr);
					  	strcat($$.code,"\n"); 
					}
					| '+' additive_expression %prec '*' {}
					| '-' additive_expression %prec '*' {}
					;

term : factor  
	 {
	 	strcpy($$.code,$1.code); 
	  	strcpy($$.addr,$1.addr);
	 }
	 | term '*' factor	
	 {
	 	ret = temp_func();
	  	strcpy($$.addr,ret);
	  	free(ret);

	  	strcat($$.code,$1.code);
	  	strcat($$.code,$3.code);

	  	strcat($$.code,"\n");
	  	strcat($$.code,$$.addr); 
	  	strcat($$.code," = ");
	  	strcat($$.code,$1.addr);
	  	strcat($$.code," * ");
	  	strcat($$.code,$3.addr);
	  	strcat($$.code,"\n"); 
	 }						
     | term '/' factor
     {
	 	ret = temp_func();
	  	strcpy($$.addr,ret);
	  	free(ret);

	  	strcat($$.code,$1.code);
	  	strcat($$.code,$3.code);

	  	strcat($$.code,"\n");
	  	strcat($$.code,$$.addr); 
	  	strcat($$.code," = ");
	  	strcat($$.code,$1.addr);
	  	strcat($$.code," / ");
	  	strcat($$.code,$3.addr);
	  	strcat($$.code,"\n"); 
	 }
  	 ;

factor : '(' expression ')' 
		{
			strcpy($$.code,$2.code); 
			strcpy($$.addr,$2.addr);
		}
	   | T_IDENTIFIER 
	   {
	   	strcpy($$.addr,$1);
	   	strcpy($$.code,"");
	   }
	   | call
	   {
	   	strcpy($$.code,$1.code);
	   }
	   | T_INTEGER_VAL 
	   {
	   	strcpy($$.addr,$1);
	   	strcpy($$.code,"");
	   }
	   | T_FLOAT_VAL 
	   {
	   strcpy($$.addr,$1);
	   	strcpy($$.code,"");
	   }
	   | T_STRING_VAL 
	   {
	   	strcpy($$.addr,$1);
	   	strcpy($$.code,"");
	   }
	   | T_CHAR_VAL 
	   {
	   	strcpy($$.addr,$1);
	   	strcpy($$.code,"");
	   }
	   ;

call : T_IDENTIFIER '(' ')'
	{
		sprintf($$.code,"call(%s,0)",$1);
	}
	 | T_IDENTIFIER '(' args ')'
	 {
	 	sprintf($$.code,"%s\ncall(%s,%d)",$3.code,$1,args_count);
	 	args_count=0;	
	 }
	 ;

args : expression
	 {
	 	sprintf($$.code,"%s\nparam %s",$1.code,$1.addr);
	 	args_count+=1;
	 }
	 | expression ',' args
	 {
	 	args_count+=1;
	 	sprintf($$.code,"%s\nparam %s\n%s",$1.code,$1.addr,$3.code);
	 }
	 ;

input_output_statements : T_COUT T_LLSHIFT expression ';' 
						| T_CIN T_LRSHIFT T_IDENTIFIER ';'
						;

%%

void yyerror(const char *str)
{
	printf("line no :%d  %s near %s\n", yylineno, str, yytext );
}

/*int yywrap()
{
	return 1;
}*/

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

	//LevelOrderTraversal(root);
    return 0;
}

/*void reset_globals(){

 type = 0;
 iset = 0;
 fset = 0;
 sset = 0;
 cset = 0;
 
}*/
/*
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
*/

char* temp_func()
{
	char *ret_temp = (char*)malloc(sizeof(char)*10);
	sprintf(ret_temp,"t%d",temp);
	temp+=1;
	return ret_temp;
}

char* label_func()
{
	char *ret_temp = (char*)malloc(sizeof(char)*10);
	sprintf(ret_temp,"L%d",label);
	label+=1;
	return ret_temp;
}

char* global_func()
{
	char *ret_temp = (char*)malloc(sizeof(char)*10);
	sprintf(ret_temp,"G%d",global_next);
	global_next +=1;
	return ret_temp;
}
