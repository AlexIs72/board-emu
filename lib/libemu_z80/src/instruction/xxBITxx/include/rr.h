#ifndef __EMU_Z80_XXBITXX_RR_INSTRUCTION_H__
#define __EMU_Z80_XXBITXX_RR_INSTRUCTION_H__


#include "../../include/xxBITxx.h"

namespace emu {
    namespace z80 {
        class cb_rr_instruction : public xxBITxx_instruction {
            public:
                cb_rr_instruction(uint32_t value) : xxBITxx_instruction(value) {}
                virtual ~cb_rr_instruction() {}
                virtual std::string to_string();
        };
    };
};

#endif