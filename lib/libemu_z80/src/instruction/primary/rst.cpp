#include <sstream>
#include <iomanip>

#include "include/rst.h"

using namespace emu::z80;

std::string rst_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = _get_opcode(); //(value & 0x000000FF);
/*
*/


/*
        case 0xC7:
        case 0xCF:
        case 0xD7:
        case 0xDF:
        case 0xE7:
        case 0xEF:
        case 0xF7:
        case 0xFF:

*/

	ss  << "rst "; 

	switch(opcode) {
        case 0xC7:
			ss << "00h";
			break;
        case 0xCF:
			ss << "08h";
			break;
        case 0xD7:
			ss << "10h";
			break;
        case 0xDF:
			ss << "18h";
			break;
        case 0xE7:
			ss << "20h";
			break;
        case 0xEF:
			ss << "28h";
			break;
        case 0xF7:
			ss << "30h";
			break;
        case 0xFF:
			ss << "38h";
			break;
        default:
printf("rst: value = 0x%02X; opcode = 0x%02X\n", value, opcode);
            ss << "?";
	}

	return ss.str();
}