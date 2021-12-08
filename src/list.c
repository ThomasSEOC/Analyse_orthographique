#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include  "../include/list.h"



void affiche_abs (liste_abs l){
  liste_abs p = l ;
  while(p != NULL){
    printf("Nb d'apparition de '%s' : %d\n", p->value, p -> occurence);
    p = p -> next;
  }
  printf("\n");
}


void insere_tete_abs(char* nouveau, liste_abs* pl){
  liste_abs p = malloc(sizeof(*p));
  //char *ch;
  if(p == NULL){
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    exit(EXIT_FAILURE);
  }

  strcpy(p -> value, nouveau);
  //p -> value = ch;
  p -> occurence = 1;
  p -> next = *pl ;
  *pl = p ;

  return;
}

int taille_abs(liste_abs l){
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


bool presence_abs(char* valeur, liste_abs l){
  //printf("fct pres");
  if (l == NULL){
    return false;
  }
  for(liste_abs p = l; p != NULL; p = p->next){
    if(strcmp(p->value,valeur) == 0){
      p -> occurence ++;
      //printf("Le mot '%s' est présent dans la liste\n",valeur);
      return(true);
    }
  }
  //printf("Le mot '%s' n'est pas présent dans la liste\n",valeur);
  return(false);
}

void liberation_liste_abs (liste_abs l){
  liste_abs p = l;
  while (p != NULL){
    p = l -> next;
    free (l);
    l = p;
  }
}



// int main(){
//   liste_abs l = NULL;
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
