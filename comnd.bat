flex lexical.l
bison -d synt.y
gcc -w lex.yy.c synt.tab.c -lfl -ly -o compileISIL