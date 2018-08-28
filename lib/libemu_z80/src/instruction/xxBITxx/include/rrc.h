#ifndef __EMU_Z80_XXBITXX_RRC_INSTRUCTION_H__
#define __EMU_Z80_XXBITXX_RRC_INSTRUCTION_H__


#include "../../include/xxBITxx.h"

namespace emu {
    namespace z80 {
        class cb_rrc_instruction : public xxBITxx_instruction {
            public:
                cb_rrc_instruction(uint32_t value) : xxBITxx_instruction(value) {}
                virtual ~cb_rrc_instruction() {}
                virtual std::string to_string();
        };
    };
};

#endif