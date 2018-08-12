#ifndef __EMU_Z80_RST_INSTRUCTION_H__
#define __EMU_Z80_RST_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class rst_instruction : public primary_instruction {
            public:
                rst_instruction(uint8_t value) : primary_instruction(value) {}
                virtual ~rst_instruction() {}
                virtual std::string to_string();

//				virtual size_t  get_size() {return 1;}
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif