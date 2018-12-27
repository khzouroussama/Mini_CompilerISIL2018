/*-----------------------------.
|      la table des Symbole    |
'------------------------------*/
extern int nb_lignes;

typedef struct {
    char NomEntt[20];
    char CodEntt[20];
    Etype TypeEntt;
    typeG Valeur;
} TypeTS;
// la tete de la liste
LLC_liste ts = NULL ;
// Entite Querant pou garder le dernier
//      Elt Ajouter a la list
LLC_liste EnttQ = NULL ;
// ---------------------
int comparTo(void* ts1,void* nomEntt){
  return strcmp( (*(TypeTS*)ts1).NomEntt , *(char**)nomEntt ) ;
}

TypeTS* getInfo(LLC_liste elt){
  return ((TypeTS*)(elt->info));
}
//---------------------

LLC_liste Recherche(char nEntt[]){
  return LLC_Recherche(ts,&nEntt,comparTo);
}

void inserer(char entite[],char code[],typeG val){
  if ( ! Recherche(entite) ){
    TypeTS *t =(TypeTS*)malloc(sizeof(TypeTS));
    strcpy(t->NomEntt,entite);
    strcpy(t->CodEntt,code);
    t->Valeur =val;
    t->TypeEntt=val->isType;
    if (!ts)
      ts = EnttQ = LLC_add(EnttQ,t,sizeof(TypeTS));
    else
      EnttQ = LLC_add(EnttQ,t,sizeof(TypeTS));
  }
}

int comparParVal(void* ts1,void* t){
  return ((TypeTS*)ts1)->Valeur != (*(typeG*)t);
}

ERREUR_TYPE MAJtype(typeG elt,Etype type,int size){
  LLC_liste l = LLC_Recherche(ts,&elt,comparParVal) ;
  if ( l ){
      getInfo(l)->TypeEntt = type;
      if (size == 1) {
          getInfo(l)->Valeur->isType =type;
      }
      else {
        getInfo(l)->Valeur=cr_Tab(getInfo(l)->NomEntt,size);
        setTABtype(getInfo(l)->Valeur,type);
      }
  }else return ERR_VAR_DOUBL_DEC;
  return NoERREUR;
}
/*
 * l'affectation
 * */
void MAJval(typeG elt,typeG elt2){
  LLC_liste l = Recherche (elt->NmEntt);
  if( l )
    PushERR(Operation('A',elt2,elt2,&(getInfo(l)->Valeur)));
}

/*
 * fonction qui recuperer la valeur d un IDF elt2
 *      est sauvgarder dans elt1 */
void getIDF(typeG *elt1,typeG elt2){
  if(getInfo(Recherche(elt2->NmEntt))->TypeEntt != VOID )
     (*elt1) = (getInfo(Recherche(elt2->NmEntt))->Valeur);
  else PushERR(ERR_VAR_NON_DEC);
}

void getIDF2(typeG *elt1,typeG elt2,int pos){
  getIDF(elt1,elt2);
  printf("%d/%d\n", (*elt1)->entier,pos);
  if (pos > (*elt1)->entier || pos < 0)
    PushERR(ERR_INDX_TABLE);
  else{
  //*elt1=(*elt1)->tab[pos];
  }
}


void aff_TypeTS(void* elt){
  printf(YEL "\t|" RESET "%-10s" YEL " | " RESET "%-12s" YEL " | " RESET "%-14s" YEL "|" RESET "%9d" YEL "|\n" RESET,
      (*(TypeTS*)elt).NomEntt , (*(TypeTS*)elt).CodEntt , NomTYP[(*(TypeTS*)elt).TypeEntt],
      ((*(TypeTS*)elt).Valeur->isType == TABLE)?(*(TypeTS*)elt).Valeur->entier:1);
}

void afficher(){
  printf(BLU "\n\t ********** Table des symboles ************\n" RESET);
  printf(YEL "\t ____________________________________________________ \n"YEL);
  printf("\t|" RESET TLU " NomEntite " YEL "| " TLU " CodeEntite  " YEL "|  " TLU "TypeEntite  " YEL " |" TLU "Taille  " YEL " |\n");
  printf("\t|___________|______________|_______________|_________|" RESET "\n");
  LLC_Affiche(ts,aff_TypeTS);
  printf(YEL "\t|___________|______________|_______________|_________|" RESET "\n\n");
}


