#ifndef DICOLISTE
#define DICOLISTE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listedge {
    char value[30];
    struct listedge* next;
};
typedef struct listedge* plistedge;








#endif
