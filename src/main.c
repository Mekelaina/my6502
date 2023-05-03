#include <stdio.h>

#include "memory.h"
#include "romloader.h"

int main() {

    
    Mem mptr; 
    loadrom(&mptr, "/home/azura/programming/my6502/rom/testrom.my6502");

    return 0;
}

