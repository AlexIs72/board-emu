#include <sstream>
#include <iomanip>

#include "include/in.h"

using namespace emu::z80;

std::string ed_in_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = _get_opcode(); //(value & 0x0000FF00) >> 8;

//printf("value = 0x%04X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "in "; 

	switch(opcode) {
        case 0xA2:
            ss << "ini";
            break;
        case 0xB2:
            ss << "inir";
            break;
        case 0xAA:
            ss << "ind";
            break;
        case 0xBA:
            ss << "indr";
            break;
        default:
printf("ed_in: value = 0x%08X; opcode = 0x%02X\n", value, opcode);
            ss << "?";
	}

	return ss.str();
}