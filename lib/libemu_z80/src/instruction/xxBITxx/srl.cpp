#include <sstream>
#include <iomanip>

#include "include/srl.h"

using namespace emu::z80;

std::string cb_srl_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = _get_opcode(); //(value & 0x00FF0000) >> 16;
//	int	nn = (value & 0x000000FF);


//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "srl "; 

	switch(opcode) {
        case 0x38:
			ss << "b";
			break;
        case 0x39:
			ss << "c";
			break;
        case 0x3A:
			ss << "d";
			break;
        case 0x3B:
			ss << "e";
			break;
        case 0x3C:
			ss << "h";
			break;
        case 0x3D:
			ss << "l";
			break;
        case 0x3E:
			ss << "(hl)";
			break;
        case 0x3F:
			ss << "a";
			break;
		default:
printf("[cb_srl_instruction] value = 0x%04X; opcode = 0x%04X\n", value, opcode);
			ss << "?";
	}

	return ss.str();
}

