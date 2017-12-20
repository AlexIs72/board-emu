#include "include/immediate.h"


typedef union {
    uint32_t    raw;
    struct {
                            //  ooooooss sssttttt iiiiiiii iiiiiiii
        uint16_t i : 16;    //  i   16  Immediate data. These 16 bits of immediate data are interpreted differently for different instructions.
                            //          2's-complement encoding is used to represent a number between -2(15) and 2(15-1).
        uint16_t t : 5;     //  t   5   Second register, in the range 0-31.
        uint16_t s : 5;     //  s   5   First register, in the range 0-31.
        uint16_t o : 6;     //  o   6   Instruction opcode. Determines which operation is to be performed. Values for this field are documented in the tables at the bottom of this page.
    }   format;
} immediate_type_format_t;


using namespace emu::mips;

emu::core::i_instruction *immediate_instruction::get(__attribute__((unused)) emu::mips::memory_cell &cell) {
	immediate_type_format_t tf;	

	tf.raw = cell.value();

	switch(tf.format.o) {
		default:
			break;
	}


    return new immediate_instruction(cell);
}

