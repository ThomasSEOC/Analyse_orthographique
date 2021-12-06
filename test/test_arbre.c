#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/arbre.h"
#include "../include/lecture_fichier_arbre.h"


int main(){
  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  noeud arbre = creation_arbre();
  analyse_livre_arbre_prefixe(filename,arbre);
  return EXIT_SUCCESS ;
}

/*
A compiler dans "algorythme"
gcc src/implementation_arbre/test_arbre.c src/implementation_arbre/arbre.c src/implementation_arbre/lecture_fichier_arbre.c src/list.c -o exe/test_arbre

./exe/test_arbre

*/
