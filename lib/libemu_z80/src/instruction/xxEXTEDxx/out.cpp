#include <sstream>
#include <iomanip>

#include "include/out.h"

using namespace emu::z80;

std::string ed_out_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = _get_opcode(); //(value & 0x0000FF00) >> 8;

//printf("value = 0x%04X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "out "; 

	switch(opcode) {
        case 0xA3:
            ss << "outi";
            break;
        case 0xB3:
            ss << "otir";
            break;
        case 0xAB:
            ss << "outd";
            break;
        case 0xBB:
            ss << "otdr";
            break;
        default:
printf("ed_out: value = 0x%08X; opcode = 0x%02X\n", value, opcode);
            ss << "?";
	}

	return ss.str();
}