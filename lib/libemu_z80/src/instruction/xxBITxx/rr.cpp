#include <sstream>
#include <iomanip>

#include "include/rr.h"

using namespace emu::z80;

std::string cb_rr_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x00FF0000) >> 16;
//	int	nn = (value & 0x000000FF);

//printf("[cb_rr_instruction] value = 0x%04X; opcode = 0x%04X\n", value, opcode);

//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "rr "; 

	switch(opcode) {
        case 0x18:
			ss << "b";
			break;
        case 0x19:
			ss << "c";
			break;
        case 0x1A:
			ss << "d";
			break;
        case 0x1B:
			ss << "e";
			break;
        case 0x1C:
			ss << "h";
			break;
        case 0x1D:
			ss << "l";
			break;
        case 0x1E:
			ss << "(hl)";
			break;
        case 0x1F:
			ss << "a";
			break;
		default:
			ss << "?";
	}

	return ss.str();
}
