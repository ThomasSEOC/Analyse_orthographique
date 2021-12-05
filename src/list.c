#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include  "list.h"



void affiche (liste l){
  liste p = l ;
  while(p != NULL){
    printf("mot : %s | : %d\n", p->value, p -> occurence);
    p = p -> next;
  }
  printf("\n");
}


void insere_tete(char* nouveau, liste* pl){
  liste p = malloc(sizeof(*p));
  //char *ch;
  if(p == NULL){
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    exit(EXIT_FAILURE);
  }

  // if (*pl == NULL){
  //   p -> value = nouveau;
  //   p -> occurence = 1;
  //   *pl = p;
  //   return;
  // }
  printf("%s\n",nouveau);
  strcpy(p -> value, nouveau);
  //p -> value = ch;
  p -> occurence = 1;
  p -> next = *pl ;
  *pl = p ;
  printf("%s\n",(*pl) -> value);

  return;
}

int taille(liste l){
  if (l == NULL){
    return 0;
  }
  int n=1;
  while(l->next != NULL){
    n++;
    l=l->next;
  }
  return n;
}


bool presence(char* valeur, liste l){
  //printf("fct pres");
  if (l == NULL){
    return false;
  }
  for(liste p = l; p != NULL; p = p->next){
    if(strcmp(p->value,valeur) == 0){
      p -> occurence ++;
      //printf("Le mot '%s' est présent dans la liste\n",valeur);
      return(true);
    }
  }
  //printf("Le mot '%s' n'est pas présent dans la liste\n",valeur);
  return(false);
}



// int main(){
//   liste l = NULL;
//   //l->value = "loic";
//   char* ch = "hello";
//   insere_tete(ch,&l);
//   //ch[1] = '2';
//   insere_tete("bonsoir",&l);
//   insere_tete("thomas",&l);
//   insere_tete("ich",&l);
//   insere_tete("ekip",&l);
//
//   affiche(l);
//   printf("Taille de la liste :%d\n",taille(l));
//
//   presence("ekip",l);
//   presence("salut",l);
//   return EXIT_SUCCESS ;
// }

/*
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
  liste mots_non_dico;
  word = strtok(file_contents," \0");
  while(word != NULL)
  {
    if (presence( word, mots_non_dico)){
      cpt ++;
    }
    else{
      if(!compare(word, arbre))
      {
        //printf("%s | ", word);
        insere_tete(word, mots_non_dico);
        cpt++;

      }
    }
    word = strtok(NULL," ");
  }
}
affiche_liste(liste);
printf("\nNombre de mot n'existant pas : %d\n", cpt);
fclose(p);
*/
