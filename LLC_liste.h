
typedef struct Elt{
	void *info;
	struct Elt *svt;
} node ;

typedef node* LLC_liste ;

int LLC_Vide(LLC_liste l){
	return l == NULL;
}

int LLC_Size(LLC_liste l){
  return (!l)?0:LLC_Size(l->svt)+1;
}


LLC_liste LLC_CrNode(void *val,size_t taille){
  LLC_liste l=(LLC_liste)malloc(sizeof(node));
  l->info = malloc(taille);
  //on copie les info byte par byte
  for (int i = 0; i < taille; i++) {
    *(char *)(l->info +i) = *(char *)(val + i);
  }
  l->svt = NULL;
  return l;
}

//return le dernier elt ajouter
LLC_liste LLC_add(LLC_liste last,void* val,size_t taille){
  LLC_liste l = LLC_CrNode(val,taille);
  if(last != NULL) last->svt = l;
  return l;
}

void LLC_Affiche(LLC_liste t,void (*ptrF)(void *)){
  for (LLC_liste w = t; w ; w=w->svt)
    (*ptrF)(w->info);
}

LLC_liste LLC_Recherche(LLC_liste l,void* val,int (*ptrF)(void *,void *)){
  for (; l ; l=l->svt)
    if ((*ptrF)(l->info,val) == 0)
      return l;
  return NULL;
}
//fonction qui faire l affichage au  sense inverse
//Comme Pile (pour afficher les Erreur)
void LLC2Pile_Affiche(LLC_liste t,void (*ptrF)(void *)){
  if(t->svt)
    LLC2Pile_Affiche(t->svt,ptrF);
  (*ptrF)(t->info);
}

