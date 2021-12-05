
#ifndef __CONSOLE_H__
#define __CONSOLE_H__



typedef char* T;

typedef struct _cellule {
  T val;
  struct _cellule* next;
} cellule;
typedef cellule* liste;

typedef struct {
  liste* table;
  unsigned capacite; /* capacité de la table */
  unsigned nb_elements; /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;


int hash (char* ch);

#endif
