#include <core/instruction.h>


#include "include/primary.h"

#include "primary/include/di.h"
#include "primary/include/nop.h"

using namespace emu::z80;
/*
emu::core::i_instruction *primary_instruction::get(uint32_t value) {
	uint8_t	value8 = ((value & 0xFF000000) >> 24);
	uint16_t value16 = ((value & 0xFFFF0000) >> 16);	
	emu::core::i_instruction *instruction = NULL;

	switch(value8) {
		case 0:
			instruction = new nop_instruction();
			break;
		case 0xF3:
			instruction = new di_instruction();
			break;
	}

	if(instruction == NULL) {
		switch(value16) {
			instruction = new nop_instruction();
			break;
		}
	}


	return instruction;
}
*/


std::string opcode_to_string() {
}