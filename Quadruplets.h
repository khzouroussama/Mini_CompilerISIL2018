          /*----------------------.
          |    les Quadruplets    |
          '----------------------*/
#ifndef S_TABLE_H 
#define S_TABLE_H

#include <string.h>
#include "Colors.h"
#include "LLC_Liste.h"


typedef enum{
  BR,
  BZ,BNZ,
  BP,BPZ,
  BM,BMZ
}Ops;

typedef struct {
    int indice;
    char Op[20];
    char Op1[100];
    char Op2[100];
    char Res[100];
}qdr;

LLC_liste quad= NULL;
LLC_liste qc   = NULL;
extern int indiceQc ;

/*
 * Def des Fonction necessaire
 */
// Compare to Quad 1 si le meme indice 0 sinon
int
CmpToQuad(void* Quadr1 ,void* Ndice);

qdr*
getQuad(LLC_liste l);

LLC_liste
RechQuad(int i);

void
Quadr(char op[] , char op1[] , char op2[] , char res[]);

void
ajour_Quad(int num_quad, int colon_quad, char val []);


void affQuad(void* q);

void affQuadS();

#endif





