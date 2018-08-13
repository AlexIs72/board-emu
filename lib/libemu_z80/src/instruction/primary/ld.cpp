#include <sstream>
#include <iomanip>

#include "include/ld.h"

using namespace emu::z80;

std::string ld_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
//	uint8_t	opcode = (value & 0x0000FF00) >> 8;
//	uint8_t	value2 = (value & 0x0000FF00) >> 8;
//	int	nn = (value & 0x000000FF);
	int nn;


	ss  << "ld "; 
	switch(_opcode) {
		case 0x01:
			nn = ((value & 0x00FF0000) >> 16) | (value & 0x0000FF00);	
			ss << "bc, #";
			break;
		default:
printf("ld: value = 0x%08X; opcode = 0x%02X\n", value, _opcode);
			ss << "?";
			return ss.str();
	}

	ss << std::hex << std::setw(4) << std::setfill('0') << nn;

	return ss.str();
}

size_t  ld_instruction::get_size() {
	size_t size = 1;
	switch(_opcode) {
        case 0x01:
			size = 3;
            break;
	}
	return size;
}