
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arbre.h"
#include <string.h>

//noeud est déjà un pointeur

//retourne 1 si c est présent et 0 si nn:
int est_present (int c,noeud liste){

  while (liste != NULL){
    if ((liste -> lettre) == c){
      //on retourne le noeud ou il y a c
      return 1;
    }
    liste = liste -> freres;
  }

  //Si c n'y est pas:
  return 0;
}

// créer un nouveau noeud:
noeud nouveau_noeud (char c){
  noeud newknot = calloc (1, sizeof (*newknot));
  newknot -> lettre = c;
  return newknot;
}

//Ajoute un nouveau frère s'il n'y est pas déjà:
noeud nouveau_frere (noeud pere, char c){

  noeud p = pere;

  if (p == NULL){
    //noeud vide:
    noeud new = calloc (1, sizeof (*new));
    new -> lettre = c;
    return (new);
  }

  while (p -> freres != NULL){
    //si p a des frères:
    if (p -> lettre == c){
      return pere;
    }
    p = p -> freres;
  }

  if (p -> lettre == c){
    //s'il n'en a pas:
    return pere;
  }

  //c n'est pas dans les frères:
  noeud new = calloc (1, sizeof (*new));
  new -> lettre = c;
  p -> freres = new;
  return pere;

}

//renvoie le noeud de la liste qui contient c:
noeud recherche (noeud liste, char c){

  noeud l = liste;

  while (l != NULL){
    if (l -> lettre == c){
      return l;
    }
    l = l -> freres;
  }

  //A chaque appel, le noeud est supposé être dans la liste, ce message ne doit donc jamais s'afficher en principe.
  printf ("Pas de noeud \n");
  return liste;
}

//ajoute un nouveau fils:
noeud nouveau_fils (noeud pere, char c){
  if (est_present(c, pere -> fils)){//si le fils y est déjà:
    return pere;
  }

  //S'il n'y est pas:
  //On rajoute un frère au fils du père (= nv fils):
  pere -> fils = nouveau_frere (pere -> fils, c);

  //On retourne le père:
  return pere;
}

//vérifie si ch est dans l'arbre:
bool compare (char* ch, noeud arbre){

  int n = strlen (ch);
  noeud a2 = arbre;
  int i = 0;

  while (i < n){
    if ( est_present (ch[i], a2) == 0){ //si non présent
      //printf ("Ce mot n'est pas dans le dictionnaire\n");
      return false;
    }

    //a2 devient le frère qui contient la lettre en question:
    a2 = recherche (a2, ch[i]);

    //mtn il devient son fils
    a2 = a2 -> fils;
    i++;
  }

  if ((a2 -> fin_de_mot) == 1){
    //printf ("Ce mot est dans le dictionnaire ");
    return true;
  }

  //printf ("Ce mot n'est pas dans le dictionnaire, il manque des lettres\n");
  return false;
}

//Libération de l'arbre:



/*Lecture et construction de l'arbre*/
bool recherche_arbre (char *word){
  //Ouverture fichier:
  FILE *fp = fopen ("FR.txt","r");
  noeud new;
  noeud arbre = NULL;
  noeud arbreb;
  int i, size;
  char ch[30]; //la chaine qui va construire le dico de longueur 30:

  while ( fgets (ch, 30, fp) != NULL){ //toutes les chaînes qu'on lit sont dans ch et on une taille max de 30:

    i = 0;
    //L'arbre à un nv frère à la racine:
    arbre = nouveau_frere (arbre, ch[i]);

    size = strlen (ch);
    //On se retrouve dans la lettre souhaitée
    arbreb = recherche (arbre, ch[i]);
    i++;

    //On met la fin du mot dans l'arbre:
    while (i < size){

      //ajout du fils:
      arbreb = nouveau_fils ( arbreb, ch[i]);

      //fin du mot?
      arbreb = recherche(arbreb -> fils, ch[i]);
      if (arbreb -> fin_de_mot != 1 && i < size - 1){
        // Si on est ici, le mot n'est pas fini
        arbreb -> fin_de_mot = 0;
        }

      i++;
      }

      arbreb -> fin_de_mot = 1;
      //On vient de lire tout le mot.

      //Il faut passer à la chaîne suivante
      i = 0;
      //On revient dans le père de tous et on recommence
  }
  arbreb = arbre;

  // //Maintenant, on teste:
  // while (1){
  //   //Le mot à rentrer:
  //   printf (" Le mot?\n");
  //   scanf ("%s", ch);
  //
  //   //Comparaison avec le dictionnaire:
  //   compare (ch, arbre);
  // }

  return compare(word,arbre);
}
