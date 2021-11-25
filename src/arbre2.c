
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "arbre2.h"

/*typedef struct _noeud{
  char lettre;
  noeud* freres;
  pnoeud* fils;
  int fin_de_mot;
} noeud, *pnoeud;*/

/*typedef struct liste_noeud{
  noeud* noeud;
  noeud* next;
}*pliste_noeud;*/

//retourne null si non présent
struct noeud* est_present (char c, struct noeud* liste){
  while (p != NULL){

    if ((p->lettre) == c){
      return liste;
    }
    liste = liste -> freres;
  }
  return NULL;
}

// créer un nouveau noeud:
struct noeud* ajouter_noeud (char c){
  struct noeud *newknot = malloc (sizeof (*newknot));
  newknot -> lettre = c;
  return newknot;
}

// Ajoute un fils à un noeud existant s'il n'existe pas déjà:
struct noeud* new_fils (struct noeud* pere, struct noeud* fils){
  struct noeud* enfants = pere -> fils;

  if ( est_present(fils -> lettre, enfants) != NULL){ // si la lettre est déjà dans les enfants
    return pere;
  }

  // si c n'y est pas:
  while (enfants -> freres != NULL){
    enfants = enfants -> freres;
  }

  enfants -> freres = fils;
  //Le pere à un fils de plus
  return pere;
}



struct noeud* nouveau_frere (struct noeud* pere, struct noeud* frere){
  // si le frère est déjà dans le pere
  if (est_present(frere -> lettre, pere -> freres) != NULL){
    return pere;
  }
  struct noeud* freres = pere -> freres;
  // s'il n'y est pas:
  while (freres -> next != NULL){
    freres = freres -> next;
  }
  freres -> next = frere;
  //Le pere à un fils de plus
  return pere;
}

/*Lecture et construction de l'arbre*/
void Construction_arbre (void){
  //Ouverture fichier:
  FILE *fp = fopen ("FR.txt","r");
  struct noeud *arbre;
  struct noeud* arbreb = arbre;
  int i = 0;
  char ch[26]; //la chaine qui va construire le dico:
  while ( fgets (ch, 26, fp) != NULL){ //toutes les chaînes qu'on lit sont dans ch et on une taille max de 26:
    while (ch[i] != '\n' || ch[i] != '\0'){
      //création noeud:
      struct noeud* new = ajouter_noeud ( ch[i] );
      //ajout du frere:
      arbreb = nouveau_frere ( arbreb, new);
      //fin du mot?
      if (ch[i+1] != '\n' || ch[i+1] != '\0'){
        arbreb -> fin_de_mot = 0;
      }
      else {
        arbreb -> fin_de_mot = 1; //fin de mot
      }
      //Maintenant on va dans le frère qu'on vient d'ajouter:
      arbreb = est_present(ch[i],new) -> fils;
      //arbreb devient donc le fils du new.
      //On avance dans la chaine:
      i++;
    }
    //On vient de lire tout le mot.
    //Il faut passer à la chaîne suivante
    i = 0;
    //On revient dans le père de tous et on recommence
    arbreb = arbre;
  }
  return ;
}
