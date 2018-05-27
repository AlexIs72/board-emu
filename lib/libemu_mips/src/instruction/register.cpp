#include "include/register.h"

//#include "register/include/unknown.h"

using namespace emu::mips;

emu::core::i_instruction *register_instruction::get(/*__attribute__((unused)) emu::mips::memory_cell &cell*/ uint32_t value) {
    return new register_instruction(/*cell*/value);
}

