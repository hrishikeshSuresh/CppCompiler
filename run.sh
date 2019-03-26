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

yacc -d grammar.y
lex scanner.l
g++ -std=c++14 -Wall -Wcomment lex.yy.c y.tab.c -ll -ly
echo -e "${CYAN}Now run ./a.out with your input file as an argument${CYAN}"
tput sgr0
#./a.out input.cpp > output.txt
