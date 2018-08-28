#include <sstream>
#include <iomanip>

#include "include/ex.h"

using namespace emu::z80;

std::string ex_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
//	uint8_t	opcode = (value & 0x0000FF00) >> 8;
//	uint8_t	value2 = (value & 0x0000FF00) >> 8;
//	int	nn = (value & 0x000000FF);
//	int nn;


	ss  << "ex "; 
	switch(_opcode) {
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
printf("ex: value = 0x%08X; opcode = 0x%02X\n", value, _opcode);
			ss << "?";
//			return ss.str();
	}


	return ss.str();
}

size_t  ex_instruction::get_size() {
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

