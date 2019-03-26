#!/bin/bash

NONE='\033[00m'
RED='\033[01;31m'
GREEN='\033[01;32m'
YELLOW='\033[01;33m'
PURPLE='\033[01;35m'
CYAN='\033[01;36m'
WHITE='\033[01;37m'
BOLD='\033[1m'
UNDERLINE='\033[4m'

echo -e "${PURPLE}			Compiling grammar....${PURPLE}"
tput sgr0
yacc -d grammar.y
echo -e "${YELLOW}			Compiling lexer....${YELLOW}"
tput sgr0
lex scanner.l
echo -e "${WHITE}			Compiling all files....${WHITE}"
tput sgr0
g++ -std=c++14 -Wall -Wcomment lex.yy.c y.tab.c -ll -ly
echo -e "${CYAN}		Now run ./a.out with your input file as an argument${CYAN}"
tput sgr0
#./a.out input.cpp > output.txt
