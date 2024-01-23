yacc -d parser.y
lex parser.l
cc y.tab.c lex.yy.c -ll
./a.out input.c