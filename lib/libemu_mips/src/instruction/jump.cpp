#include "include/jump.h"


using namespace emu::mips;

emu::core::i_instruction *jump_instruction::get(/*__attribute__((unused)) emu::mips::memory_cell &cell*/uint32_t value) {
    return new jump_instruction(/*cell*/value);
}

