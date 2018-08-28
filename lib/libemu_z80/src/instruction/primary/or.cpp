#include <sstream>
#include <iomanip>

#include "include/or.h"

using namespace emu::z80;

std::string or_instruction::to_string() { 
	std::stringstream ss;
	uint8_t opcode = _get_opcode();

//http://z80-heaven.wikidot.com/instructions-set:or

	ss  << "or "; 

	switch(opcode) {
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
printf("or: value = 0x%02X; opcode = 0x%02X\n", _get_raw_value(), opcode);
            ss << "?";
	}

	return ss.str();
}

size_t  or_instruction::get_size() const {
    size_t size = 1;
	uint8_t opcode = _get_opcode();

    switch(opcode) {
        case 0xF6:
            size = 2;
            break;
    }
    return size;
}
