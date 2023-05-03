#include "memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


//allocates specified amount of memory for struct. memory is zero'd
bool initMem(Mem* mem, Word mem_size){
    Byte* t = (Byte*)calloc(mem_size, sizeof(Byte));
    if (t == NULL){
        fprintf(stderr, "ERROR: Couldnt allocate memory. %s", strerror(errno));
        return false;
    } else {
        //printf("setting ptr to: %d\n", t);
        mem->m = t;
        mem->size = mem_size;
        return true;
    } 
} 

//resizes allocated memory
bool resizeMem(Mem* mem, Word newSize){
    Byte* t = mem->m;
    mem->m = (Byte*)realloc(mem->m, newSize * sizeof(Byte));
    if(mem->m == NULL){
        fprintf(stderr, "ERROR: Couldnt reallocate memory. %s", strerror(errno));
        mem->m = t;
        return false;
    } else {
        mem->size = newSize;
        return true;
    }
} 

//frees the memory and clears the structure info.
void freeMem(Mem* mem){
    free(mem->m);
    mem->size = 0;
}