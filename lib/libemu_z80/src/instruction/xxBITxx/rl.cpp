#include <sstream>
#include <iomanip>

#include "include/rl.h"

using namespace emu::z80;

std::string cb_rl_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x00FF0000) >> 16;
//	int	nn = (value & 0x000000FF);

//printf("[cb_rl_instruction] value = 0x%04X; opcode = 0x%04X\n", value, opcode);

//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "rl "; 

	switch(opcode) {
        case 0x10:
			ss << "b";
			break;
        case 0x11:
			ss << "c";
			break;
        case 0x12:
			ss << "d";
			break;
        case 0x13:
			ss << "e";
			break;
        case 0x14:
			ss << "h";
			break;
        case 0x15:
			ss << "l";
			break;
        case 0x16:
			ss << "(hl)";
			break;
        case 0x17:
			ss << "a";
			break;
		default:
			ss << "?";
	}

	return ss.str();
}
