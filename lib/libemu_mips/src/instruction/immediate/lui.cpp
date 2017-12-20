#include "include/lui.h"

using namespace emu::mips;

std::string lui_instruction::to_string() { 
	const char *t_reg_str = reg_to_str(_get_t_reg());
	std::stringstream ss;
	
	ss  << "lui " 
		<< t_reg_str << ", "
		<< std::hex << "0x" << _get_immediate_data();

	return ss.str(); 
}