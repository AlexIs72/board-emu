#include <sstream>
#include <iomanip>

#include "include/cp.h"

using namespace emu::z80;

std::string cp_instruction::to_string() { 
	std::stringstream ss;
//	uint32_t value =  _get_raw_value();
	uint8_t	opcode = _get_opcode(); //(value & 0x000000FF);


//http://z80-heaven.wikidot.com/instructions-set:cp

	ss  << "cp "; 

	switch(opcode) {
		default:
printf("cp: value = 0x%02X; opcode = 0x%02X\n", _get_raw_value(), opcode);
			ss << "?";
	}

	return ss.str();
}