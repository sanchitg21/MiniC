yacc -d three.y
lex three.l
cc y.tab.c lex.yy.c -ll
./a.out input.c