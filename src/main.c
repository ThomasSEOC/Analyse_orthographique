#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arbre.h"
#include "dicoliste.h"
#include "lecture_fichier.h"
#include "hashtable.h"
#include "lecture_hashtable.h"



int main(){
  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  // noeud arbre = creation_arbre();
  // analyse_livre_arbre_prefixe(filename,arbre);

  table_hachage ht = generation_dico();
  analyse_livre_hashtable(filename,ht);
  return EXIT_SUCCESS ;
}
