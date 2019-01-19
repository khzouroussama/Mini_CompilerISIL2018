/*
 * Header qui contien touts les operation
 * selon chaque type avec les Erreur
 * (:
 */

#include "OperationTypeG.h"
#include <string.h>


int cmptTmp=1;

char NomTYP[5][15]={
  "Entier",
  "Reele" ,
  "Chaine",
  "Booleen",
  "/"
};


/*--------------------------.
| les Fonctions de Creation |
'--------------------------*/
typeG creeTYPvide(){
  return (typeGlobale*)malloc(sizeof(typeGlobale));
}
typeG creeTYP(Etype type){
  typeG t = creeTYPvide();
  t->isType=type;
  strcpy(t->NmEntt,"");
  return t;
}

typeG creeIDF(char* nom){
  typeG t =  creeTYP(VOID);
  strcpy(t->NmEntt,nom);
  return t;
}

typeG cr_Entier(int val){
  typeG t=creeTYP(ENTIER);
  sprintf(t->NmEntt,"%d",val);
  t->entier=val;
  return t;
}

typeG cr_Reele(double val){
  typeG t=creeTYP(REELE);
  sprintf(t->NmEntt,"%.2f",val);
  t->reele=val;
  return t;
}

typeG cr_Chain(char* val){
  typeG t = creeTYP(CHAINE);
  strcpy(t->NmEntt,val);
  t->chaine = val;
  return t;
}
typeG cr_Tab(char* NmIDF,int n){
  typeG t=creeIDF(NmIDF);
  t->tab=(typeG*)malloc(n*sizeof(typeGlobale));
  for (int i = 0; i < n; i++) {
    char c[20];
    sprintf(c,"%s[%d]",NmIDF,i);
    (t->tab[i])=creeIDF(c);
  }
  t->isType=TABLE;
  t->entier=n;
  return t;
}
void setTABtype(typeG t,Etype typ){
  for (int i = 0; i < t->entier; i++){
    t->tab[i]->isType=typ;
  }
}


typeG cr_Booleen(int val){
  typeG t=creeTYP(BOOLEEN);
  strcpy(t->NmEntt,(val)?"TRUE":"FALSE");
  t->Booleen=val;
  return t;
}

/*--------------------------------------.
| les Fonctions de verification de type |
'--------------------------------------*/


Etype deType(typeG elt){
  return elt->isType;
}

int isENTIER(typeG elt){
  return deType(elt) == ENTIER;
}

int isREELE(typeG elt){
  return deType(elt) == REELE;
}
int isCHAINE(typeG elt){
  return deType(elt) == CHAINE;
}

int isBOOLEEN(typeG elt){
  return deType(elt) == BOOLEEN;
}

int hasType(typeG elt){
  return deType(elt) != VOID ;
}
int mmType(typeG op1,typeG op2){
  return deType(op1) == deType(op2) ;
}

    /*------------------------------------------.
    |   LEs Operation arethmetique el logique   |
    |          les routine Sementique           |
    '------------------------------------------*/

/* Fonction qui FAIRE l'operation est return l'ERREUR c'il ya
 * est le Constant  <NoERREUR> si il y a pas
 * la resultat sera stockee dans l'adress de <res>
 */

