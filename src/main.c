#include <stdio.h>

#include "memory.h"
#include "romloader.h"
#include "opcode.h"

int main() {

    //read in rom file
    Mem mptr;
    //TODO: unhardcode filepath and get as CL argument. 
    loadrom(&mptr, "/home/azura/programming/my6502/rom/testrom.my6502");

    

    return 0;
}

