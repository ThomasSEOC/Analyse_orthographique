#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/hashtable.h"
#include "../include/lecture_hashtable.h"

// Test de la vérification orthographique avec une table de hachage.
// Le main renvoie le nombre de mots (en comptant les doublons) n'étant pas dans le dictionnaire.
// Il calcule également le temps d'exécution du programme (relatif à l'ordinateur qui exécute).

int main(){
  clock_t ti, tf;
  double temps;
  ti = clock();

  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  table_hachage ht = generation_dico();

  analyse_livre_hashtable_avec_doublons(filename,ht);
  free_hashtable(&ht);

  tf = clock();
  temps = (double)(tf-ti)/CLOCKS_PER_SEC;
  printf("Temps d'exéctution  : %lf secondes \n",temps);

  return EXIT_SUCCESS ;
}
