#include <stdlib.h>

#include <z80/instruction/factory.h>

#include "include/primary.h"
#include "primary/include/di.h"
#include "primary/include/nop.h"
#include "primary/include/jr.h"
#include "primary/include/rst.h"
#include "primary/include/xor.h"
#include "primary/include/out.h"

using namespace emu::z80;

/*
http://z80-heaven.wikidot.com/opcode-reference-chart
*/

emu::core::i_instruction *get_primary_instruction(uint32_t value) {
    uint8_t value8 = ((value & 0xFF000000) >> 24);
    uint16_t value16 = ((value & 0xFFFF0000) >> 16);
    emu::core::i_instruction *instruction = NULL;

//printf("value8 = 0x%02X; value16 = 0x%04X\n", value8, value16);

    switch(value8) {
        case 0:
            instruction = new nop_instruction();
            break;
		case 0x18:
		case 0x20:
		case 0x28:
		case 0x30:
		case 0x38:
           	instruction = new jr_instruction(value16);
			break;
        case 0xF3:
            instruction = new di_instruction();
            break;
        case 0xC7:
        case 0xCF:
        case 0xD7:
        case 0xDF:
        case 0xE7:
        case 0xEF:
        case 0xF7:
        case 0xFF:
            instruction = new rst_instruction(value8);
            break;
		case 0xA8:
		case 0xA9:
		case 0xAA:
		case 0xAB:
		case 0xAC:
		case 0xAD:
		case 0xAE:
		case 0xAF:
		case 0xEE:
            instruction = new xor_instruction(value8);
            break;
		case 0xD3:
            instruction = new out_instruction(value16);
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

emu::core::i_instruction *get_ED_instruction(uint32_t value) {
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
		instruction = get_ED_instruction(value);
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



