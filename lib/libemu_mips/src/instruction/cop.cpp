#include "include/cop.h"


using namespace emu::mips;

emu::core::i_instruction *cop_instruction::get(__attribute__((unused)) emu::mips::memory_cell &cell) {
    return new cop_instruction(cell);
}

