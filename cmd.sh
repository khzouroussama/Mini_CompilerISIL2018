flex lexical.l
bison -dv synt.y
gcc -w lex.yy.c synt.tab.c -lfl -ly -o compileISIL
