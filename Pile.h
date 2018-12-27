

typedef struct {
  LLC_liste lst;
  size_t eltSize;
}Pile;

void init_Pile(Pile *p,size_t sizeELT){
  p->eltSize=sizeELT;
  p->lst = NULL;
}

void push(Pile* p,void* val){
  if (!p->lst)
    p->lst = LLC_CrNode(val,p->eltSize);
  else {
    LLC_liste tmp = p->lst;
    p->lst = LLC_CrNode(val,p->eltSize);
    p->lst->svt = tmp;
  }
}


void* pop(Pile* p){
  LLC_liste l;
  void* tmp = NULL;
  if ( p->lst){
    l =p->lst ;
    p->lst = p->lst->svt ;
    l->svt = NULL;
    tmp = l->info;
    free(l);
    l=NULL;
  }
  return tmp;
}

void* SommetPile(Pile p){
  return (p.lst)?p.lst->info:NULL;
}

LLC_liste Pile_toLLC(Pile p){
  return p.lst;
}
