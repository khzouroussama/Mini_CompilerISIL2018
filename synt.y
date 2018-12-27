%{
  #include <stdio.h>
  int decBIB[3]={0,0,0}
      ,nb_lignes=1
      ,indiceQc =0
  ;
  char tmp[30];
 %}

%code requires{
  #include "TypeGlobale.h"
}

%union{
  typeG typeG;
  Etype SauvType;
  int ent;
}
/*-Les Tokens--*/
%token mc_lang <typeG>id mc_fin mc_dec mc_fdec mc_deb
       bib_inOut bib_tab bib_arithm mc_CONST
       mc_While mc_Faire mc_Fait mc_EXECUT mc_IF
       <typeG>mc_IntVal <typeG>mc_ReelVal <typeG>mc_StringVal
       mc_int mc_float mc_string mc_vardec
       mc_input mc_Output aff
       ',' '(' ')' '[' ']'

%left '+' '-'
%left '*' '/'
%left '>' '<' '=' leOp geOp neOp
%left moin

%type <typeG> EXP
%type <typeG> VAL
%type <typeG> IDF
%type <SauvType> TYPE
/*%type <typeG> ALLVARS
*/

%%
s:mc_lang id mc_dec BIB VAR mc_fdec mc_deb INST mc_fin {
  printf(GRN "\n->[SYNTAXE_CORRECTE] %d%d%d" RESET,decBIB[0],decBIB[1],decBIB[2]);}
 ;
BIB :bib_inOut BIB      { decBIB[0] = 1; }
    |bib_tab BIB        { decBIB[1] = 1; }
    |bib_arithm BIB     { decBIB[2] = 1; }
    |
    ;
INST:INST_AFF INST  /*tout les instruction*/
    |BOUCLE INST
    |IF INST
    |INPUT INST
    |OUTPUT INST
    |
    ;
INST_AFF:IDF aff EXP ';'  { MAJval($1,$3);
                            Quadr(":=",$3->NmEntt,"___",$1->NmEntt); }
        ;

IDF:id                    { getIDF(&$$,$1); }
   |id '[' IDF ']'
   |id '[' mc_IntVal ']'  { getIDF2(&$1,$$,$3->entier);}
   ;

VAL:mc_IntVal     { $$ = $1 ; }
   |mc_ReelVal    { $$ = $1 ; }
   |mc_StringVal  { $$ = $1 ; }
   ;
VAR:TYPE mc_vardec VARS ';' VAR
   |TYPE mc_vardec mc_CONST id ';' VAR  { PushERR( MAJtype($4,$1,1)); }
   |
   ;
VARS:id                            { PushERR(MAJtype($1,$<SauvType>-1,1 )); }
    |id '[' mc_IntVal ']'          { PushERR(MAJtype($1,$<SauvType>-1,$3->entier)); }
    |VARS ',' id                   { PushERR(MAJtype($3,$<SauvType>-1,1 )); }
    |VARS ',' id '[' mc_IntVal ']' { PushERR(MAJtype($3,$<SauvType>-1,$5->entier)); }
    ;

ALLVARS:ALLVARS  ',' EXP   {PushERR( afficheElt($3,decBIB[0]) );}
       |EXP                {PushERR( afficheElt($1,decBIB[0]) );}
       ;

TYPE:mc_int     { $$ = ENTIER ;}
    |mc_float   { $$ = REELE  ;}
    |mc_string  { $$ = CHAINE ;}
    ;

EXP:EXP '+' EXP         { PushERR(Operation('+',$1,$3,&$$) ); Quadr("+" ,$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP '-' EXP         { PushERR(Operation('-',$1,$3,&$$) ); Quadr("-" ,$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP '*' EXP         { PushERR(Operation('*',$1,$3,&$$) ); Quadr("*" ,$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP '/' EXP         { PushERR(Operation('/',$1,$3,&$$) ); Quadr("/" ,$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP '>' EXP         { PushERR(Operation('>',$1,$3,&$$) ); Quadr(">" ,$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP '<' EXP         { PushERR(Operation('<',$1,$3,&$$) ); Quadr("<" ,$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP '=' EXP         { PushERR(Operation('=',$1,$3,&$$) ); Quadr("=" ,$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP leOp EXP        { PushERR(Operation('L',$1,$3,&$$) ); Quadr("<=",$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP geOp EXP        { PushERR(Operation('G',$1,$3,&$$) ); Quadr(">=",$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |EXP neOp EXP        { PushERR(Operation('N',$1,$3,&$$) ); Quadr("!=",$1->NmEntt,$3->NmEntt,$$->NmEntt); }
   |'-' EXP %prec moin  { PushERR(Operation('M',$2,$2,&$$) ); Quadr("-" ,$2->NmEntt,"___",$$->NmEntt); }
   |'(' EXP ')'         { $$ = $2 ;}
   |IDF                 { getIDF(&$$,$1); }
   |VAL                 { $$ = $1;}
   ;

    /*----------------------.
    |    les Quadruplets    |
    '----------------------*/
BOUCLE:mc_While             { $<ent>$ = indiceQc ;}
      '(' EXP ')'           { $<ent>$ = indiceQc ; Quadr("BZ","",$4->NmEntt,"___");}
      mc_Faire INST mc_Fait { sprintf(tmp,"%d",$<ent>2) ; Quadr("BR",tmp,"___","___");
                              sprintf(tmp,"%d",indiceQc); ajour_Quad($<ent>6,1,tmp);}
      ;
IF:mc_EXECUT {  Quadr("BR","","___","___");   $<ent>$ = indiceQc ;   }
  INST mc_IF {  Quadr("BR","","___","___");   $<ent>$ = indiceQc ;   }
  '(' EXP ')'{    sprintf(tmp,"%d",$<ent>2);
                Quadr("BNZ",tmp,$7->NmEntt,"___");
                  sprintf(tmp,"%d",indiceQc);
                ajour_Quad($<ent>5-1,1,tmp);
                  sprintf(tmp,"%d",indiceQc-2);
                ajour_Quad($<ent>2-1,1,tmp);
             }
  ;
INPUT:mc_input '(' mc_StringVal ')' ';'{ PushERR(scanElt());}
     ;
OUTPUT:mc_Output '(' ALLVARS ')' ';'
      ;


%%
main()
{
initERROR();
yyparse();
afficher();
affQuadS();
aff_ERR_Pile();
}
yywrap(){}

int yyerror(char* msg){
  printf(RED "[ERREUR_Syntaxique]->" RESET " %s " YEL " [%d]\n" RESET ,msg,nb_lignes);
}


