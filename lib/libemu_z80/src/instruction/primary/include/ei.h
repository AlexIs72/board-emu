#ifndef __EMU_Z80_EI_INSTRUCTION_H__
#define __EMU_Z80_EI_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class ei_instruction : public primary_instruction {
            public:
                ei_instruction() : primary_instruction(0xFB) {}
                virtual ~ei_instruction() {}
                virtual std::string to_string();
        };
    };
};
#endif