#ifndef __EMU_Z80_PRIMARY_INSTRUCTION_NOP_H__
#define __EMU_Z80_PRIMARY_INSTRUCTION_NOP_H__

#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class nop_instruction : public primary_instruction {
            public:
				nop_instruction() : primary_instruction(0) {}
                virtual ~nop_instruction() {}
                virtual std::string to_string() { return std::string("nop"); }
        };
    };
};



#endif