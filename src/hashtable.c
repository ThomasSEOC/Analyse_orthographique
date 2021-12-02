#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"
#include <string.h>

int hash (char* ch, int size){
  //hache le mot:
  int hash = 0;
  int n = strlen (ch);
  int i = 0;
  int c;
  for (i = 0; i < n; i++){
    c = ch[i];
    hash += c * (i+1);
  }
  hash = hash % size;
  return hash;
}
