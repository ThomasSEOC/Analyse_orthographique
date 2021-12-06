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


void display_liste (liste l){
  liste p = l ;
  while(p != NULL){

    printf("%s | ", p->val);
    p = p -> next;
  }
  //printf("\n");
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

bool is_present(T elem, table_hachage* ht){
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
  ht->nb_elements++;
  insere_tete(element,&ht->table[hash_value]);
}

void afficher_table(table_hachage* ht){
  printf("{\n");
  for(int i=0 ; i<ht->capacite ; i++)
  {
    if(ht->table[i]!=NULL)
    {
      printf("\nHash n°%d :",i);
      display_liste(ht->table[i]);
      printf("\n");
    }
  }
  printf("}\n");
}

void free_hashtable(table_hachage* ht){
  for(int i=0; i<ht->capacite;i++){
    free(ht->table[i]);
    //Libérer la liste (et non le maillon)
  }
  free(ht->table);
}

 table_hachage new_hashtable(int capacite,int capacite_initiale){
   table_hachage ht;
   ht.capacite = capacite;
   ht.capacite_initiale = capacite_initiale;
   ht.nb_elements = 0;
   ht.table = calloc(ht.capacite,sizeof(liste));
   for(int i=0 ; i<ht.capacite ; i++){
     ht.table[i] = NULL;
   }
   return ht;
}

table_hachage generation_dico(){
  table_hachage ht = new_hashtable(200,200);
  FILE *p = fopen ("FR.txt","r");
  char ch[30];
  while ( fgets (ch, 30, p) != NULL){
    if(ch[strlen(ch)-1] == '\n'){
      ch[strlen(ch)-1] = '\0';
    }
    inserer_sans_redimensionner(ch,&ht);
  }
  return(ht);
}



// int main(){
//   printf("Début\n");
//   table_hachage ht = generation_dico();
//   afficher_table(&ht);
//   printf("%d\nFin\n",ht.nb_elements);
//
//   return EXIT_SUCCESS;
// }
