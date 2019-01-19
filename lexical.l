%{
  #include "y.tab.h"
  #include "LLC_Liste.h"
  #include "OperationTypeG.h"
  #include "TableDesSymbole.h"
  #include "Quadruplets.h"
  extern int nb_lignes;
  extern YYSTYPE yylval;

%}

idf [A-Z][A-Za-z0-9]*
number [0-9]+
%%
\{\{(([^\}]|\n)*(\}([^\}]|\n)+)*)*\}\} for(;*yytext;nb_lignes+=(*yytext)=='\n',yytext++);
LANGAGE return mc_lang;
FIN return mc_fin;
DEC return mc_dec;
FINDEC return mc_fdec;
DEBUT return mc_deb;
#InOut[ ]*\n {nb_lignes++;return bib_inOut;}
#TAB[ ]*\n {nb_lignes++;return bib_tab;}
#ARITHME[ ]*\n {nb_lignes++;return bib_arithm;}
:= return aff;
:: return mc_vardec;
{number} {
  if ((atoi(yytext)<=32767)  &&
       (atoi(yytext)>=-32768))
              yylval.typeG = cr_Entier(atoi(yytext));
   else
   printf(RED "[ERREURLEXICAL]->" RESET "Le nombre est tres lang [ligne:%d]!!\n",nb_lignes);
  return mc_IntVal;
         }
[\"][^\"]*[\"] {  yylval.typeG = cr_Chain(strdup(yytext));
                  return mc_StringVal;}
{number}[.]{number} {
             yylval.typeG = cr_Reele(atof(yytext));
             return mc_ReelVal;
              }
int return mc_int;
float return mc_float;
string return mc_string;
CONST return mc_CONST;
[\+\-\*\/\)\(\>\<\=\,\;\]\[] return yytext[0];
(<=) return leOp;
(>=) return geOp;
(!=) return neOp;
While return mc_While;
Faire return mc_Faire;
Fait return mc_Fait;
EXECUT return mc_EXECUT;
IF return mc_IF;
input return mc_input;
Output return mc_Output;
{idf} {
      typeG g = yylval.typeG =creeIDF(yytext);
      inserer(yytext,"IDF",g);
      return id ;
      }
\n {nb_lignes++;}
[ \t] ;
. printf("[ERREURLEXICAL] a la ligne =%d [%s]\n",nb_lignes,yytext );


%%

