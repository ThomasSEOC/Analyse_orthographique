#ifndef LIST
#define LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cellule {
    char value[26];
    int occurence ;
    struct cellule* next;
};
typedef struct cellule* liste;

//Affiche une liste
void affiche (liste l);

//Ajoute un char* en tête de liste
void insere_tete(char* nouveau, liste* pl);

//Ajoute un char* en fin de liste
void insere_queue(char* nouveau, liste* pl);

//Renvoie un booléen : true si 'valeur' est dans la liste l, false sinon
bool presence(char* valeur, liste l);

//Renvoie la taille d'une liste
int taille(liste l);


#endif
