#include <stdlib.h>

#include <mips/instruction/factory.h>

#include "include/cop.h"
#include "include/register.h"
#include "include/jump.h"
#include "include/immediate.h"
#include "include/simple.h"

/*
// simple type
#define     TYPE_S          'S'
#define     TYPE_R          'R'
#define     TYPE_I          'I'
#define     TYPE_J          'J'
#define     TYPE_COP        'C'
#define     TYPE_ERR        'E'
#define     TYPE_UNKNOWN    'U'
// SPECIAL3 type
#define     TYPE_S3         '3'

#define     MAX_INSTRUCTION_CODE    0x3F
*/

typedef union {
    uint32_t    raw;
//  uint8_t raw[4];
    struct {
        uint32_t dummy  : 26;
        uint32_t o      : 6;        //  o   6   Instruction opcode. Determines which operation is to be performed. Values for this field are documented in the tables at the bottom of this page.
    }   format;
} base_type_format_t;




using namespace emu::mips;

emu::core::i_instruction *factory::get_instruction(emu::mips::memory_cell &cell) {
	base_type_format_t	tf;

	tf.raw = cell.value();

    if(/*((uint32_t)(*((uint32_t*)*/tf.raw/*)))*/ == 0) {
        return /*TYPE_S*/simple_instruction::get(cell);
    }

//	printf("op = 0x%X\n", tf.format.o);
	
    if(tf.format.o == 0x00) {
        return /*TYPE_R*/register_instruction::get(cell);
    }
    else if(tf.format.o == 2 || tf.format.o == 3) {
        return /*TYPE_J*/jump_instruction::get(cell);
    }
    /*else if(op == 0x1F) {
        return MTR_3_TYPE;
    }*/
    else if((tf.format.o & 0x10) && (tf.format.o & 0x13) && tf.format.o <= 0x13/*(op & 0x11 || op & 0x12 || op & 0x13)*/) {
        return /*TYPE_COP*/cop_instruction::get(cell);
    }
    else {  // All opcodes except 000000, 00001x, and 0100xx are used for I-type instructions.
        return /*TYPE_I*/immediate_instruction::get(cell);
    }

	return new emu::core::unknown_instruction(cell);
}

/*
emu::core::i_instruction *get_simple_instruction(emu::core::memory_cell<uint32_t> &cell) {
	return new mips_simple_instruction(cell);
}

emu::core::i_instruction *get_register_instruction(emu::core::memory_cell<uint32_t> &cell) {
	return new mips_unknown_register_instruction(cell);
}

emu::core::i_instruction *get_jump_instruction(emu::core::memory_cell<uint32_t> &cell) {
	return new mips_unknown_jump_instruction(cell);
}

emu::core::i_instruction *get_cop_instruction(emu::core::memory_cell<uint32_t> &cell) {
	return new mips_unknown_cop_instruction(cell);
}

emu::core::i_instruction *get_immediate_instruction(emu::core::memory_cell<uint32_t> &cell) {
	return new mips_unknown_immediate_instruction(cell);
}
*/