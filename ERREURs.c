
#include "ERREURs.h"

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


void PushERR(ERREUR_TYPE err){
  if (err != NoERREUR ){
    ERRelt e;
    e.Erreur = err;
    e.NB_LIGNE = nb_lignes;
    push(& ERR_Pile , & e ,sizeof(ERRelt));
  }
}

void aff_ERR(void* err){
  printf(RED "[ERREUR_Sementique]" RESET "->%s " YEL "[%d]" RESET "\n"
      ,ERR_MSG[(*(ERRelt*)err).Erreur]
      ,(*(ERRelt*)err).NB_LIGNE
      ) ;
}

void aff_ERR_Pile(){
  LLC_Affiche(ERR_Pile,aff_ERR);
}

