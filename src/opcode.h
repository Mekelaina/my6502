#ifndef MY6502_OPCODE
#define MY6502_OPCODE

#include <stdint.h>

typedef enum addressingmode {
    IMP,
    IMM,
    ZP0,
    ZPX,
    ZPY,
    REL,
    ABS,
    ABX,
    ABY,
    IND,
    IZX,
    IZY
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

static const Opcode OPCODES[256] = {
    {.name = "BRK", .mn = BRK, .mode = IMM, .cycles = 7}, {.name = "ORA", .mn = ORA,  .mode = IZX, .cycles = 6}, {.name = "???", .mn = XXX, .mode = IMP, .cycles = 2}, {.name = "???", .mn = XXX, .mode = IMPLIED, .cycles = 8 }, { .name = "???", .mn = NOP, .mode = IMP, .cycles = 3 }, {.name = "ORA", .mn = ORA, .nm = ZP0, .cycles = 3}, {.name = "ASL", .mn = ASL, .nm = ZP0, .cycles = 5}, {.name = "???", .mn = XXX, .nm = IMP, .cycles = 5}, {.name = "PHP", .mn = PHP, .nm = IMP, .cycles = 3}, {.name = "ORA", .mn = ORA, .nm = IMM, .cycles = 2}, {.name = "ASL", .mn = ASL, .nm = IMP, .cycles = 2}, {.name = "???", .mn = XXX, .nm = IMP, .cycles = 2}, {.name = "???", .mn = NOP, .nm = IMP, .cycles = 4}, {.name = "ORA", .mn = ORA, .nm = ABS, .cycles = 4}, {.name = "ASL", .mn = ASL, .nm = ABS, .cycles = 6}, {.name = "???", .mn = XXX, .nm = IMP, .cycles = 6},
    };


#endif //MY6502_OPCODE