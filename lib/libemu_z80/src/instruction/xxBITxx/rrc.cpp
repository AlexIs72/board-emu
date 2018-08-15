#include <sstream>
#include <iomanip>

#include "include/rrc.h"

using namespace emu::z80;

std::string cb_rrc_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x00FF0000) >> 16;
//	int	nn = (value & 0x000000FF);

//printf("[cb_rrc_instruction] value = 0x%04X; opcode = 0x%04X\n", value, opcode);

//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "rrc "; 

	switch(opcode) {
        case 0x08:
			ss << "b";
			break;
        case 0x09:
			ss << "c";
			break;
        case 0x0A:
			ss << "d";
			break;
        case 0x0B:
			ss << "e";
			break;
        case 0x0C:
			ss << "h";
			break;
        case 0x0D:
			ss << "l";
			break;
        case 0x0E:
			ss << "(hl)";
			break;
        case 0x0F:
			ss << "a";
			break;
		default:
			ss << "?";
	}

	return ss.str();
}
