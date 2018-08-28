#include "include/dec.h"

using namespace emu::z80;

std::string dec_instruction::to_string() { 
    std::stringstream ss;
	uint32_t opcode =  _get_opcode();

	ss  << "dec ";

	switch(opcode) {
        case 0x05:
			ss << "b";
			break;
        case 0x15:
			ss << "d";
			break;
        case 0x25:
			ss << "h";
			break;
        case 0x35:
			ss << "(hl)";
			break;
        case 0x0b:
			ss << "bc";
			break;
        case 0x1b:
			ss << "de";
			break;
        case 0x2b:
			ss << "hl";
			break;
        case 0x3b:
			ss << "sp";
			break;
        case 0x0d:
			ss << "c";
			break;
        case 0x1d:
			ss << "e";
			break;
        case 0x2d:
			ss << "l";
			break;
        case 0x3d:
			ss << "a";
			break;
		default:
printf("dec: value = 0x%08X; opcode = 0x%02X\n", _get_raw_value(), opcode);
			ss << "?";
			break;
	}

	return ss.str();
}