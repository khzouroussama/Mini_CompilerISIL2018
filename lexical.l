%{
  #include "synt.tab.h"
%}

idf [A-Z][A-Za-z0-9]*
%%
LANGAGE return mc_lang;
FIN return mc_fin;
DEC return mc_dec;
FINDEC return mc_fdec;
DEBUT return mc_deb;
#InOut return bib_inOut;
#TAB return bib_tab;
#ARITHME return bib_arithm;
:= return aff;
; return pvg;
[0-9]+ return mc_number;
"[" return mc_dCroch;
"]" return mc_finCroch;
:: return mc_vardec;
int return mc_int;
float return mc_float;
string return mc_string;
{idf} return id;
[ \t\n]
. printf("erreur lexical\n" );




