#ifndef LECTURE_FICHIER
#define LECTURE_FICHIER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arbre.h"



// Cette version du code affiche à l'écran les mots qui ne sont pas dans le dictionnaire.
// L'affichage supprime les doublons et indique le nombre de fois que chaque mot apparait
// Il affiche finalement à l'écran le nombre de mots qui ne sont pas dans le dictionnaire sans puis avec suppression des doublons.
void analyse_livre_arbre_prefixe_sans_doublons(char* filename, noeud arbre);

// Cette version du code affiche à l'écran le nombre de mots qui ne sont pas dans le dictionnaire.
void analyse_livre_arbre_prefixe_avec_doublons(char* filename, noeud arbre);




#endif
