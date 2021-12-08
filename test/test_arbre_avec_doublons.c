#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/arbre.h"
#include "../include/lecture_fichier_arbre.h"

// Test de la vérification orthographique avec un "arbre préfixe".
// Le main renvoie le nombre de mots (en comptant les doublons) n'étant pas dans le dictionnaire.
// Il calcule également le temps d'exécution du programme (relatif à l'ordinateur qui exécute).

int main(){
  clock_t ti, tf;
  double temps;
  ti = clock();

  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  noeud arbre = creation_arbre();

  analyse_livre_arbre_prefixe_avec_doublons(filename,arbre);

  tf = clock();
  temps = (double)(tf-ti)/CLOCKS_PER_SEC;
  printf("Temps d'exéctution  : %lf secondes \n",temps);

  return EXIT_SUCCESS ;
}
