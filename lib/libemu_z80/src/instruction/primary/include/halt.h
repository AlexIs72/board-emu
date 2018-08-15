#ifndef __EMU_Z80_HALT_INSTRUCTION_H__
#define __EMU_Z80_HALT_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class halt_instruction : public primary_instruction {
            public:
                halt_instruction() : primary_instruction(0x76) {}
                virtual ~halt_instruction() {}
                virtual std::string to_string();
        };
    };
};
#endif