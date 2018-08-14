#include <sstream>
#include <iomanip>

#include "include/cp.h"

using namespace emu::z80;

std::string cp_instruction::to_string() { 
	std::stringstream ss;
	uint32_t value =  _get_raw_value();
	uint8_t	opcode = (value & 0x000000FF);
//	int	nn = (value & 0x000000FF);
/*
*/

//printf("value = 0x%02X; opcode = 0x%02X, nn = 0x%02X\n", value, opcode, nn);

//http://z80-heaven.wikidot.com/instructions-set:cp

	ss  << "cp "; 

	switch(opcode) {
		default:
			ss << "?";
	}

	return ss.str();
}