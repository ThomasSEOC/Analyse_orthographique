#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct noeud{
  char lettre;
  noeud* freres;
  noeud* fils;
  int fin_de_mot;
};

typedef struct noeud* pnoeud;
