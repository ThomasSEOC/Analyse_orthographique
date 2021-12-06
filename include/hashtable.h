
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashtable.h"


typedef char* T;

typedef struct _cellule {
  char val[26]; //T val
  struct _cellule* next;
} cellule;
typedef cellule* liste;

typedef struct {
  liste* table;
  unsigned capacite; /* capacité de la table */
  unsigned nb_elements; /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;

//affiche une liste
void display_liste (liste l);

//Renvoie le hash d'un char*
int hash (T word);

//Renvoie true si elem_1 et elem_2 sont identiques, false sinon
bool identiques(T elem_1, T elem_2);

//Renvoie true si elem est présent dans la table de hashage, false sinon
bool is_present(T elem, table_hachage* ht);

//Insere element dans la table de hachage ht sans redimensionner la table de hachage
void inserer_sans_redimensionner(T element, table_hachage* ht);

//Affiche la table de hachage
void afficher_table(table_hachage* ht);

//Libère la mémoire allouée pour la table de hachage
void free_hashtable(table_hachage* ht);

//Renvoie une nouvelle table de hachage vide
table_hachage new_hashtable(int capacite,int capacite_initiale);

//Renvoie une table de hachage contenant les mots du dictionnaire hachés selon la fonction de hashage
table_hachage generation_dico();

#endif
