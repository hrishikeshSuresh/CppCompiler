%{
	#include "y.tab.h"
	#include <bits/stdc++.h>
	//void yyerror(const char *s);
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
DATATYPES		int|float|char|double|long|string|void
%%

{SINGLE_COMMENT}		{ std::cout<<yytext<<std::endl; }
"/*"          			{ BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"    	{ BEGIN(INITIAL);}
<ML_COMMENT>[^*\n]+		{ }
<ML_COMMENT>"*"			{ }
<ML_COMMENT>\n			{ }

"main"					{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_MAIN;}
"for"					{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_FOR;}
"while"					{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_WHILE;}
"if"					{ //if_cond_flag = 0;
						  char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_IF;}
"else"					{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_ELSE;}
"include"				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_INCLUDE;}
{DATATYPES}				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_TYPE;}
"struct"				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_STRUCT;}
"class" 				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_CLASS;}
"return"				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_RETURN;}
"private"				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_PRIVATE;}
"public"				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						 strcpy(s,yytext);
						 yylval.sval=s;return T_PUBLIC;}
"protected"				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_PROTECTED;}
"cout"					{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_COUT;}
"cin"					{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_CIN;}
[\+\-\*\/#\",;<>(){}=\[\]:]		{ std::cout<<yytext<<" sent"<<std::endl; return *yytext;}
{ID}\.[h]				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						 strcpy(s,yytext);
						 yylval.sval=s;return T_IDH;}
\"{ID}\.h\"				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_IDH;}
{CCONST}		 		{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_CHAR_VAL;}
{STRING}			  	{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_STRING_VAL;}
{ICONST}				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_INTEGER_VAL;}
{FCONST}				{ char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;return T_FLOAT_VAL;}
\n						{ lineno++;}
{ID}					{ /*
						  cout << yytext << " identifier" << endl;
						  insert(yytext, strlen(yytext), UNDEF, yylineno);
						  */
						  char *s = (char*)malloc(sizeof(char)*(strlen(yytext)+1));
						  strcpy(s,yytext);
						  yylval.sval=s;
						  return T_IDENTIFIER;}
\+\+					{ return T_ADDADD;}
\-\-					{ return T_MINMIN;}
\+\=					{ return T_ADDEQ;}
\-\=					{ return T_MINEQ;}
\*\=					{ return T_MULEQ;}
\/\=					{ return T_DIVEQ;}
"<="					{ return T_LTEQ;}
">="					{ return T_GTEQ;}
"!="					{ return T_NEQEQ;}
"=="					{ return T_EQEQ;}
"||"					{ return T_OROR;}
"&&"					{ return T_ANDAND;}
"|"						{ return T_OR;}
"&"						{ return T_AND;}
"^"						{ return T_XOR;}
">>"					{ return T_LRSHIFT;}
"<<"					{ return T_LLSHIFT;}
%%
