#ifndef LECTURE_FICHIER
#define LECTURE_FICHIER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arbre.h"


// Lit un fichier texte et vérifie si ils sont ou non dans le dictionnaire francais
// La recherche dans le dictionnaire emploie la méthode de l'arbre préfixé
// Les mots qui ne sont pas dans le dictionnaire sont affichés à l'écran
void analyse_livre_arbre_prefixe(char* filename, noeud arbre);

#endif
