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
	nn = ((value & 0x00FF0000) >> 16);	
	switch(_opcode) {
		case 0x01:
			nn = ((value & 0x00FF0000) >> 16) | (value & 0x0000FF00);	
			ss << "bc, #" << std::hex << std::setw(4) << std::setfill('0') << nn;
			break;
		case 0x06:
			ss << "b, #" << std::hex << std::setw(2) << std::setfill('0') << nn;
			break;
		case 0x16:
			ss << "d, #" << std::hex << std::setw(2) << std::setfill('0') << nn;
			break;
		case 0x3e:
			ss << "a, #" << std::hex << std::setw(2) << std::setfill('0') << nn;
			break;
		case 0x78:
			ss << "a,b";
			break;
		case 0x4f:
			ss << "c,a";
			break;
		default:
printf("ld: value = 0x%08X; opcode = 0x%02X\n", value, _opcode);
			ss << "?";
//			return ss.str();
	}


	return ss.str();
}

size_t  ld_instruction::get_size() {
	size_t size = 1;
	switch(_opcode) {
        case 0x01:
			size = 3;
            break;
		case 0x06:
		case 0x16:
		case 0x3e:
			size = 2;
			break;
	}
	return size;
}


std::string ld_instruction::opcode_to_string()  {
	std::stringstream ss;
	size_t  size = get_size();
	uint32_t value =  _get_raw_value();

	if(size == 1) {
		ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
		return ss.str();
	} else if(size == 2) {
		ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
		ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0x00FF0000) >> 16) << " ";
		return ss.str();
	}	

	return emu::core::instruction<uint32_t>::opcode_to_string();	
}
