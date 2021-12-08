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
typedef struct cellule* liste_abs;

//Affiche une liste
void affiche_abs (liste_abs l);

//Ajoute un char* en tête de liste
void insere_tete_abs(char* nouveau, liste_abs* pl);

//Renvoie un booléen : true si 'valeur' est dans la liste l, false sinon
bool presence_abs(char* valeur, liste_abs l);

//Renvoie la taille d'une liste
int taille_abs(liste_abs l);

//Libere la mémoire allouée pour une liste chainée
void liberation_liste_abs (liste_abs l);



#endif
