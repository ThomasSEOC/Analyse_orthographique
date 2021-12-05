#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashtable.h"

#define PREMIER 13
#define MODULO 200

int puissance(int x, int y){
  int resultat=1;
    for(int i = 0; i<y;i++){
      resultat *=x;
    }
    return resultat;
}

void insere_tete(T nouveau, liste* pl){
  liste p = malloc(sizeof(*p));

  if (*pl == NULL){
    //p -> val = nouveau;
    strcpy(p -> val, nouveau);

    *pl = p;
    return;
  }

  if(p == NULL){
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    exit(EXIT_FAILURE);
  }

  strcpy(p -> val, nouveau);
  p->next = *pl ;
  *pl = p ;
}


void affiche_liste (liste l){
  liste p = l ;
  while(p != NULL){

    printf("mot : %s | ", p->val);
    p = p -> next;
  }
  printf("\n");
}

int hash (T word){
  int hash = 0;
  for (int i = 0; i < strlen(word); i++){
    hash += word[i]*puissance(PREMIER,i);
  }
  hash %= MODULO;
  return hash;
}

bool identiques(T elem_1, T elem_2){
  if(strcmp(elem_1,elem_2)==0){
    return true;
  }
  return false;
}

bool est_present(T elem, table_hachage* ht){
  int hash_value = hash(elem);
  liste l=ht->table[hash_value];
  while (l != NULL){
    if(identiques(elem,l->val)){
      return true;
    }
    l=l->next;
  }
  return false;
}

void inserer_sans_redimensionner(T element, table_hachage* ht){
  int hash_value = hash(element);
  liste l=ht->table[hash_value];
  ht->nb_elements++;
  insere_tete(element,&l);
}

void afficher_table(table_hachage* ht){
  printf("{\n");
  for(int i=0 ; i<ht->capacite ; i++)
  {
    if(ht->table[i]!=NULL)
    {
      printf("{ hash n°%d :",i);
      affiche_liste(ht->table[i]);
      printf("}\n");
    }
  }
  printf("}\n");
}




int main(){
  liste l;
  printf("hello");
  //l->val = "loic";
  char ch[10] = "hello";
  insere_tete(ch,&l);
  ch[2] = '5';
  insere_tete(ch,&l);
  insere_tete("thomas",&l);
  insere_tete("ich",&l);
  insere_tete("ekip",&l);

  affiche_liste(l);


  printf("%d hash de %s\n",hash("salut"),"salut");
  printf("%d hash de %s\n",hash("bonjour"),"bonjour");

  return EXIT_SUCCESS;
}
