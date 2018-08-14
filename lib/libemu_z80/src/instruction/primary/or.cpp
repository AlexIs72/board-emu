#include <sstream>
#include <iomanip>

#include "include/or.h"

using namespace emu::z80;

std::string or_instruction::to_string() { 
	std::stringstream ss;
//	uint32_t value =  _get_raw_value();
//	uint8_t	opcode = (value & 0x000000FF);
//	int	nn = (value & 0x000000FF);
/*
*/

//printf("value = 0x%02X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:or

	ss  << "or "; 

	switch(_opcode) {
		case 0xb0:
			ss << "b";
			break;
		case 0xb1:
			ss << "c";
			break;
		case 0xb2:
			ss << "d";
			break;
		case 0xb3:
			ss << "e";
			break;
		case 0xb4:
			ss << "h";
			break;
		case 0xb5:
			ss << "l";
			break;
		case 0xb6:
			ss << "(hl)";
			break;
		case 0xb7:
			ss << "a";
			break;
        default:
            ss << "?";
	}

	return ss.str();
}

size_t  or_instruction::get_size() {
    size_t size = 1;
    switch(_opcode) {
        case 0xF6:
            size = 2;
            break;
    }
    return size;
}
