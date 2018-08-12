#include <sstream>
#include <iomanip>

#include "include/jr.h"

using namespace emu::z80;

std::string jr_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x0000FF00) >> 8;
	int	nn = (value & 0x000000FF);
/*
JP NN        ;no contition
JR C,NN        ;jumps if C is set
JR NC,NN        ;jumps if C is reset
JR Z,NN        ;jumps if Z is set
JR NZ,NN    ;jumps if Z is reset
*/

//printf("value = 0x%02X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

	ss  << "jr "; 
	switch(opcode) {
		case 0x18:		// jr x
//			ss << nn;
			break;
		case 0x20:	// jr nz,x
			ss << "nz, ";
			break;
		case 0x28:	// jr z,x
			ss << "z, ";
			break;
		case 0x30:	// jr nc,x
			ss << "nc, ";
			break;
		case 0x38: 	// jr c,x
			ss << "c, ";
			break;
		default:
			ss << "?";
			return ss.str();
	}

	ss << std::hex << "0x" << std::setw(2) << nn;


	return ss.str();
}