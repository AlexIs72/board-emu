#ifndef __EMU_MIPS_LUI_INSTRUCTION_H__
#define __EMU_MIPS_LUI_INSTRUCTION_H__


#include "../../include/immediate.h"

namespace emu {
    namespace mips {
        class lui_instruction : public immediate_instruction {
            public:
                lui_instruction(/*__attribute__((unused)) emu::mips::memory_cell &cell*/uint32_t value) : immediate_instruction(value) {}
                virtual ~lui_instruction() {}
                virtual std::string to_string();
        };
    };
};


#endif