#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include "arbre.h"

void lecture_livre(){
  char *filename  = "a_la_recherche_du_temps_perdu.txt" ;
  FILE* p = fopen(filename,"r");
  if(p==NULL){
    printf("Erreur de lecture");
    exit(EXIT_FAILURE);
  }

  char l1[5000], l2[5000];
  fgets(l1,5000,p);
  fgets(l2,5000,p);

  char *ligne;
  char *pch;
  pch = strtok(l2," ");
  while(pch != NULL){
    printf("%s\n",pch);
    pch = strtok(NULL," ");
  }
  printf("Ligne : %s",ligne);

}

// void traite_char(char* c){
//   for(int i=0 ; i<strlen(c) ; i++){
//     c[i]=tolower(c[i]);
//     if(c[i]< 97 || c[i]>122){
//       c[i] = ' ';
//     }
//   }
//   char *pch;
//   pch = strtok(c," ");
//
//   while(pch != NULL){
//     printf("<%s>\n",pch);
//     pch = strtok(NULL," ");
//   }
//
// }

void test_lecture(){
  //Ouverture du fichier en mode "lecture seule"
  //const char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  const char* filename = "text_test.txt" ;

  FILE *p = fopen(filename, "r");
  if (p==NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
  }


  char file_contents[30];
  // On récupère dans file contents les chaines de caractères sépaérées par un espace les unes après les autres
  while (fscanf(p, "%[^\n ] ", file_contents) != EOF) {
    //printf(">%s\n",file_contents);

    for(int i=0 ; i<strlen(file_contents) ; i++){
      file_contents[i]=tolower(file_contents[i]); // Le dictionnaire étant écrit en lettre minuscule, s'assure d'avoir toutes les lettres en minuscule grace à la fonction tolower
      if(file_contents[i]< 97 || file_contents[i]>122){
        //On traite ici les "séparateurs", la ponctutatuion, les traites d'union, etc... en les remplacant par un espace
        // Exemple : "peut-etre" devient "peut etre"
        file_contents[i] = ' ';
      }
    }

    // une fois les séparateurs enlevés, nous traitons "mot-à-mot" les chaines de caractère en les séparants sur les espacees
    char *pch;
    pch = strtok(file_contents," ");

    while(pch != NULL){
      // On a donc accès dans cette boucle aux mots un à un
      // Exemple : pour file_contents = "peut etre", on aura accès dans le while à "peut", puis à "etre" à l'itération suivante
      printf(">%s ",pch);
      if(recherche_arbre(pch)){
        //printf("existe.\n");
      }
      else{
        //printf("n'existe pas\n");
      }
      pch = strtok(NULL," ");
    }
  }
  printf("\nterminado\n");
  fclose(p);
}







int main(){
  // char b[14] = "%Hello;world#";
  // printf("%s\n",b);
  // traite_char(b);
  // printf("%s\n",b);
  test_lecture();
  return EXIT_SUCCESS ;

}
