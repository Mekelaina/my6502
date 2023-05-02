#include <stdio.h>
#include "memory.h"


int main() {


    //memory test

    Mem memory;

    initMem(&memory, TEST_MEM);

    printf("mem size: %d\n", memory.size);
  
    printf("The elements of the array are: ");
    for (int k = 0; k < memory.size; ++k) {
        printf("%d, ", memory.m[k]);
    }
  
    printf("\n");


    resizeMem(&memory, 64);

    printf("mem size: %d\n", memory.size);
  
    printf("The elements of the array are: ");
    for (int k = 0; k < memory.size; ++k) {
        printf("%d, ", memory.m[k]);
    }
  
    printf("\n");

    freeMem(&memory);

    return 0;
}