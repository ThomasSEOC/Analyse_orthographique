#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include  "list.h"



void affiche (liste l){
  liste p = l ;
  while(p->next !=NULL){
    printf("mot : %s | ", p->value);
    p=p->next;
  }
  printf("\n");
}


void insere_tete(char* nouveau, liste* pl){
  liste p = malloc(sizeof(*p));

  if(p == NULL){
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    exit(EXIT_FAILURE);
  }

  p->value = nouveau ;
  p->next = *pl ;
  *pl = p ;
}

int taille(liste l){
  int n=1;
  while(l->next != NULL){
    n++;
    l=l->next;
  }
  return n;
}


bool presence(char* valeur, liste l){
  for(liste p = l; p != NULL; p = p->next){
    if(strcmp(p->value,valeur) == 0){
      printf("Le mot '%s' est présent dans la liste\n",valeur);
      return(true);
    }
  }
  printf("Le mot '%s' n'est pas présent dans la liste\n",valeur);
  return(false);
}




// int main(){
//   liste l = malloc(sizeof(*l));
//   l->value = "loic";
//   insere_tete("hello",&l);
//   insere_tete("mme",&l);
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
