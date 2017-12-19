#include <core/instruction.h>

using namespace emu::core;

instruction::instruction() {
	_init(0,0);
}

instruction::instruction(emu::core::memory_cell<uint32_t> &cell) {
	_init(cell.address(), cell.value());
}

instruction::instruction(uint32_t address, uint32_t value) {
	_init(address, value);
}

instruction::~instruction() {
}

void instruction::_init(uint32_t address, uint32_t value) {
	_address = address;
	_raw_value = value;
}
