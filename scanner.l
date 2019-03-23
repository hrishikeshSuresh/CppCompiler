%{
	/*
		AUTHORS 	: 		 Hrishikesh S.
							 Adarsha Nayak
							 Jai Agarwal
				  
		DEVELOPER COMMENTS : /*  for describing code
							 //    for removing code
							 vn		 v - version, n - version number

	*/
	
	#include "y.tab.h"
	#include <bits/stdc++.h>
	#include "symtab.h"
	
	/*declare a user-defined yyerror function*/
	void yyerror(const char *s);
	
	using namespace std;
	
	int yylex();
	unsigned int lineno = 0;
	//int yylineno = 1;
%}

%x ML_COMMENT
%option yylineno
%option noyywrap

SINGLE_COMMENT	\/\/(.*)
MULTI_COMMENT	\/\*(.*\n)*.*\*\/
DIGIT 			[0-9]
FL				[fFlL]?
UL				(u|U|l|L)*
FRAC			(\.{DIGIT}+)?
EXP				([Ee][+-]?{DIGIT}+)?
NUMBER 			({DIGIT}+{FRAC}{EXP})
LETTER			[a-zA-Z]
ID				[a-zA-Z_][a-zA-Z_0-9]*
PRINT			[ -~]
CCONST			(\'{PRINT}\')|(\'\\[nftrbv]\')
STRING			\"{PRINT}*\"
ICONST			{DIGIT}+
FCONST			({DIGIT}+(\.{DIGIT}+){EXP})
CODE_CHAR		[\+\-\*\/#\",;<>(){}=\[\]:]

%%

[ /t/r/f]+
{SINGLE_COMMENT}		{ cout << yytext << endl; }
"/*"          			{ BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"    	{ BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+		{ }
<ML_COMMENT>"*"			{ }
<ML_COMMENT>\n			{ }

"main"					{ cout << "Main function" << endl;
						  return T_MAIN; }
"for"					{ return T_FOR; }
"while"					{ return T_WHILE; }
"if"					{ return T_IF; }
"else"					{ return T_ELSE; }
"include"				{ return T_INCLUDE; }
"define"				{ return T_DEFINE; }
"int"					{ yylval.str_val = yytext;
						  return T_INT; }
"void"					{ yylval.str_val = yytext;
						  return T_VOID; }
"float"					{ yylval.str_val = yytext;
						  return T_FLOAT; }
"char"					{ yylval.str_val = yytext;
						  return T_CHAR; }
"double"				{ yylval.str_val = yytext;
						  return T_DOUBLE; }
"long"					{ return T_LONG; }
"long int"				{ return T_LINT; }
"long double"			{ return T_LDOUBLE; }
"long long int"			{ return T_LLINT; }
"unsigned"				{ return T_UNSIGNED; }
"struct"				{ return T_STRUCT; }
"string"				{ cout << yytext << " data type" << endl; 
						  return T_STRING; }
"class" 				{ return T_CLASS; }
"return"				{ return T_RETURN; }
"private"				{ return T_PRIVATE; }
"public"				{ return T_PUBLIC; }
"protected"				{ return T_PROTECTED; }
"cout"					{ return T_COUT; }
"cin"					{ return T_CIN; }
{CODE_CHAR}				{ cout << yytext << " sent" << endl; 
						  return *yytext; }
{ID}\.[h]				{ cout << "standard header\n"; 
					      return T_IDH; }
\"{ID}\.h\"				{ cout << yytext << " T_IDH" << endl; 
						  return T_IDH; }
{CCONST}		 		{ yylval.char_val  = yytext[0];
						  return T_CHAR_VAL; }
{STRING}			  	{ yylval.str_val = (char*)malloc(yyleng * sizeof(char));
						  strcpy(yylval.str_val, yytext); 
						  return T_STRING_VAL; }
{ICONST}				{ yylval.int_val   = atoi(yytext); 
						  return T_INTEGER_VAL; }
{FCONST}				{ yylval.double_val = atof(yytext);
						  return T_FLOAT_VAL; }
\n						{ lineno++; }
{ID}					{ cout << yytext << " identifier" << endl;
						  yylval.str_val = yytext;
						  insert(yytext, strlen(yytext), UNDEF, yylineno);
						  return T_IDENTIFIER; }
\+\+					{ return T_ADDADD; }
\-\-					{ return T_MINMIN; }
\+\=					{ return T_ADDEQ; }
\-\=					{ return T_MINEQ; }
\*\=					{ return T_MULEQ; }
\/\=					{ return T_DIVEQ; }
"<="					{ return T_LTEQ; }
">="					{ return T_GTEQ; }
"!="					{ return T_NEQEQ; }
"=="					{ return T_EQEQ; }
"||"					{ return T_OROR; }
"&&"					{ return T_ANDAND; }
"|"						{ return T_OR; }
"&"						{ return T_AND; }
"^"						{ return T_XOR; }
">>"					{ return T_LRSHIFT; }
"<<"					{ return T_LLSHIFT; } 

%%
