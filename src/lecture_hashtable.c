
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "hashtable.h"
#include "lecture_hashtable.h"




void analyse_livre_hashtable(char* filename, table_hachage ht){

  FILE *p = fopen(filename, "r");
  if (p==NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
  }

  liste mots_abs = NULL;
  char file_contents[30];
  int cpt=0; // Compte le nombre de mots n'étant pas dans le dictionnaire

  // A l'aide d'une boucle while et de la fonction fscanf, nous parcourons l'ensemble du livre en s'arrêtant à chaque espace
  // On récupère dans file_contents les chaines de caractères sépaérées par un espace les unes après les autres

  while (fscanf(p, "%[^\n ] ", file_contents) != EOF) {

    // Le dictionnaire étant écrit en lettre minuscule, s'assure d'avoir toutes les lettres en minuscule avec tolower()
    // On traite ici les "séparateurs", la ponctutatuion, les traites d'union, etc... en remplacant tout ce qui n'est pas une lettre
    // minuscule par un espace.
    // Exemple : "Peut-etre." devient "peut etre "
    for(int i=0 ; i<strlen(file_contents) ; i++)
    {
      file_contents[i]=tolower(file_contents[i]);
      if(file_contents[i]< 97 || file_contents[i]>122)
      {
        file_contents[i] = ' ';
      }
    }

    // Une fois les séparateurs enlevés, nous traitons "mot-à-mot" les chaines de caractère en les séparants sur les espaces avec strtok()
    // On a donc accès dans cette boucle aux mots un à un
    // Exemple : pour "peut etre ", on aura accès dans le while à "peut", puis à "etre" à l'itération suivante
    // C'est dans cette boucle while qu'on vérifie si le mot obtenu est dans l'arbre
    char *word;
    liste l;
    word = strtok(file_contents," \0");
    while(word != NULL)
    {
      // if(!is_present(word,&ht))
      // {
      //   printf("%s | ", word);
      //   //insere_tete(word,&mots_abs);
      //   cpt++;
      // }
      printf("%s | ", word);
      word = strtok(NULL," ");
    }
  }
  //affiche(mots_abs);
  printf("\nNombre de mot n'existant pas : %d\n", cpt);
  fclose(p);
}

int main(){
  char* filename = "a_la_recherche_du_temps_perdu.txt" ;
  table_hachage ht = generation_dico();
  afficher_table(&ht);
  //analyse_livre_hashtable(filename,ht);
  return EXIT_SUCCESS ;
}
