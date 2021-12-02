#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include "arbre.h"
#include "list.h"




void analyse_livre(){
  //Ouverture du fichier en mode "lecture seule"
  const char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  //const char* filename = "text_test.txt" ;

  FILE *p = fopen(filename, "r");
  if (p==NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
  }


  char file_contents[30];

  liste mots_absents = malloc(sizeof(*mots_absents));
  mots_absents->value = "FIN DE LA LISTE";
  int cpt=0;

  // On fait l'arbre:
  noeud arbre = creation_arbre();

  // On récupère dans file_contents les chaines de caractères sépaérées par un espace les unes après les autres
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
    pch = strtok(file_contents," \0");
    while(pch != NULL){
      // On a donc accès dans cette boucle aux mots un à un
      // Exemple : pour file_contents = "peut etre", on aura accès dans le while à "peut", puis à "etre" à l'itération suivante
      //printf("<%s>\n",pch);
      if(!compare(pch, arbre)){
        printf(">%s\n",pch);
        cpt++;
      }
      pch = strtok(NULL," ");
    }
  }
  affiche(mots_absents);
  printf("\nNombre de mot n'existant pas : %d\n", cpt);
  fclose(p);
}







int main(){
  analyse_livre();
  return EXIT_SUCCESS ;

}
