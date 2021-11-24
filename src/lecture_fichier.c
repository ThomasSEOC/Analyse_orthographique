#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lecture_livre(){
  FILE* p = fopen("a_la_recherche_du_temps_perdu.txt","r");
  if(p==NULL){
    printf("Erreur de lecture");
    exit(1);
  }

  char l1[2000], l2[2000];
  fgets(l1,2000,p);
  fgets(l2,2000,p);

  int count = 0;

  for(int i=0; i<strlen(l2);i++){
    if(l2[i] == ' '){
      count ++;
    }
  } 


  //printf("%s",l2);
  printf("Nombre d'espaces : %d",count);
}

int main(){
  lecture_livre();
  return EXIT_SUCCESS ;
}
