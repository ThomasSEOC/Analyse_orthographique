#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/dicoliste.h"
#include "../include/lecture_dicoliste.h"

// Test de la vérification orthographique avec une liste chainée.
// Le main renvoie le nombre de mots (sans les doublons) n'étant pas dans le dictionnaire et affiche le nombre de fois que ces mots apparaissent.
// Il calcule également le temps d'exécution du programme (relatif à l'ordinateur qui exécute).

int main(){
  clock_t ti, tf;
  double temps;
  ti = clock();

  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  plistedge liste = NULL;
  liste = creation_liste(liste);

  analyse_livre_dicoliste_sans_doublons(filename,liste);

  tf = clock();
  temps = (double)(tf-ti)/CLOCKS_PER_SEC;
  printf("Temps d'exéctution  : %lf secondes \n",temps);

  return EXIT_SUCCESS ;
}
