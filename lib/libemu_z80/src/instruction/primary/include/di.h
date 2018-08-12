#ifndef __EMU_Z80_DI_INSTRUCTION_H__
#define __EMU_Z80_DI_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class di_instruction : public primary_instruction {
            public:
                di_instruction() : primary_instruction(0xF3) {}
                virtual ~di_instruction() {}
                virtual std::string to_string();

//				virtual size_t  get_size() {return 1;}
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif