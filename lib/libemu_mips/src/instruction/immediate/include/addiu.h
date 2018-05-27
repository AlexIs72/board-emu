#ifndef __EMU_MIPS_ADDIU_INSTRUCTION_H__
#define __EMU_MIPS_ADDIU_INSTRUCTION_H__


#include "../../include/immediate.h"

namespace emu {
    namespace mips {
        class addiu_instruction : public immediate_instruction {
            public:
                addiu_instruction(/*__attribute__((unused)) emu::mips::memory_cell &cell*/uint32_t value) : immediate_instruction(value) {}
                virtual ~addiu_instruction() {}
                virtual std::string to_string();
        };
    };
};


#endif