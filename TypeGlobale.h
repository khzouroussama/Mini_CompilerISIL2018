/*
 * Declaration de type globale
 */

//#include <stdlib.h>
// Declaration des Erreur
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define TLU   "\x1B[36m" //Blue Claire
#define TLT   "\x1B[91m"
#define RESET "\x1B[0m"

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



