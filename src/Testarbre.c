#include "arbre.h"

int main(){
  noeud arbre = creation_arbre();
  int a = 1;
  while (a == 1){
    printf ("mot\n");
    char ch[50];

    scanf ("%s", ch);
    printf ("ok");
    printf ("%s", ch);
    printf ("ok2");
    if (compare(ch, arbre)){
      printf ("oui\n");
    }
    else {
      printf ("non\n");
    }
    a = 0;
  }
  return 0;

}
