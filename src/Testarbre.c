#include "arbre.h"

int main(){
  arbre a=malloc(sizeof(arbre));
  struct noeud* n1=creer_noeud(1);
  struct noeud* n2=creer_noeud(2);
  struct noeud* n3=creer_noeud(3);
  struct noeud* n4=creer_noeud(4);
  struct noeud* n5=creer_noeud(5);
  struct noeud* n6=creer_noeud(6);
  struct noeud* n7=creer_noeud(7);
  struct noeud* n8=creer_noeud(8);
  struct noeud* n9=creer_noeud(9);
  struct noeud* n10=creer_noeud(10);

  a->valeur=0;
  a->gauche=n1;
  a->droite=n2;
  (a->gauche)->gauche=n3;
  (a->gauche)->droite=n4;
  (a->droite)->gauche=n5;
  (a->droite)->droite=n6;
  ((a->gauche)->gauche)->gauche=n7;
  ((a->droite)->droite)->gauche=n8;
  (((a->droite)->droite)->gauche)->gauche=n9;
  (((a->droite)->droite)->gauche)->gauche->droite=n10;

  printf("hauteur: %u, 11 noeuds? %u, 4 feuilles?: %u, dégénéré? (non): %d, parfait?(non), %d\n",hauteur(a),nb_noeuds(a),nb_feuilles(a),arbre_est_degenere(a),arbre_est_parfait(a));
  parcours_prefixe(a);
  return 0;

}
