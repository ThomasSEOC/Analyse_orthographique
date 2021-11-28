
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arbre2.h"
#include <string.h>

/*typedef struct _noeud{
  char lettre;
  noeud* freres;
  pnoeud* fils;
  int fin_de_mot;
} noeud, *pnoeud;*/

//noeud st déjà un pointeur
//retourne null si non présent
int est_present (int c,noeud liste){ //1 si oui et 0 si nn

  while (liste != NULL){

    if ((liste->lettre) == c){
      //on retourne le noeud ou il y a c
      return 1;
    }

    liste = liste -> freres;
  }
  return 0;
}

// créer un nouveau noeud:
noeud nouveau_noeud (char c){
  noeud newknot = calloc (1,sizeof (*newknot));
  newknot -> lettre = c;
  return newknot;
}

noeud nouveau_frere (noeud pere, char c){
  // si le frère est déjà dans le pere
  noeud p = pere;
  if (p == NULL){
    noeud new = calloc (1, sizeof (*new));
    new -> lettre = c;
    return (new);
  }
  while (p -> freres != NULL){
    if (p -> lettre == c){
      return pere;
    }
    p = p -> freres;
  }
  if (p -> lettre == c){
    return pere;
  }
  noeud new = calloc (1, sizeof (*new));
  new -> lettre = c;
  p -> freres = new;
  return pere;

}

noeud recherche (noeud liste, char c){
  noeud l = liste;
  while (l != NULL){
    if (l -> lettre == c){
      return l;
    }
    l = l -> freres;
  }
  printf ("Pas de noeud \n");
  return liste;
}

noeud nouveau_fils (noeud pere, char c){
  if (est_present(c, pere -> fils)){//si le fils y est déjà:
    return pere;
  }
  //printf("\nDans NV FILS: %c",c);
  //S'il n'y est pas:
  //On rajoute un frère à son fils
  pere -> fils = nouveau_frere (pere -> fils, c);
  //printf("\nET LA????%c\n", pere -> fils -> lettre);
  //On retourne le père:
  return pere;
}

int compare (char* ch, noeud arbre){
  int n = strlen (ch);
  noeud a2 = arbre;
  int i = 0;
  while (i < n){
    if ( est_present (ch[i], a2) == 0){ //si non présent
      printf ("NOOON\n");
      return 0;
    }
    printf ("maybe\n");
    //a2 devient le frr qui contient la lettre en question
    a2 = recherche (a2, ch[i]);
    //mtn il devient son fils
    a2 = a2 -> fils;
    i++;
  }
  if ((a2 -> fin_de_mot) == 1){
    printf (" OUIIIIII \n");
    return 0;
  }
  printf ("nope");
  return 0;
}


/*Lecture et construction de l'arbre*/
int main (void){
  //Ouverture fichier:
  FILE *fp = fopen ("FR.txt","r");
  noeud new;
  noeud arbre = calloc (1, sizeof (*arbre));
  arbre -> lettre = 'a';
  arbre -> fin_de_mot = 1;
  //noeud arbre;
  noeud arbreb;
  int i, size;
  char ch[30]; //la chaine qui va construire le dico de longueur 26:
  while ( fgets (ch, 30, fp) != NULL){ //toutes les chaînes qu'on lit sont dans ch et on une taille max de 26:
    //Le premier caractère de la chaîne:
    //printf ("%s", ch);

    i = 0;
    //L'arbre à un nv frère à la racine
    //printf ("yep\n");
    arbre = nouveau_frere (arbre, ch[i]);
    //printf ("yepiie\n");
    size = strlen (ch);
    //On se retrouve dans la lettre souhaitée
    arbreb = recherche (arbre, ch[i]);
    //printf ("la oui\n");
    i++;
    //printf ("%d\n\n",size);
    while (i < size){
      //création noeud:
      //ajout du frere:
      arbreb = nouveau_fils ( arbreb, ch[i]);
      //printf ("%c",ch[i]);

      //fin du mot?
      arbreb = recherche(arbreb -> fils, ch[i]);
      if (arbreb -> fin_de_mot != 1 && i < size - 1){
        arbreb -> fin_de_mot == 0;
        //printf ("mot non fini \n");
      }
      //printf ("Lettre [%c]", arbreb -> lettre);
      i++;
      //arbreb -> fin_de_mot = 0; //fin de mot
      }

      //printf ("\n mot fini \n");
      arbreb -> fin_de_mot = 1;
      //On vient de lire tout le mot.
      //Il faut passer à la chaîne suivante
      i = 0;
      //On revient dans le père de tous et on recommence
      //arbreb = arbre;
  }
  arbreb = arbre;
  //printf ("arbre de ses morts:  \n");
  /*while (arbreb != NULL){
    printf ("\npère : %c\n fils: \n", arbreb -> lettre);
    new = arbreb -> fils;
    while (new != NULL){
      printf ("%c", new -> lettre);
      new = new -> freres;
    }
    arbreb = arbreb -> freres;
  }*/
  //Maintenant, on teste:
  while (1){
    printf (" Le mot?");
    scanf ("%s", ch);
    compare (ch, arbre);
  }

  return 0;
}




/*
int main (void){
  noeud new = nouveau_noeud('a');
  new = nouveau_frere (new, 'b');
  new = nouveau_frere (new, 'c');
  new = nouveau_fils (new, 'd');
  printf ("%c %c %c", new -> lettre, new -> freres -> lettre, new -> fils -> lettre);

  printf ("ok");
  if ( est_present('a',new)){
    printf ("ouiiii\n");
  }
  free (new -> freres -> freres);
  free (new -> freres);
  free (new -> fils);
  free (new);
  return 0;

}*/
