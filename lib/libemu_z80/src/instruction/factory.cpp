#include <stdlib.h>

#include <z80/instruction/factory.h>

#include "include/primary.h"
#include "primary/include/halt.h"
#include "primary/include/ei.h"
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
#include "primary/include/inc.h"
#include "primary/include/ex.h"

//#include "xx80xx/include/out.h"

#include "xxBITxx/include/rl.h"
#include "xxBITxx/include/rr.h"
#include "xxBITxx/include/rlc.h"
#include "xxBITxx/include/rrc.h"
#include "xxBITxx/include/srl.h"

#include "xxEXTEDxx/include/ld.h"
#include "xxEXTEDxx/include/cp.h"
#include "xxEXTEDxx/include/in.h"
#include "xxEXTEDxx/include/out.h"


using namespace emu::z80;

/*
http://z80-heaven.wikidot.com/opcode-reference-chart
*/

typedef enum {
	NOP = 0,
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
	IN,
	OUT,
	DI,
	EI,
	RLC,
	RRC,
	RL,
	RR,
	SRL,
	ED_LDx,
	ED_CPx
} intstruction_t;

int8_t	primary_instruction_map[] = {
/*       0    1   2   3    4    5    6     7     8    9    A    B     C     D    E    F */
/* 0 */	NOP,  LD, LD, INC, INC, DEC, LD,   RLCA, EX,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 1 */	DJNZ, LD, LD, INC, INC, DEC, LD,   -1,   JR,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 2 */	JR,   LD, LD, INC, INC, DEC, LD,   -1,   JR,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 3 */ JR,   LD, LD, INC, INC, DEC, LD,   -1,   JR,  -1,  LD,  DEC,  INC,  DEC, LD,  -1,
/* 4 */	LD,   LD, LD, LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 5 */	LD,   LD, LD, LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 6 */	LD,   LD, LD, LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 7 */	LD,   LD, LD, LD,  LD,  LD,  HALT, LD,   LD,  LD,  LD,  LD,   LD,   LD,  LD,  LD,
/* 8 */	-1,   -1, -1, -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 9 */	-1,   -1, -1, -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* A */	-1,   -1, -1, -1,  -1,  -1,  -1,   -1,   XOR, XOR, XOR, XOR,  XOR,  XOR, XOR, XOR,
/* B */	OR,   OR, OR, OR,  OR,  OR,  OR,   OR,   CP,  CP,  CP,  CP,   CP,   CP,  CP,  CP,
/* C */	-1,   -1, -1, -1,  -1,  -1,  -1,   RST,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  RST,
/* D */	-1,   -1, -1, OUT, -1,  -1,  -1,   RST,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  RST,
/* E */	-1,   -1, -1, EX,  -1,  -1,  -1,   RST,  -1,  -1,  -1,  EX,   -1,   -1,  XOR, RST,
/* F */	-1,   -1, -1, DI,  -1,  -1,  OR,   RST,  -1,  LD,  -1,  EI,   -1,   -1,  -1,  RST
};


int8_t	bit_instruction_map[] = {
/*       0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F */
/* 0 */  RLC, RLC, RLC, RLC, RLC, RLC, RLC, RLC, RRC, RRC, RRC, RRC, RRC, RRC, RRC, RRC,
/* 1 */  RL,  RL,  RL,  RL,  RL,  RL,  RL,  RL,  RR,  RR,  RR,  RR,  RR,  RR,  RR,  RR,
/* 2 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 3 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  SRL, SRL, SRL, SRL, SRL, SRL, SRL, SRL,
/* 4 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 5 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 6 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 7 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 8 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 9 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* A */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* B */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* C */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* D */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* E */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* F */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1
};


int8_t	extd_instruction_map[] = {
/*       0         1       2   3    4    5    6    7     8        9        A    B    C    D    E    F */
/* 0 */  -1,       -1,    -1,  -1,  -1,  -1,  -1,  -1,    -1,     -1,      -1,  -1,  -1,  -1,  -1,  -1,
/* 1 */  -1,       -1,    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
/* 2 */  -1,       -1,    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,-1,
/* 3 */  -1,       -1,    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
/* 4 */  IN,      OUT,    -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 5 */  IN,      OUT,    -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 6 */  IN,      OUT,    -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 7 */  IN,      OUT,    -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 8 */  -1,      -1,     -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 9 */  -1,      -1,     -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* A */  ED_LDx,  ED_CPx, IN, OUT,  -1,  -1,  -1,  -1,  ED_LDx,  ED_CPx,  IN,  OUT,   -1,   -1,  -1,  -1,
/* B */  ED_LDx,  ED_CPx, IN, OUT,  -1,  -1,  -1,  -1,  ED_LDx,  ED_CPx,  IN,  OUT,   -1,   -1,  -1,  -1,
/* C */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* D */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* E */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* F */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1
};


#if 0
int8_t	extd_instruction_map[] = {
/*       0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F */
/* 0 */  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
/* 1 */  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
/* 2 */  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,-1,
/* 3 */  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
/* 4 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 5 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 6 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 7 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 8 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* 9 */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* A */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* B */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* C */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* D */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* E */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1,
/* F */  -1,  -1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -1,   -1,  -1,  -1
};

#endif


