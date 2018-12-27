#define NB_ERREUR_POSSIBLES 10
extern int nb_lignes;

typedef enum{

  NoERREUR,
  ERR_DIV_0,
  ERR_VAR_DOUBL_DEC,
  ERR_VAR_NON_DEC,
  ERR_TYPE_N_COMPTATIBLE,
  ERR_OPT_N_AUTORISEE,
  ERR_BIB_INOUT,
  ERR_BIB_TAB,
  ERR_BIB_ARITHM,
  ERR_INDX_TABLE

}ERREUR_TYPE;

char ERR_MSG[NB_ERREUR_POSSIBLES][50]={
  " No Erreur ",
  " Division Par zero                  ",//1
  " Identifiant doublement Declarer    ",//2
  " Variable non Declarer              ",//3
  " Type non Comptatible               ",//4
  " Cette Operation est non autoriser  ",//5
  " Absence d’une bibliothèque :InOut  ",//6
  " Absence d’une bibliothèque :TAB    ",//7
  " Absence d’une bibliothèque :ARITHME",//8
  " INdex de tableau no Autorise       "//8
};

typedef struct {
  ERREUR_TYPE Erreur;
  int NB_LIGNE;
}ERRelt;
/*
 * Touts les Erreur doivent etre stocker dans la piles
 * des Erreurs
 */

Pile ERR_Pile ;

void initERROR(){
  init_Pile( & ERR_Pile, sizeof(ERRelt));
  //printf("PileErr Init..");
}
void PushERR(ERREUR_TYPE err){
  if (err != NoERREUR ){
    ERRelt e;
    e.Erreur = err;
    e.NB_LIGNE = nb_lignes;
    push(& ERR_Pile , & e);
  }
}

void aff_ERR(void* err){
  printf(RED "[ERREUR_Sementique]" RESET "->%s " YEL "[%d]" RESET "\n"
      ,ERR_MSG[(*(ERRelt*)err).Erreur]
      ,(*(ERRelt*)err).NB_LIGNE
      ) ;
}

void aff_ERR_Pile(){
  LLC_Affiche(Pile_toLLC(ERR_Pile),aff_ERR);
}

