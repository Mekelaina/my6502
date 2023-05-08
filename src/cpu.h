#ifndef MY6502_CPU
#define MY6502_CPU

// http://www.6502.org/users/obelisk/

#include "datatype.h"


#define RESET_VECTOR 0xFFFC
#define STACK_TOP 0x01FF
#define STACK_BOTTOM 0

typedef struct {
    Word PC;
    Word SP;
    Byte A, X, Y;

    Byte C : 1; //carry
    Byte Z : 1; //zero
    Byte I : 1; //interupt disable
    Byte D : 1; //decimal
    Byte B : 1; //break
    Byte V : 1; //overflow
    Byte N : 1; //sign flag

} CPU;



#endif //MY6502_CPU