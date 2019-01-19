#ifndef ERREUR_H
#define ERREUR_H

#define NB_ERREUR_POSSIBLES 10
extern int nb_lignes;

#include "LLC_Liste.h"
#include "Colors.h"

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

typedef struct {
  ERREUR_TYPE Erreur;
  int NB_LIGNE;
}ERRelt;
/*
 * Touts les Erreur doivent etre stocker dans la piles
 * des Erreurs
 */

LLC_liste ERR_Pile ;

void PushERR(ERREUR_TYPE err);

void aff_ERR(void* err);

void aff_ERR_Pile();

#endif
