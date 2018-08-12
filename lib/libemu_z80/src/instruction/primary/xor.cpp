#include <sstream>
#include <iomanip>

#include "include/xor.h"

using namespace emu::z80;

std::string xor_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x000000FF);
//	int	nn = (value & 0x000000FF);
/*
*/

//printf("value = 0x%02X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:xor

	ss  << "xor "; 

	switch(opcode) {
        case 0xA8:
			ss << "b";
			break;
        case 0xA9:
			ss << "c";
			break;
        case 0xAA:
			ss << "d";
			break;
        case 0xAB:
			ss << "e";
			break;
        case 0xAC:
			ss << "h";
			break;
        case 0xAD:
			ss << "l";
			break;
        case 0xAE:
			ss << "(hl)";
			break;
        case 0xAF:
			ss << "a";
			break;
        case 0xEE:
			ss << "x";
			break;
	}

	return ss.str();
}