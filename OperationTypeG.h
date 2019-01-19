#ifndef TYPE_G_OPS_H
#define TYPE_G_OPS_H
/*
 * Header qui contien touts les operation
 * selon chaque type avec les Erreur
 * (:
 */

#include <string.h>
#include "TypeGlobale.h"
#include "ERREURs.h"

extern char ERR_MSG[NB_ERREUR_POSSIBLES][50];
extern int decBIB[3];


/*--------------------------.
| les Fonctions de Creation |
'--------------------------*/
typeG creeTYPvide();

typeG creeTYP(Etype type);

typeG creeIDF(char* nom);

typeG cr_Entier(int val);

typeG cr_Reele(double val);

typeG cr_Chain(char* val);

typeG cr_Tab(char* NmIDF,int n);

void setTABtype(typeG t,Etype typ);

typeG cr_Booleen(int val);

/*--------------------------------------.
| les Fonctions de verification de type |
'--------------------------------------*/


Etype deType(typeG elt);

int isENTIER(typeG elt);

int isREELE(typeG elt);

int isCHAINE(typeG elt);

int isBOOLEEN(typeG elt);

int hasType(typeG elt);

int mmType(typeG op1,typeG op2);
    /*------------------------------------------.
    |   LEs Operation arethmetique el logique   |
    |          les routine Sementique           |
    '------------------------------------------*/

/* Fonction qui FAIRE l'operation est return l'ERREUR c'il ya
 * est le Constant  <NoERREUR> si il y a pas
 * la resultat sera stockee dans l'adress de <res>
 */

ERREUR_TYPE Operation(char op,typeG op1,typeG op2,typeG *res);

ERREUR_TYPE  afficheElt(typeG elt,int inoutBIB);

ERREUR_TYPE scanElt();


#endif
