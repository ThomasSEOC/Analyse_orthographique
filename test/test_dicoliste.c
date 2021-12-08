#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/dicoliste.h"
#include "../include/lecture_dicoliste.h"

// Test de la vérification orthographique avec une liste simple.
// Ce main permet de tester la méthode avec deux affichages différents (explication dans src/implementation_hashtable/lecture_hashtanle.c)
// Le main renvoie le nombre de mots n'étant pas dans le dictionnaire et le temps d'exécution du programme (relatif à l'ordinateur qui exécute)

int main(){
  clock_t ti, tf;
  double temps;
  ti = clock();

  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  plistedge liste = NULL;
  liste = creation_liste(liste);
  // Choisir un des deux programmes : (il faut en commenter un et un seul.)
  //analyse_livre_dicoliste_avec_doublons(filename,liste);
  analyse_livre_dicoliste_sans_doublons(filename,liste);

  tf = clock();
  temps = (double)(tf-ti)/CLOCKS_PER_SEC;
  printf("Temps d'exéctution  : %lf secondes \n",temps);

  return EXIT_SUCCESS ;
}
