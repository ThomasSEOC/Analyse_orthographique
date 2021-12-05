#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include  "dicoliste.h"
#include <ctype.h>


plistedge new_maillon (char* ch){
  plistedge new = calloc (1,sizeof(*new));
  strcpy(new -> value, ch);
  return new;
}

plistedge list_add_first (plistedge maillon, plistedge liste){
  maillon -> next = liste;
  return maillon;
}

int est_present_liste (plistedge liste, char *ch){// 0 si non et 1 si oui

  plistedge p = liste;

  while (p != NULL){
    if (strcmp (ch, p -> value) == 0){
      //printf("%s\n", p-> value);
      return 1;
    }
    p = p -> next;
  }
  return 0;
}

void affiche_liste (plistedge liste){
  plistedge p = liste;
  while (p -> next != NULL){
    if (p -> value == NULL){
      return;
    }
    //printf ("%s\n", p -> value);

    p = p -> next;

  }
  return ;
}


plistedge creation_liste (plistedge liste){
  printf ("oui");
  FILE *fp = fopen ("FR.txt","r");
  char ch[30];
  plistedge maillon;
  while ( fgets (ch, 30, fp) != NULL){
    //Maintenant, on traite la liste:
    int n = strlen (ch);
    int i ;
    for (i = 0; i < n ; i ++){
      if (ch[i] == '\n'){
        ch[i] = '\0';
      }
    }
    maillon = new_maillon (ch);
    //printf ("%s", maillon -> value);
    liste = list_add_first (maillon, liste);
  }
  free (fp);
  return liste;
}

void liberation_liste (plistedge liste){
  plistedge p = liste;
  //printf ("libé");
  while (p != NULL){
    //printf ("lib");
    liste = p -> next;
    free (p);
    p = liste;
  }
  return;
}


/*int main(){
  printf ("oui");
  plistedge liste = NULL;
  liste = creation_liste( liste );
  affiche_liste (liste);
  if (est_present_liste(liste, "anticonstitutionnellement")){
    printf ("bonjour présent");
  }
  else{
    printf ("error loool");
  }
  liberation_liste(liste);
  return 0;
}*/

int main(){
  plistedge liste = NULL;
  liste = creation_liste(liste);
  FILE *p = fopen("a_la_recherche_du_temps_perdu.txt", "r");
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
    word = strtok(file_contents," ");
    while(word != NULL)
    {
      if(!est_present_liste(liste, word))
      {
        printf("%s | ", word);
        cpt++;
      }
      word = strtok(NULL," ");
    }
  }
  printf("\nNombre de mot n'existant pas : %d\n", cpt);
  fclose(p);
  return 0;
}
