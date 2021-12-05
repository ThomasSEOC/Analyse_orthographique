#ifndef DICOLISTE
#define DICOLISTE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listedge {
    char value[30];
    struct listedge* next;
};
typedef struct listedge* plistedge;

plistedge new_maillon (char* ch);
plistedge list_add_first (plistedge maillon, plistedge liste);
int est_present_liste (plistedge liste, char *ch);
void affiche_liste (plistedge liste);
plistedge creation_liste (plistedge liste);
void liberation_liste (plistedge liste);








#endif
