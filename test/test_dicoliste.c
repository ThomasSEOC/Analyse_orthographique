#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/dicoliste.h"
#include "../include/lecture_dicoliste.h"


int main(){
  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  plistedge liste = NULL;
  liste = creation_liste(liste);
  analyse_livre_dicoliste(filename,liste);
  return EXIT_SUCCESS ;
}

/*
A compiler dans "algorythme"
gcc src/implementation_dicoliste/test_dicoliste.c src/implementation_dicoliste/dicoliste.c src/implementation_dicoliste/lecture_dicoliste.c src/list.c -o exe/test_dicoliste

./exe/test_dicoliste

*/
