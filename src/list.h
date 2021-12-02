#ifndef LIST
#define LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cellule {
    char* value;
    int occurence ;
    struct cellule* next;
};
typedef struct cellule* liste;


void affiche (liste l);
void insere_tete(char* nouveau, liste* pl);
void insere_queue(char* nouveau, liste* pl);
bool presence(char* valeur, liste l);





#endif