emu::core::i_instruction *get_primary_instruction(uint32_t value) {
//    uint8_t value8 = ((value & 0xFF000000) >> 24);
//    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;
	uint8_t opcode = instruction::get_opcode(value);

//printf("value8 = 0x%02X; value16 = 0x%04X\n", value8, value16);

    switch(primary_instruction_map[/*value8*/opcode]) {
        case NOP:
            instruction = new nop_instruction();
            break;
        case HALT:
            instruction = new halt_instruction();
            break;
		case LD:
            instruction = new ld_instruction(/*value8, */value);
            break;
		case INC:
            instruction = new inc_instruction(value/*8*/);
            break;
		case DEC:
            instruction = new dec_instruction(value/*8*/);
            break;
        case DJNZ:
            instruction = new djnz_instruction(value/*8*/);
            break;
		case JR:
           	instruction = new jr_instruction(value/*16*/);
			break;
        case DI/*0xF3*/:
            instruction = new di_instruction();
            break;
        case EI:
            instruction = new ei_instruction();
            break;
		case RST:
            instruction = new rst_instruction(value/*8*/);
            break;
		case XOR:
            instruction = new xor_instruction(value/*8*/);
            break;
		case OR:
            instruction = new or_instruction(/*value8, */value);
            break;
		case CP:
            instruction = new cp_instruction(value/*8*/);
            break;
		case OUT:
            instruction = new out_instruction(value/*16*/);
            break;
		case EX:
            instruction = new ex_instruction(/*value8,*/ value);
            break;
    }
/*
    if(instruction == NULL) {
        switch(value16) {
			case 0:
            	instruction = new nop_instruction();
            	break;
        }
    }
*/

    return instruction;
}

emu::core::i_instruction *get_xxBITxx_instruction(uint32_t value) {
//    uint8_t value8 = ((value & 0x00FF0000) >> 16);
//    uint16_t value16 = ((value & 0x00FFFF00) >> 8);
    emu::core::i_instruction *instruction = NULL;
	uint8_t opcode = xxBITxx_instruction::get_opcode(value);

	switch(bit_instruction_map[opcode/*value8*/]) {
		case RL:
            instruction = new cb_rl_instruction(value);
            break;
		case RLC:
            instruction = new cb_rlc_instruction(value);
            break;
		case RR:
            instruction = new cb_rr_instruction(value);
            break;
		case RRC:
            instruction = new cb_rrc_instruction(value);
            break;
		case SRL:
            instruction = new cb_srl_instruction(value);
            break;
		default:
			printf("[get_xxBITxx_instruction] value = 0x%08X; opcode = 0x%02X; \n", value, opcode);
//			printf("[get_xxBITxx_instruction] value = 0x%08X; value8 = 0x%02X; value16 = 0x%04X; \n", value, value8, value16);
	}

    return instruction;
}

emu::core::i_instruction *get_DD_instruction(uint32_t value) {
//    uint8_t value8 = ((value & 0x00FF0000) >> 16);
//    uint16_t value16 = ((value & 0x00FFFF00) >> 8);
    emu::core::i_instruction *instruction = NULL;
	uint8_t opcode = instruction::get_opcode(value);

//	printf("value = 0x%08X; value8 = 0x%02X; value16 = 0x%04X\n", value, value8, value16);
	printf("value = 0x%08X; opcode = 0x%02X\n", value, opcode);



    return instruction;
}

emu::core::i_instruction *get_xxEXTEDxx_instruction(uint32_t value) {
//    uint8_t value8 = ((value & 0x00FF0000) >> 16);
//    uint16_t value16 = ((value & 0x00FFFF00) >> 8);
    emu::core::i_instruction *instruction = NULL;
	uint8_t opcode = xxEXTEDxx_instruction::get_opcode(value);

//printf("value = 0x%08X; value8 = 0x%02X; value16 = 0x%04X\n", value, value8, value16);

	switch(extd_instruction_map[/*value8*/opcode]) {
		case ED_LDx:
            instruction = new ed_ld_instruction(/*value8, */value);
			break;
		case ED_CPx:
            instruction = new ed_cp_instruction(value/*, value*/);
			break;
		case IN: 
            instruction = new ed_in_instruction(value/*, value*/);
			break;
		case OUT:
            instruction = new ed_out_instruction(value/*, value*/);
			break;
		default:
			printf("[get_xxEXTDxx_instruction] value = 0x%08X; opcode = 0x%02X; \n", value, opcode);
//			printf("[get_xxEXTDxx_instruction] value = 0x%08X; value8 = 0x%02X; value16 = 0x%04X; \n", value, value8, value16);
	}


    return instruction;
}

emu::core::i_instruction *get_FD_instruction(uint32_t value) {
//    uint8_t value8 = ((value & 0xFF000000) >> 24);
//    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;
	uint8_t opcode = instruction::get_opcode(value);

//	printf("value = 0x%08X; value8 = 0x%02X; value16 = 0x%04X\n", value, value8, value16);
	printf("value = 0x%08X; opcode = 0x%02X\n", value, opcode);

    return instruction;
}



emu::core::i_instruction *factory::get_instruction(/*emu::z80::memory_cell &cell*/uint32_t value) {
//	uint8_t	prefix = ((value & 0xFF000000) >> 24);
	emu::core::i_instruction *instruction = NULL;
	uint8_t opcode = instruction::get_opcode(value);

//printf("prefix = %02X\n", prefix);

	if(opcode == 0xCB) {
		instruction = get_xxBITxx_instruction(value);
	} else if(opcode == 0xDD) {
		instruction = get_DD_instruction(value);
	} else if(opcode == 0xED) {
		instruction = get_xxEXTEDxx_instruction(value);
	} else if(opcode == 0xFD) {
		instruction = get_FD_instruction(value);
	} else {
		instruction = get_primary_instruction(value);
	}

	if(instruction == NULL) {
		instruction = new emu::core::unknown_instruction(opcode);
	}

	// TODO Need to add exception
	return instruction;
}



