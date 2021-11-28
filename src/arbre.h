#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct truc{
  char lettre;
  struct truc* freres;
  struct truc* fils;
  int fin_de_mot;
} *noeud ;


int est_present (int c,noeud liste);
noeud nouveau_noeud (char c);
noeud nouveau_frere (noeud pere, char c);
noeud recherche (noeud liste, char c);
noeud nouveau_fils (noeud pere, char c);
int compare (char* ch, noeud arbre);

int recherche_arbre (void);
