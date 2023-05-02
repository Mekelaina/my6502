#include "memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

//allocates specified amount of memory for struct. memory is zero'd
void initMem(Mem* mem, Word mem_size){
    Byte* t = (Byte*)calloc(mem_size, sizeof(Byte));
    if (t == NULL){
        fprintf(stderr, "ERROR: Couldnt allocate memory. %s", strerror(errno));
    } else {
        //printf("setting ptr to: %d\n", t);
        mem->m = t;
        mem->size = mem_size;
    } 
} 

//resizes allocated memory
void resizeMem(Mem* mem, Word newSize){
    Byte* t = mem->m;
    mem->m = (Byte*)realloc(mem->m, newSize * sizeof(Byte));
    if(mem->m == NULL){
        fprintf(stderr, "ERROR: Couldnt reallocate memory. %s", strerror(errno));
        mem->m = t;
    } else {
        mem->size = newSize;
    }
} 

//frees the memory and clears the structure info.
void freeMem(Mem* mem){
    free(mem->m);
    mem->size = 0;
}