yacc -d grammar.y
lex scanner.l
g++ -std=c++14 -Wall lex.yy.c y.tab.c -ll -ly
echo "Now run ./a.out with your input file as an argument"
#./a.out input.cpp > output.txt
