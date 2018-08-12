#ifndef __EMU_Z80_JR_INSTRUCTION_H__
#define __EMU_Z80_JR_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class jr_instruction : public primary_instruction {
            public:
                jr_instruction(uint16_t value) : primary_instruction(value) {}
                virtual ~jr_instruction() {}
                virtual std::string to_string();

				virtual size_t  get_size() {return 2;}
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif