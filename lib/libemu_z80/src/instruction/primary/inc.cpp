#include "include/inc.h"

using namespace emu::z80;

std::string inc_instruction::to_string() { 
    std::stringstream ss;
    uint32_t opcode =  _get_opcode();

	ss  << "inc ";

	switch(opcode) {
		case 0x03:
			ss << "bc";
			break;
		case 0x04:
			ss << "b";
			break;
		case 0x13:
			ss << "de";
			break;
		case 0x44:
			ss << "d";
			break;
		case 0x23:
			ss << "hl";
			break;
		case 0x24:
			ss << "h";
			break;
		case 0x33:
			ss << "sp";
			break;
		case 0x34:
			ss << "(hl)";
			break;
		case 0x0C:
			ss << "c";
			break;
		case 0x1C:
			ss << "e";
			break;
		case 0x2C:
			ss << "l";
			break;
		case 0x3C:
			ss << "a";
			break;
		default:
printf("inc: value = 0x%08X; opcode = 0x%02X\n", _get_raw_value(), opcode);
			ss << "?";
			break;
	}

	return ss.str();
}