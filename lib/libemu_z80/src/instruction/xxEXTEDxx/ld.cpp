#include <sstream>
#include <iomanip>

#include "include/ld.h"

using namespace emu::z80;

std::string ed_ld_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
//	uint8_t opcode = (value & 0xFF000000) >> 24;
//	int nn;


//	ss  << "ld "; 
//	nn = ((value & 0x00FF0000) >> 16);	
	switch(_opcode) {
		case 0xA0:
			ss << "ldi";
			break;
		case 0xB0:
			ss << "ldir";
			break;
/*		case 0xA1:
			ss << "cpi";
			break;
		case 0xB1:
			ss << "cpir";
			break;
		case 0xA2:
			ss << "ini";
			break;
		case 0xB2:
			ss << "inir";
			break;
		case 0xA3:
			ss << "outi";
			break;
		case 0xB3:
			ss << "otir";  
			break;
*/
		case 0xA8:
			ss << "ldd";
			break;
		case 0xB8:
			ss << "lddr";  
			break;
/*		case 0xA9:
			ss << "cpd";
			break;
		case 0xB9:
			ss << "cpdr";  
			break;
		case 0xAA:
			ss << "ind";
			break;
		case 0xBA:
			ss << "indr";  
			break;
		case 0xAB:
			ss << "outd";
			break;
		case 0xBB:
			ss << "otdr";  
			break;
*/
		default:
printf("ed_ld: value = 0x%08X; opcode = 0x%02X\n", value, _opcode);
			ss << "?";
//			return ss.str();
	}


	return ss.str();
}

