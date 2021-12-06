
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


void display_liste (liste l);

int hash (T word);

bool identiques(T elem_1, T elem_2);

bool is_present(T elem, table_hachage* ht);

void inserer_sans_redimensionner();

void afficher_table(table_hachage* ht);

void free_hashtable(table_hachage* ht);

table_hachage new_hashtable(int capacite,int capacite_initiale);

table_hachage generation_dico();

#endif
