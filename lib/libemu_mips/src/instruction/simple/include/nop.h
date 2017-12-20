#ifndef __EMU_MIPS_SIMPLE_INSTRUCTION_NOP_H__
#define __EMU_MIPS_SIMPLE_INSTRUCTION_NOP_H__

#include "../../include/simple.h"

namespace emu {
    namespace mips {
        class nop_instruction : public simple_instruction {
            public:
				nop_instruction(__attribute__((unused)) emu::mips::memory_cell &cell) : simple_instruction(cell) {}
                virtual ~nop_instruction() {}
                virtual std::string to_string() { return std::string("nop"); }
        };
    };
};



#endif