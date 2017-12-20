#include "include/addiu.h"

using namespace emu::mips;

std::string addiu_instruction::to_string() { 
	const char *s_reg_str = reg_to_str(_get_s_reg());
	const char *t_reg_str = reg_to_str(_get_t_reg());
	std::stringstream ss;
	
	ss  << "addiu " 
		<< t_reg_str << ", "
		<< s_reg_str << ", "
		<< std::hex << "0x" << _get_immediate_data();

	return ss.str(); 
}