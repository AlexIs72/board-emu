#ifndef __EMU_Z80_DEC_INSTRUCTION_H__
#define __EMU_Z80_DEC_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class dec_instruction : public primary_instruction {
            public:
                dec_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~dec_instruction() {}
                virtual std::string to_string();
        };
    };
};

#endif