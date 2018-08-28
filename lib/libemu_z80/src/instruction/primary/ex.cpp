#include <sstream>
#include <iomanip>

#include "include/ex.h"

using namespace emu::z80;

std::string ex_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t opcode = _get_opcode();

	ss  << "ex "; 
	switch(opcode) {
		case 0x08:
			ss << "af,af'";
			break;
		case 0xE3:
			ss << "(sp),hl";
			break;
		case 0xEB:
			ss << "de,hl'";
			break;
		default:
printf("ex: value = 0x%08X; opcode = 0x%02X\n", value, opcode);
			ss << "?";
//			return ss.str();
	}


	return ss.str();
}

size_t  ex_instruction::get_size() const {
	size_t size = 1;

/*	switch(_opcode) {
        case 0x01:
			size = 3;
            break;
		case 0x3e:
			size = 2;
			break;
	}
*/
	return size;
}

