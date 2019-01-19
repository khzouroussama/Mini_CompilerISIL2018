#ifndef LLC_LISTE_H
#define LLC_LISTE_H

#include <stdio.h>
#include <stdlib.h>
			
		/*-----------------------------.
		|      	  LLC   Listes         |
		|		 _______________	   |
		|  Created By :Khezour Oussama |
		'------------------------------*/

typedef struct Elt{
	void *info;
	struct Elt *svt;
} node ;

typedef node* LLC_liste ;

int LLC_Vide(LLC_liste l);
int LLC_Size(LLC_liste l);

/**	
	LLC_neGet({l},0)              --> return le derinier element 
	LLC_Get({l}, LLC_size({l})-1) --> return le derinier element 
*/
void* LLC_neGet(LLC_liste l,int index);
void* LLC_Get(LLC_liste l,int index);
/**
	Cree un Elt a partir un type donnee 
	parms  :
		{val}    : addresse de valeur a ajouter
		{taille} : la taille de l'elt ( sizeof (<monType>) )
	returns:
		new LLC_liste Object
		[remq: Cree un copie de val]
*/
LLC_liste LLC_CrNode(void *val,size_t taille);

/**
	ajouter une val a {last} 
	parms  :
		{val}    : addresse de valeur a ajouter
		{taille} : la taille de l'elt ( sizeof (<monType>) )
	returns:
		le dernier elt ajouter
	[
	remq: utiliser pour minimaliser la complexite de l'ajout a l'fin par 
			sauvgarder le dernier elt ajouter dans var(last)
	]
*/
LLC_liste LLC_add(LLC_liste last,void* val,size_t taille);

/* last elt de tete lst */
LLC_liste getLast(LLC_liste lst);

void LLC_addLast(LLC_liste *l ,void* val , size_t taille);

void push(LLC_liste* p,void* val,size_t taille);

void* pop(LLC_liste* p);

void LLC_addFirst(LLC_liste *l,void* val, size_t taille);

void LLC_Affiche(LLC_liste t,void (*ptrF)(void *));

void LLC_Affiche2(LLC_liste t,void (*ptrF)(void*),char* Listname);

//return l'adr de 1er occurence d Elt qui verifier le prediact ptrF(fonction->>boolean)
LLC_liste LLC_Recherche(LLC_liste l,void* val,int (*ptrF)(void *,void *));

int LLC_Count(LLC_liste l , void* val ,int (*ptrF)(void *,void *));

void __Swap(LLC_liste *lst1,LLC_liste *lst2);

void LLC_sort(LLC_liste *l ,int (*CmpPtrF)(void*,void*));

//fonction qui faire l affichage au  sense inverse
void LLC2Pile_Affiche(LLC_liste t,void (*ptrF)(void *));



#endif
