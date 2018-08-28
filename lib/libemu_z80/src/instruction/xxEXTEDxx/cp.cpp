#include <sstream>
#include <iomanip>

#include "include/cp.h"

using namespace emu::z80;

std::string ed_cp_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = _get_opcode(); //(value & 0x000000FF);
/*
*/

//printf("value = 0x%02X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:cp

	ss  << "cp "; 

	switch(opcode) {
        case 0xA1:
            ss << "cpi";
            break;
        case 0xB1:
            ss << "cpir";
            break;
        case 0xA9:
            ss << "cpd";
            break;
        case 0xB9:
            ss << "cpdr";
            break;
		default:
printf("ed_cp: value = 0x%08X; opcode = 0x%02X\n", value, opcode);
			ss << "?";
	}

	return ss.str();
}