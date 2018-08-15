#include <sstream>
#include <iomanip>

#include "include/rlc.h"

using namespace emu::z80;

std::string cb_rlc_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x00FF0000) >> 16;
//	int	nn = (value & 0x000000FF);

//printf("[cb_rlc_instruction] value = 0x%04X; opcode = 0x%04X\n", value, opcode);

//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "rlc "; 

	switch(opcode) {
        case 0x00:
			ss << "b";
			break;
        case 0x01:
			ss << "c";
			break;
        case 0x02:
			ss << "d";
			break;
        case 0x03:
			ss << "e";
			break;
        case 0x04:
			ss << "h";
			break;
        case 0x05:
			ss << "l";
			break;
        case 0x06:
			ss << "(hl)";
			break;
        case 0x07:
			ss << "a";
			break;
		default:
			ss << "?";
	}

	return ss.str();
}
