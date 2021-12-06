#ifndef ARBRE
#define ARBRE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct truc{
  char lettre;
  struct truc* freres;
  struct truc* fils;
  int fin_de_mot;
} *noeud ;

// Retourne 1 si c est présent et 0 sinon
int est_present (int c,noeud liste);

// Créer un nouveau noeud
noeud nouveau_noeud (char c);

// Ajoute un nouveau frère s'il n'y est pas déjà
noeud nouveau_frere (noeud pere, char c);

// Renvoie le noeud de la liste qui contient c
noeud recherche (noeud liste, char c);

// Ajoute un nouveau fils:
noeud nouveau_fils (noeud pere, char c);

// Vérifie si ch est dans l'arbre:
int compare (char* ch, noeud arbre);

// Libère la mémoire allouée par l'arbre
void lib_arbre(noeud arbre, noeud arbre1, noeud arbre2, char c);

//Lecture et construction de l'arbre
noeud creation_arbre (void);


#endif
