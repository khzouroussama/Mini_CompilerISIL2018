/*
 * Declaration de type globale
 */

//#include <stdlib.h>
#ifndef TYPE_G_H 
#define TYPE_G_H


typedef enum{
  ENTIER,
  REELE,
  CHAINE,
  BOOLEEN,
  TABLE,
  VOID
}Etype;

typedef struct tt{
    int entier;
    double reele;
    char* chaine;
    int Booleen;
    Etype isType;
    char NmEntt[20];
    struct tt **tab;
  }typeGlobale;

typedef typeGlobale* typeG;


#endif
