
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arbre.h"



//On crée un noeud mains on ne connait pas son père
//On ne sait donc pas où le placer dans la liste

struct noeud* creer_noeud(int valeur){
  pnoeud pnewn=malloc(sizeof(struct noeud));
  pnewn->valeur=valeur;
  //Pas de fils
  pnewn->gauche=NULL;
  pnewn->droite=NULL;
  return(pnewn);
}

//vérifie si l'arbre est vide
bool arbre_est_vide (arbre a){
  if (a==NULL){
    return true;
  }
  return false;
}

//Destruction recursive de l'arbre:

void detruire_arbre(arbre a){
  if (a->gauche==NULL && a->droite==NULL){
    free(a);
  }
  if (a->gauche==NULL){
    detruire_arbre(a->droite);
  }
  if (a->droite==NULL){
    detruire_arbre(a->gauche);
  }
  detruire_arbre(a->droite);
  detruire_arbre(a->gauche);
}

//fonction intermédiaire du maximum:
unsigned max(unsigned a, unsigned b){
  if (a>b){
    return a;
  }
  return b;
}


//Calcul de la hauteur de l'arbre:
unsigned hauteur (arbre a){
  if(a==NULL){
    return 0;
  }
  return (max(hauteur(a->droite), hauteur(a->gauche))+1);
}

//Calcul nb noeuds:
unsigned nb_noeuds(arbre a){
  if (arbre_est_vide(a)){
    return 0;
  }
  return(nb_noeuds(a->gauche)+nb_noeuds(a->droite)+1);
}

//calcul du nb de feuilles:
unsigned nb_feuilles(arbre a){
  if(arbre_est_vide(a)){
    return(0);
  }
  if(arbre_est_vide(a->gauche) && arbre_est_vide(a->droite)){
    //C'est une feuille
    return(1);
  }
  return(nb_feuilles(a->gauche)+nb_feuilles(a->droite));
}

//arbre=ligne horizontale?
bool arbre_est_degenere(arbre a){
  if (arbre_est_vide(a)){
    return(true);
  }
  if (a->droite!=NULL && a->gauche!=NULL){
    return(false);
  }
  return(arbre_est_degenere(a->gauche) && arbre_est_degenere(a->droite));
}

//arbre=parfait?(sans fils unique?)
bool arbre_est_parfait(arbre a){
  if(arbre_est_vide(a)){
    return true;
  }
  if (a->droite==NULL && a->gauche!=NULL){
    return false;
  }
  if (a->droite!=NULL && a->gauche==NULL){
    return false;
  }
  return(arbre_est_parfait(a->gauche) && arbre_est_parfait(a->droite));
}



//Parcours préfixé:
//racine puis fils de gauche puis de droite
void parcours_prefixe(arbre a){
  if (arbre_est_vide(a)){
    exit(1);
  }
  //On est dans la racine
  printf("%d",a->valeur);
  parcours_prefixe(a->droite);

}





//Maintenant on fait les fonctions sur les listes:



/*pnoeud ajout_noeud(int valeur, int indice, pnoeud liste_noeud){
  pnoeud newnoeud=malloc(sizeof(noeud));
  if (liste_noeud==null){

  }
}*/
