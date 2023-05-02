#ifndef MY6502_CPU
#define MY6502_CPU

// http://www.6502.org/users/obelisk/

#include "data.h"

typedef struct {
    Word PC;
    Word SP;
    Byte A, X, Y;

    Byte C : 1;
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

} CPU;

#endif