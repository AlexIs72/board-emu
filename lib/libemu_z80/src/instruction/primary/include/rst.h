#ifndef __EMU_Z80_RST_INSTRUCTION_H__
#define __EMU_Z80_RST_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class rst_instruction : public primary_instruction {
            public:
                rst_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~rst_instruction() {}
                virtual std::string to_string();
        };
    };
};

#endif