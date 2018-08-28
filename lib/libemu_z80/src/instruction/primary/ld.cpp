#include <sstream>
#include <iomanip>

#include "include/ld.h"

using namespace emu::z80;

std::string ld_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t opcode = _get_opcode();
//	uint8_t	opcode = (value & 0x0000FF00) >> 8;
//	uint8_t	value2 = (value & 0x0000FF00) >> 8;
//	int	nn = (value & 0x000000FF);
	int nn;


	ss  << "ld "; 
	nn = _get_byte_value(); //((value & 0x00FF0000) >> 16);	
	switch(opcode) {
		case 0x01:
//			nn = ((value & 0x00FF0000) >> 16) | (value & 0x0000FF00);	
			nn = _get_halfword_value();
			ss << "bc, #" << std::hex << std::setw(4) << std::setfill('0') << nn;
			break;
		case 0x11:
//			nn = ((value & 0x00FF0000) >> 16) | (value & 0x0000FF00);	
			nn = _get_halfword_value();
			ss << "de, #" << std::hex << std::setw(4) << std::setfill('0') << nn;
			break;
		case 0x21:
//			nn = ((value & 0x00FF0000) >> 16) | (value & 0x0000FF00);	
			nn = _get_halfword_value();
			ss << "hl, #" << std::hex << std::setw(4) << std::setfill('0') << nn;
			break;
		case 0x31:
//			nn = ((value & 0x00FF0000) >> 16) | (value & 0x0000FF00);	
			nn = _get_halfword_value();
			ss << "sp, #" << std::hex << std::setw(4) << std::setfill('0') << nn;
			break;
		case 0x40:
			ss << "b, b";
			break;
		case 0x41:
			ss << "b, c";
			break;
		case 0x42:
			ss << "b, d";
			break;
		case 0x43:
			ss << "b, e";
			break;
		case 0x44:
			ss << "b, h";
			break;
		case 0x45:
			ss << "b, l";
			break;
		case 0x46:
			ss << "b, (hl)";
			break;
		case 0x47:
			ss << "b, a";
			break;
		case 0x48:
			ss << "c, b";
			break;
		case 0x49:
			ss << "c, c";
			break;
		case 0x4A:
			ss << "c, d";
			break;
		case 0x4B:
			ss << "c, e";
			break;
		case 0x4C:
			ss << "c, h";
			break;
		case 0x4D:
			ss << "c, l";
			break;
		case 0x4E:
			ss << "c, (hl)";
			break;
		case 0x4F:
			ss << "c, a";
			break;
		case 0x50:
			ss << "d, b";
			break;
		case 0x51:
			ss << "d, c";
			break;
		case 0x52:
			ss << "d, d";
			break;
		case 0x53:
			ss << "d, e";
			break;
		case 0x54:
			ss << "d, h";
			break;
		case 0x55:
			ss << "d, l";
			break;
		case 0x56:
			ss << "d, (hl)";
			break;
		case 0x57:
			ss << "d, a";
			break;
		case 0x58:
			ss << "e, b";
			break;
		case 0x59:
			ss << "e, c";
			break;
		case 0x5A:
			ss << "e, d";
			break;
		case 0x5B:
			ss << "e, e";
			break;
		case 0x5C:
			ss << "e, h";
			break;
		case 0x5D:
			ss << "e, l";
			break;
		case 0x5E:
			ss << "e, (hl)";
			break;
		case 0x5F:
			ss << "e, a";
			break;
		case 0x60:
			ss << "h, b";
			break;
		case 0x61:
			ss << "h, c";
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
		case 0x70:
			ss << "(hl), b";
			break;
		case 0x71:
			ss << "(hl), c";
			break;
		case 0x72:
			ss << "(hl), d";
			break;
		case 0x73:
			ss << "(hl), e";
			break;
		case 0x74:
			ss << "(hl), h";
			break;
		case 0x75:
			ss << "(hl), l";
			break;
/*		case 0x76:
			break;*/
		case 0x77:
			ss << "(hl), a";
			break;
		case 0x78:
			ss << "a, b";
			break;
		case 0x79:
			ss << "a, c";
			break;
		case 0x7A:
			ss << "a, d";
			break;
		case 0x7B:
			ss << "a, e";
			break;
		case 0x7C:
			ss << "a, h";
			break;
		case 0x7D:
			ss << "a, l";
			break;
		case 0x7E:
			ss << "a, (hl)";
			break;
		case 0x7F:
			ss << "a, a";
			break;
/*		case 0x4f:
			ss << "c,a";
			break;*/
		default:
printf("ld: value = 0x%08X; opcode = 0x%02X\n", value, opcode);
			ss << "?";
//			return ss.str();
	}


	return ss.str();
}

size_t  ld_instruction::get_size() const {
	size_t size = 1;
	uint8_t opcode = _get_opcode();

	switch(opcode) {
        case 0x01:
        case 0x11:
        case 0x21:
		case 0x31:
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


/*
TODO
*/

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
