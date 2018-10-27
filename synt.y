%token mc_lang id mc_fin mc_dec mc_fdec mc_deb bib_inOut bib_tab bib_arithm aff pvg mc_number mc_int mc_float mc_string mc_vardec mc_dCroch mc_finCroch

%%
s:mc_lang id mc_dec BIB VAR  mc_fdec mc_deb INST mc_fin {printf("synt correct");}
;
BIB :bib_inOut BIB
    |bib_tab BIB
    |bib_arithm BIB
    |
;
INST:INST_AFF
    |
;
INST_AFF:id aff id pvg
;

VAR:TYPE mc_vardec id pvg
   |TYPE mc_vardec id mc_dCroch mc_number mc_finCroch pvg
   |
;
TYPE:mc_int
    |mc_float
    |mc_string
;


%%
main()
{
yyparse();
}
yywrap(){}

