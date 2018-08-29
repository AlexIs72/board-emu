#include <sstream>
#include <iomanip>

#include "include/ld.h"

using namespace emu::z80;

std::string ld_instruction::to_string() { 
	const char *right_regs_list[] = {"b", "c", "d", "e", "h", "l", "(hl)", "a"};
#if 0
	const char *regs_table[][] = {
								  /* 0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F  */
/* 0 */								{NULL, "bc", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
/* 1 */								{NULL, "de", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
/* 2 */								{NULL, "hl", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
/* 3 */								{NULL, "sp", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
								};
#endif
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t opcode = _get_opcode();
	uint8_t major = (opcode & 0xF0) >> 4;
	uint8_t minor = (opcode & 0x0F);
	std::string val_left("?");
	std::string val_right("?");

	ss  << "ld "; 
	if(major == 0 || major == 1 || major == 2 || major == 3) {
		int nn = _get_halfword_value();
		std::stringstream nn_str;
		
		nn_str  << "#" << std::hex << std::setfill('0') << std::setw(4);

		switch(opcode) {
			case 0x01:
				val_left = "bc";
				break;
			case 0x06:
				//ss << "b, #" << std::hex << std::setw(2) << std::setfill('0') << nn;
				nn = _get_byte_value();
				nn_str  << std::setw(2);
				val_left = "b";
				break;
			case 0x11:
				val_left = "de";
				break;
			case 0x16:
//				ss << "d, #" << std::hex << std::setw(2) << std::setfill('0') << nn;
				nn = _get_byte_value();
				nn_str  << std::setw(2);
				val_left = "d";
				break;
			case 0x21:
				val_left = "hl";
				break;
			case 0x31:
				val_left = "sp";
				break;
			case 0x3e:
//				ss << "a, #" << std::hex << std::setw(2) << std::setfill('0') << nn;
				nn = _get_byte_value();
				nn_str  << std::setw(2);
				val_left = "a";
				break;
		}

		if(val_left.compare("?") != 0) {
//			nn_str  << "#" << std::hex << std::setw(4) << std::setfill('0') << nn;
			nn_str  << nn;
			val_right = nn_str.str();
		}

	} else if(major == 4){
		if(minor < 8) {
			val_left = "b";
			val_right = right_regs_list[minor];
		} else {
			val_left = "c";
			val_right = right_regs_list[minor-8];
		}
	} else if(major == 5){
		if(minor < 8) {
			val_left = "d";
			val_right = right_regs_list[minor];
		} else {
			val_left = "e";
			val_right = right_regs_list[minor-8];
		}
	} else if(major == 6){
		if(minor < 8) {
			val_left = "h";
			val_right = right_regs_list[minor];
		} else {
			val_left = "l";
			val_right = right_regs_list[minor-8];
		}
	} else if(major == 7){
		if(opcode != 0x76) {
			if(minor < 8) {
				val_left = "(hl)";
				val_right = right_regs_list[minor];
			} else {
				val_left = "a";
				val_right = right_regs_list[minor-8];
			}
		}
	} else if(major == 0xF){
		if(minor == 9) {
			val_left = "sp";
			val_right = "hl";
		}
	} /*else {
	}*/
	
	if(val_left.compare("?") == 0 || val_right.compare("?") == 0) {
printf("ld: opcode = 0x%02X, major = 0x%02X, minor = 0x%02X\n", opcode, major, minor);
printf("ld: value = 0x%08X; opcode = 0x%02X\n", value, opcode);
	}

	ss << val_left << ", " << val_right;

//printf("==========> ld %c, %s\n", val_left.c_str(), val_right.c_str());
	

/*	switch(opcode) {
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
/ *		case 0x76:
			break;* /
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
		default:
printf("ld: value = 0x%08X; opcode = 0x%02X\n", value, opcode);
			ss << "?";
//			return ss.str();
	}
*/

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
