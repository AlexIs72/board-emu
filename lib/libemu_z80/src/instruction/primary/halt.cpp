#include "include/halt.h"

using namespace emu::z80;

std::string halt_instruction::to_string() { 
	return std::string("halt"); 
}