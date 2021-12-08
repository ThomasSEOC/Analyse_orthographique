#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/hashtable.h"

#define MODULO 100000 // taille de la table
#define PREMIER 3


int puissance(int x, int y){
  int resultat=1;
    for(int i = 0; i<y;i++){
      resultat *=x;
    }
    return resultat;
}



void insere_tete_classique(T nouveau, liste* pl){
  liste p = malloc(sizeof(*p));

  if (*pl == NULL){
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
}



unsigned long hash (T word){
  unsigned long hash = 0;
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
  unsigned long hash_value = hash(elem);
  liste l = ht->table[hash_value];
  while (l != NULL){
    if(identiques(elem,l->val)){
      return true;
    }
    l=l->next;
  }
  return false;
}



void inserer_sans_redimensionner(T element, table_hachage* ht){
  unsigned long hash_value = hash(element);
  ht->nb_elements++;
  insere_tete_classique(element,&ht->table[hash_value]);
}



void afficher_table(table_hachage* ht){
  printf("{\n");
  for(unsigned long i=0 ; i<ht->capacite ; i++)
  {
    if(ht->table[i]!=NULL)
    {
      printf("\nHash n°%ld :",i);
      display_liste(ht->table[i]);
      printf("\n");
    }
  }
  printf("}\n");
}



void liberation_liste (liste l){
  liste p = l;
  while (p != NULL){
    p = l -> next;
    free (l);
    l = p;
  }
}



void free_hashtable(table_hachage* ht){
  for(int i=0; i<ht->capacite;i++){
    liberation_liste(ht->table[i]);
    //Libérer la liste (et non le maillon)
  }
  free(ht->table);
}



 table_hachage new_hashtable(int capacite){
   table_hachage ht;
   ht.capacite = capacite;
   ht.nb_elements = 0;
   ht.table = calloc(ht.capacite,sizeof(liste));
   for(int i=0 ; i<ht.capacite ; i++){
     ht.table[i] = NULL;
   }
   return ht;
}



table_hachage generation_dico(){
  table_hachage ht = new_hashtable(MODULO);
  FILE *p = fopen ("FR.txt","r");
  char ch[30];
  while ( fgets (ch, 30, p) != NULL){
    if(ch[strlen(ch)-1] == '\n'){
      ch[strlen(ch)-1] = '\0';
    }
    inserer_sans_redimensionner(ch,&ht);
  }
  fclose(p);
  return(ht);
}
