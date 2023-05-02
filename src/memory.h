#ifndef MY6502_MEMORY
#define MY6502_MEMORY

#include "datatype.h"

/*
* a simple dynamic array struct and implementation so the emulator can have chunks of memory of any size.
* 64k is to be used for the main operation of the virtual cpu.
*/

//TODO: load and save memory to a file

#define MAX_MEM 1024 * 64 //64 Kilobytes
#define TEST_MEM 1024 * 1 //1 Kilobyte

typedef struct {
    Word size;
    Byte *m;    
} Mem;

//allocates specified amount of memory for struct. memory is zero'd
void initMem(Mem* mem, Word size); 

//resizes allocated memory
void resizeMem(Mem* mem, Word newSize); 

//frees the memory and clears the structure info.
void freeMem(Mem* mem); 

#endif //MY6502_MEMORY