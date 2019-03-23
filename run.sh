yacc -d grammar.y
lex scanner.l
g++ -std=c++14 -Wall lex.yy.c y.tab.c -ll -ly
#./a.out input.cpp > output.txt
