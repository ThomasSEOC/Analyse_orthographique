#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/hashtable.h"
#include "../include/lecture_hashtable.h"


// Test de la vérification orthographique avec une table de hashage.
// Ce main permet de tester la méthode avec deux affichages différents (explication dans src/implementation_hashtable/lecture_hashtanle.c)
// Le main renvoie le nombre de mots n'étant pas dans le dictionnaire et le temps d'exécution du programme (relatif à l'ordinateur qui exécute)

int main(){
  clock_t ti, tf;
  double temps;
  ti = clock();

  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  table_hachage ht = generation_dico();

  // Choisir un des deux programmes : (il faut en commenter un et un seul.)
  analyse_livre_hashtable_avec_doublons(filename,ht);
  //analyse_livre_hashtable_sans_doublons(filename,ht);

  free_hashtable(&ht);

  tf = clock();
  temps = (double)(tf-ti)/CLOCKS_PER_SEC;
  printf("Temps d'exéctution  : %lf secondes \n",temps);

  return EXIT_SUCCESS ;
}


/*
A compiler dans "algorythme"
gcc test/test_hashtable.c src/implementation_hashtable/lecture_hashtable.c src/implementation_hashtable/hashtable.c -o bin/test_hashtable
./exe/test_hashtable

*/
