#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/hashtable.h"
#include "../include/lecture_hashtable.h"


int main(){
  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  table_hachage ht = generation_dico();
  //afficher_table(&ht);
  analyse_livre_hashtable(filename,ht);
  free_hashtable(&ht);
  return EXIT_SUCCESS ;
}


/*
A compiler dans "algorythme"
gcc test/test_hashtable.c src/implementation_hashtable/lecture_hashtable.c src/implementation_hashtable/hashtable.c -o bin/test_hashtable
./exe/test_hashtable

*/
