#include "include/di.h"

using namespace emu::z80;

std::string di_instruction::to_string() { 
//	const char *t_reg_str = reg_to_str(_get_t_reg());
//	std::stringstream ss;
	
//	ss  << "di " 
//		<< t_reg_str << ", "
//		<< std::hex << "0x" << _get_immediate_data();

	return std::string("di"); 
}