          /*----------------------.
          |    les Quadruplets    |
          '----------------------*/

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
CmpToQuad(void* Quadr1 ,void* Ndice){
  return (*(qdr*)Quadr1).indice != *(int*)Ndice;
}

qdr*
getQuad(LLC_liste l){
  return ((qdr*)(l->info));
}

LLC_liste
RechQuad(int i){
  return LLC_Recherche(quad,&i,CmpToQuad);
}

void
Quadr(char op[] , char op1[] , char op2[] , char res[]){
  qdr q ; q.indice=indiceQc ; strcpy(q.Op,op) ;
  strcpy(q.Op1,op1) ;
  strcpy(q.Op2,op2) ;
  strcpy(q.Res,res) ;
  if (!quad )
    quad = qc =LLC_add(qc,&q,sizeof(qdr));
  else
    qc =LLC_add(qc,&q,sizeof(qdr));
  indiceQc++;
}

void
ajour_Quad(int num_quad, int colon_quad, char val []){
        LLC_liste l = RechQuad(num_quad) ;
     if ( colon_quad == 0 ) strcpy(getQuad(l)->Op , val);
else if ( colon_quad == 1 ) strcpy(getQuad(l)->Op1 , val);
else if ( colon_quad == 2 ) strcpy(getQuad(l)->Op2 , val);
else if ( colon_quad == 3 ) strcpy(getQuad(l)->Res , val);
}


void affQuad(void* q){
  printf(BLU "\t %3d " GRN "-(" RED " %3s  " GRN "," RESET "%5s  " GRN "," RESET "%5s  " GRN "," RESET "%5s  " GRN ")\n" RESET ,
          (*(qdr*)q).indice , (*(qdr*)q).Op , (*(qdr*)q).Op1 , (*(qdr*)q).Op2 ,(*(qdr*)q).Res
        );
  printf(BLU "\t ________________________________________\n" RESET );
}

void affQuadS(){
  printf(TLU "\n\t ************ Les Quadruplets ***********\n" RESET);
  LLC_Affiche(quad,affQuad);
}









