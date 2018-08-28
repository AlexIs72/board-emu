#ifndef __EMU_Z80_XXBITXX_RLC_INSTRUCTION_H__
#define __EMU_Z80_XXBITXX_RLC_INSTRUCTION_H__


#include "../../include/xxBITxx.h"

namespace emu {
    namespace z80 {
        class cb_rlc_instruction : public xxBITxx_instruction {
            public:
                cb_rlc_instruction(uint32_t value) : xxBITxx_instruction(value) {}
                virtual ~cb_rlc_instruction() {}
                virtual std::string to_string();
        };
    };
};

#endif