#include "include/simple.h"

#include "simple/include/nop.h"

using namespace emu::mips;

emu::core::i_instruction *simple_instruction::get(__attribute__((unused)) emu::mips::memory_cell &cell) {
	return new nop_instruction(cell);
}