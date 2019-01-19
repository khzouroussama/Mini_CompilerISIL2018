/*-----------------------------.
|      la table des Symbole    |
'------------------------------*/
#ifndef S_TABLE_H 
#define S_TABLE_H

#include <string.h>
#include "TypeGlobale.h"
#include "OperationTypeG.h"
#include "ERREURs.h"

extern int nb_lignes;

typedef struct {
    char NomEntt[20];
    char CodEntt[20];
    Etype TypeEntt;
    typeG Valeur;
} TypeTS;
// ---------------------
int comparTo(void* ts1,void* nomEntt);

TypeTS* getInfo(LLC_liste elt);
//---------------------

LLC_liste Recherche(char nEntt[]);

void inserer(char entite[],char code[],typeG val);

int comparParVal(void* ts1,void* t);

ERREUR_TYPE MAJtype(typeG elt,Etype type,int size);
/*
 * l'affectation
 * */
void MAJval(typeG elt,typeG elt2);
/*
 * fonction qui recuperer la valeur d un IDF elt2
 *      est sauvgarder dans elt1 */
void getIDF(typeG *elt1,typeG elt2);

void getIDF2(typeG *elt1,typeG elt2,int pos);

void aff_TypeTS(void* elt);

void afficher();

#endif

