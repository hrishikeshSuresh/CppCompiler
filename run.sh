#!/bin/bash

NONE='\033[00m'
BLACK='\033[01;30m'
RED='\033[01;31m'
GREEN='\033[01;32m'
YELLOW='\033[01;33m'
BLUE='\033[01;34m'
PURPLE='\033[01;95m'
CYAN='\033[01;36m'
WHITE='\033[01;37m'
DGRAY='\033[01;90m'
BOLD='\033[1m'
UNDERLINE='\033[4m'

echo -e "\e[4m"
echo -e "${PURPLE}			Compiling grammar....${PURPLE}"
tput sgr0
echo -e "${DGRAY}"
yacc -d grammar.y
tput sgr0
echo -e "\e[4m"
echo -e "${YELLOW}			Compiling lexer....${YELLOW}"
tput sgr0
lex scanner.l
echo -e "\e[4m"
echo -e "${WHITE}			Compiling all files....${WHITE}"
tput sgr0
g++ -std=c++14 -Wall lex.yy.c y.tab.c -ll -ly
echo -e "${CYAN}		Now run ./a.out with your input file as an argument${CYAN}"
tput sgr0
./a.out test/input9.cpp > output/ast_output.txt
echo -e "Abstract Syntax Tree generated"
echo -e "\e[4m"
echo -e "${PURPLE}			Compiling grammar....${PURPLE}"
tput sgr0
echo -e "${DGRAY}"
yacc -d icg_grammar.y
tput sgr0
echo -e "\e[4m"
echo -e "${YELLOW}			Compiling lexer....${YELLOW}"
tput sgr0
lex icg_scanner.l
echo -e "\e[4m"
echo -e "${WHITE}			Compiling all files....${WHITE}"
tput sgr0
g++ -std=c++14 -Wall lex.yy.c y.tab.c -ll -ly
echo -e "${CYAN}		Now run ./a.out with your input file as an argument${CYAN}"
tput sgr0
./a.out test/input9.cpp > output/junk.txt
echo -e "Intermediate Three-Address Code generated"
python3 dead_code_elimination.py > output/junk.txt
echo -e "Code Optimization done. Dead Code Elimination"
