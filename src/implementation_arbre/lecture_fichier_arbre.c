
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../include/arbre.h"
#include "../../include/list.h"



// Cette version du code affiche à l'écran les mots qui ne sont pas dans le dictionnaire.
// L'affichage supprime les doublons et indique le nombre de fois que chaque mot apparait
// Il affiche finalement à l'écran le nombre de mots qui ne sont pas dans le dictionnaire sans puis avec suppression des doublons.
void analyse_livre_arbre_prefixe_sans_doublons(char* filename, noeud arbre){

  FILE *p = fopen(filename, "r");
  if (p==NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
  }

  liste_abs mots_abs = NULL;
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
    word = strtok(file_contents," \0");
    while(word != NULL)
    {
      /*if (presence_abs(word, mots_abs)){
        cpt ++;
      }
      else{
        if(!compare(word, arbre))
        {
          insere_tete_abs(word,&mots_abs);
          cpt++;

        }
      }*/
      if(!compare(word, arbre)){
        cpt++;
        if (!presence_abs(word, mots_abs)){
          insere_tete_abs(word, &mots_abs);
        }
      }

      word = strtok(NULL," ");
    }
  }
  affiche_abs(mots_abs);
  printf("Nombre de mots n'étant pas dans le dictionnaire: %d\n", cpt);
  printf("Nombre de mots uniques n'étant pas dans le dictionnaire :%d\n",taille_abs(mots_abs));
  liberation_liste_abs(mots_abs);

  fclose(p);
}


// Cette version du code affiche à l'écran le nombre de mots qui ne sont pas dans le dictionnaire.
void analyse_livre_arbre_prefixe_avec_doublons(char* filename, noeud arbre){

  FILE *p = fopen(filename, "r");
  if (p==NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
  }

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
    word = strtok(file_contents," \0");
    while(word != NULL)
    {
      if(!compare(word, arbre))
      {
        cpt++;
      }
      word = strtok(NULL," ");
    }
  }

  printf("Nombre de mots n'étant pas dans le dictionnaire: %d\n", cpt);
  fclose(p);
}
