#ifndef MY6502_OPCODE
#define MY6502_OPCODE

#include <stdint.h>

typedef enum addressingmode {
    IMPLIED,
    IMMEDIATE,
    ZEROPAGE,
    ZEROPAGE_X,
    ZEROPAGE_Y,
    RELATIVE,
    ABSOLUTE,
    ABSOLUTE_X,
    ANSOLUTE_Y,
    INDIRECT,
    INDIRECT_X,
    INDIRECT_Y
} AddressingMode;

typedef enum instruction {
    ADC, AND, ASL, BCC,
	BCS, BEQ, BIT, BMI,
	BNE, BPL, BRK, BVC,
	BVS, CLC, CLD, CLI,
	CLV, CMP, CPX, CPY,
	DEC, DEX, DEY, EOR,
	INC, INX, INY, JMP,
	JSR, LDA, LDX, LDY,
	LSR, NOP, ORA, PHA,
	PHP, PLA, PLP, ROL,
	ROR, RTI, RTS, SBC,
	SEC, SED, SEI, STA,
	STX, STY, TAX, TAY,
	TSX, TXA, TXS, TYA,

    XXX //catch all for unknown ops.
} Mnemonic;

typedef struct opcode {
    char* name;
    Mnemonic mn;
    AddressingMode mode;
    uint8_t cycles;
} Opcode;


//lookup table for opcodes. format and concept taken from
//https://github.com/OneLoneCoder/olcNES/blob/master/Part%232%20-%20CPU/olc6502.cpp

static const Opcode OPCODES[256] = {{.name = "BRK", .mn =  BRK,  .mode = IMMEDIATE, .cycles = 7}, {.name = "ORA", .mn = ORA,  .mode = INDIRECT_X, .cycles = 6}, {.name = "???", .mn = XXX, .mode = IMPLIED, .cycles = 2}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};


#endif //MY6502_OPCODE