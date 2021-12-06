#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include  "../../include/dicoliste.h"


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
