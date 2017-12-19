#include <mips/instruction.h>

using namespace emu::mips;

instruction::instruction(emu::mips::memory_cell &cell) {
	emu::core::instruction(cell.address(), cell.value());
}

instruction::~instruction() {
}
/*
void instruction::_init(uint32_t address, uint32_t value) {
	_address = address;
	_raw_value = value;
}*/
