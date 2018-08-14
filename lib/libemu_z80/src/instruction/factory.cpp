#include <stdlib.h>

#include <z80/instruction/factory.h>

#include "include/primary.h"
#include "primary/include/di.h"
#include "primary/include/nop.h"
#include "primary/include/jr.h"
#include "primary/include/rst.h"
#include "primary/include/xor.h"
#include "primary/include/or.h"
#include "primary/include/cp.h"
#include "primary/include/out.h"
#include "primary/include/djnz.h"
#include "primary/include/ld.h"
#include "primary/include/dec.h"
#include "primary/include/ex.h"

#include "xx80xx/include/out.h"

using namespace emu::z80;

/*
http://z80-heaven.wikidot.com/opcode-reference-chart
*/

typedef enum {
	NOP,
	INC,
	DEC,
	EX,
	RLCA,
	DJNZ,
	LD,
	JR,
	HALT,
	XOR,
	OR,
	CP,
	RST,
	OUT,
	DI
} intstruction_t;

int8_t	primary_instruction_map[] = {
/*       0    1   2   3    4    5    6    7    8    9    A    B     C     D    E    F */
/* 0 */	NOP,  LD, LD, INC, INC, DEC, LD, RLCA, EX,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 1 */	DJNZ, LD, LD, INC, INC, DEC, LD, -1,   JR,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 2 */	JR,   LD, LD, INC, INC, DEC, LD, -1,   JR,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 3 */ JR,   LD, LD, INC, INC, DEC, LD, -1,   JR,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 4 */	LD,   LD, LD, LD,  LD,  LD,  LD, LD,   LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 5 */	LD,   LD, LD, LD,  LD,  LD,  LD, LD,   LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 6 */	LD,   LD, LD, LD,  LD,  LD,  LD, LD,   LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 7 */	LD,   LD, LD, LD,  LD,  LD,  LD, HALT, LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 8 */	-1,   -1, -1, -1,  -1,  -1,  -1, -1,   -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 9 */	-1,   -1, -1, -1,  -1,  -1,  -1, -1,   -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* A */	-1,   -1, -1, -1,  -1,  -1,  -1, -1,   XOR, XOR, XOR, XOR,  XOR,  XOR, XOR, XOR,
/* B */	OR,   OR, OR, OR,  OR,  OR,  OR, OR,   CP,  CP,  CP,  CP,   CP,   CP,  CP,  CP,
/* C */	-1,   -1, -1, -1,  -1,  -1,  -1, RST,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  RST,
/* D */	-1,   -1, -1, OUT, -1,  -1,  -1, RST,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  RST,
/* E */	-1,   -1, -1, EX,  -1,  -1,  -1, RST,  -1,  -1,  -1,  EX,   -1,   -1,  XOR, RST,
/* F */	-1,   -1, -1, DI,  -1,  -1,  OR, RST,  -1,  LD,  -1,  -1,   -1,   -1,  -1,  RST
};


emu::core::i_instruction *get_primary_instruction(uint32_t value) {
    uint8_t value8 = ((value & 0xFF000000) >> 24);
    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;

//printf("value8 = 0x%02X; value16 = 0x%04X\n", value8, value16);

    switch(primary_instruction_map[value8]) {
        case NOP:
            instruction = new nop_instruction();
            break;
/*        case 0x01:
        case 0x02:
        case 0x06:
        case 0x0a:
        case 0x0e:
        case 0x11:
        case 0x12:
        case 0x16:
        case 0x1a:
        case 0x1e:
        case 0x21:
        case 0x22:
        case 0x26:
        case 0x2a:
        case 0x2e:
        case 0x31:
        case 0x32:
        case 0x36:
        case 0x3a:
        case 0x3e:
        case 0x78:
        case 0xf9:*/
		case LD:
            instruction = new ld_instruction(value8, value);
            break;
/*		case 0x05:
		case 0x15:
		case 0x25:
		case 0x35:
		case 0x0b:
		case 0x1b:
		case 0x2b:
		case 0x3b:
		case 0x0d:
		case 0x1d:
		case 0x2d:
		case 0x3d:
*/
		case DEC:
            instruction = new dec_instruction(value8);
            break;
        case DJNZ:
            instruction = new djnz_instruction(value8);
            break;
/*		case 0x18:
		case 0x20:
		case 0x28:
		case 0x30:
		case 0x38:
*/
		case JR:
           	instruction = new jr_instruction(value16);
			break;
        case DI/*0xF3*/:
            instruction = new di_instruction();
            break;
/*        case 0xC7:
        case 0xCF:
        case 0xD7:
        case 0xDF:
        case 0xE7:
        case 0xEF:
        case 0xF7:
        case 0xFF:
*/
		case RST:
            instruction = new rst_instruction(value8);
            break;
/*		case 0xA8:
		case 0xA9:
		case 0xAA:
		case 0xAB:
		case 0xAC:
		case 0xAD:
		case 0xAE:
		case 0xAF:
		case 0xEE:*/
		case XOR:
            instruction = new xor_instruction(value8);
            break;
		case OR:
            instruction = new or_instruction(value8, value);
            break;
		case CP:
            instruction = new cp_instruction(value8);
            break;
		case OUT:
            instruction = new out_instruction(value16);
            break;
		case EX:
            instruction = new ex_instruction(value8, value);
            break;
    }

    if(instruction == NULL) {
        switch(value16) {
			case 0:
            	instruction = new nop_instruction();
            	break;
        }
    }


    return instruction;
}

emu::core::i_instruction *get_CB_instruction(uint32_t value) {
    uint8_t value8 = ((value & 0xFF000000) >> 24);
    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;

	value8++;
	value16++;

    return instruction;
}

emu::core::i_instruction *get_DD_instruction(uint32_t value) {
    uint8_t value8 = ((value & 0xFF000000) >> 24);
    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;

	value8++;
	value16++;

    return instruction;
}

emu::core::i_instruction *get_xx80xx_instruction(uint32_t value) {
    uint8_t value8 = ((value & 0xFF000000) >> 24);
    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;

	value8++;
	value16++;

    return instruction;
}

emu::core::i_instruction *get_FD_instruction(uint32_t value) {
    uint8_t value8 = ((value & 0xFF000000) >> 24);
    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;

	value8++;
	value16++;

    return instruction;
}



emu::core::i_instruction *factory::get_instruction(/*emu::z80::memory_cell &cell*/uint32_t value) {
	uint8_t	prefix = ((value & 0xFF000000) >> 24);
	emu::core::i_instruction *instruction = NULL;

//printf("prefix = %02X\n", prefix);

	if(prefix ==  0xCB) {
		instruction = get_CB_instruction(value);
	} else if(prefix ==  0xDD) {
		instruction = get_DD_instruction(value);
	} else if(prefix ==  0xED) {
		instruction = get_xx80xx_instruction(value);
	} else if(prefix ==  0xFD) {
		instruction = get_FD_instruction(value);
	} else {
		instruction = get_primary_instruction(value);
	}

	if(instruction == NULL) {
		instruction = new emu::core::unknown_instruction(prefix);
	}

	// TODO Need to add exception
	return instruction;
}



