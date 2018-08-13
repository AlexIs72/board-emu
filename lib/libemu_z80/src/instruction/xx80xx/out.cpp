#include <sstream>
#include <iomanip>

#include "include/out.h"

using namespace emu::z80;

std::string ed_out_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x0000FF00) >> 8;
	int	nn = (value & 0x000000FF);

printf("[ed_out_instruction] value = 0x%04X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:out

	ss  << "out "; 

	switch(opcode) {
        case 0xD3:
			ss << "(#" << std::hex << std::setw(2) << std::setfill('0')  << nn << "),a";
			break;
	}

	return ss.str();
}