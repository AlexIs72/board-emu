#ifndef __EMU_Z80_XOR_INSTRUCTION_H__
#define __EMU_Z80_XOR_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class xor_instruction : public primary_instruction {
            public:
                xor_instruction(uint8_t value) : primary_instruction(value) {}
                virtual ~xor_instruction() {}
                virtual std::string to_string();

//				virtual size_t  get_size() {return 1;}
        };
    };
};

#endif