ERREUR_TYPE Operation(char op,typeG op1,typeG op2,typeG *res){
  if (! hasType(op1) || ! hasType(op2) )
    return ERR_VAR_NON_DEC ;
  if (!decBIB[2] && op!='A')
    return ERR_BIB_ARITHM ;
  if ( ! mmType(op1,op2) )
    return ERR_TYPE_N_COMPTATIBLE;

 switch (op) {
    case '+':
             //Addition..
             if(!isENTIER(op1) && !isREELE(op1) )
                return ERR_OPT_N_AUTORISEE;
             if (isENTIER(op1))
                *res = cr_Entier( op1->entier + op2->entier );
             if (isREELE(op1))
                *res = cr_Reele( op1->reele + op2->reele);
      break;
    case '-':
            //la soustraction..
             if (! isENTIER(op1) && !isREELE(op1))
                return ERR_OPT_N_AUTORISEE;
             if (isENTIER(op1))
                *res = cr_Entier( op1->entier - op2->entier);
             if (isREELE(op1))
                *res = cr_Reele( op1->reele - op2->reele);
      break;
    case '*':
            //la multiplication
             if (! isENTIER(op1) && !isREELE(op1))
                return ERR_OPT_N_AUTORISEE;
             if (isENTIER(op1))
                *res = cr_Entier( op1->entier * op2->entier );
             if (isREELE(op1))
                *res = cr_Reele( op1->reele * op2->reele);
      break;
    case '/':
            //la division ..
             if (!isENTIER(op1) && !isREELE(op1))
                return ERR_OPT_N_AUTORISEE;

             if (isENTIER(op2))
               if ( op2->entier == 0 )
                 return ERR_DIV_0;
               else
                *res = cr_Reele( (double)op1->entier / (double)op2->entier );
             if (isREELE(op2))
               if ( op2->reele == 0.0 )
                 return ERR_DIV_0;
               else
                *res = cr_Reele( op1->reele / op2->reele);
      break;
    case 'M':
            //  le moin
             if (! isENTIER(op1) && !isREELE(op1))
                return ERR_OPT_N_AUTORISEE;
             if (isENTIER(op1))
                *res = cr_Entier( - op1->entier);
             if (isREELE(op1))
                *res = cr_Reele ( - op1->reele  );
      break;

          //LES OPERATIONS LOGIQUE
    case '=':
            if (isENTIER(op1))
              *res =cr_Booleen( op1->entier == op2->entier );
            if (isREELE(op1))
              *res =cr_Booleen( op1->reele == op2->reele );
            if (isCHAINE(op1))
              *res =cr_Booleen(strcmp(op1->chaine,op2->chaine) == 0);
            if (isBOOLEEN(op1))
              *res =cr_Booleen( op1->Booleen == op2->Booleen );
      break;
    case 'N':
            if (isENTIER(op1))
              *res =cr_Booleen( op1->entier != op2->entier );
            if (isREELE(op1))
              *res =cr_Booleen( op1->reele != op2->reele );
            if (isCHAINE(op1))
              *res =cr_Booleen(strcmp(op1->chaine,op2->chaine) != 0);
            if (isBOOLEEN(op1))
              *res =cr_Booleen( op1->Booleen != op2->Booleen );
      break;
    case 'L':
            if (isENTIER(op1))
              *res =cr_Booleen( op1->entier <= op2->entier );
            if (isREELE(op1))
              *res =cr_Booleen( op1->reele <= op2->reele );
            if (isCHAINE(op1))
              *res =cr_Booleen(strcmp(op1->chaine,op2->chaine) <= 0);
            if (isBOOLEEN(op1))
              return ERR_OPT_N_AUTORISEE;
      break;
    case 'G':
            if (isENTIER(op1))
              *res =cr_Booleen( op1->entier >= op2->entier );
            if (isREELE(op1))
              *res =cr_Booleen( op1->reele >= op2->reele );
            if (isCHAINE(op1))
              *res =cr_Booleen(strcmp(op1->chaine,op2->chaine) >= 0);
            if (isBOOLEEN(op1))
              return ERR_OPT_N_AUTORISEE;
      break;
    case '>':
            if (isENTIER(op1))
              *res =cr_Booleen( op1->entier > op2->entier );
            if (isREELE(op1))
              *res =cr_Booleen( op1->reele > op2->reele );
            if (isCHAINE(op1))
              *res =cr_Booleen(strcmp(op1->chaine,op2->chaine) > 0);
            if (isBOOLEEN(op1))
              return ERR_OPT_N_AUTORISEE;
      break;
    case '<':
            if (isENTIER(op1))
              *res =cr_Booleen( op1->entier < op2->entier );
            if (isREELE(op1))
              *res =cr_Booleen( op1->reele < op2->reele );
            if (isCHAINE(op1))
              *res =cr_Booleen(strcmp(op1->chaine,op2->chaine) < 0);
            if (isBOOLEEN(op1))
              return ERR_OPT_N_AUTORISEE;
      break;
      //L'affictation
   case 'A':
            switch (deType(op1)) {
              case ENTIER : (*res)->entier = op1->entier ; break;
              case REELE  : (*res)->reele  = op1->reele  ; break;
              case CHAINE : (*res)->chaine = op1->chaine ; break;
              case BOOLEEN: return ERR_OPT_N_AUTORISEE   ; break;
              case  VOID  : return ERR_VAR_NON_DEC       ; break;
            }
      break;
    }
  if (op!='A'){
                sprintf((*res)->NmEntt,TLT "  T%2d" RESET,cmptTmp);
                cmptTmp++;
  }
          return NoERREUR;

  }

  ERREUR_TYPE  afficheElt(typeG elt,int inoutBIB){
    char* c;
    if (! inoutBIB)
      return ERR_BIB_INOUT;
    switch (deType(elt)) {
      case ENTIER:
               printf("%d", elt->entier);
        break;
      case REELE:
              printf("%f", elt->reele);
        break;
      case CHAINE:
              c =strdup(elt->chaine);
              c[strlen(c)-1]='\0';
              printf("%s", c+1);
        break;
      case BOOLEEN:
              printf("%s",(elt->Booleen)?"TRUE":"FALSE");
        break;
    }
    return NoERREUR;
  }

  ERREUR_TYPE scanElt(){
      if(!decBIB[0]) return ERR_BIB_INOUT;
      else return NoERREUR ;
  }
