#include <sstream>
#include <iomanip>

#include "include/djnz.h"

using namespace emu::z80;

std::string djnz_instruction::to_string() { 
	std::stringstream ss;
//	uint32_t value =  _get_raw_value();
	int	nn = _get_byte_value(); //(value & 0x000000FF);

//printf("value = 0x%04X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:djnz

	ss  << "djnz #" << std::hex << std::setw(2) << nn; 

	return ss.str();
}