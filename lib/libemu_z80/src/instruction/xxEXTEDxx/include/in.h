#ifndef __EMU_Z80_ED_IN_INSTRUCTION_H__
#define __EMU_Z80_ED_IN_INSTRUCTION_H__


#include "../../include/xxEXTEDxx.h"

namespace emu {
    namespace z80 {
        class ed_in_instruction : public xxEXTEDxx_instruction {
            public:
                ed_in_instruction(uint32_t value) : xxEXTEDxx_instruction(value) {}
                virtual ~ed_in_instruction() {}
                virtual std::string to_string();
//				virtual size_t  get_size() {return 2;}
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif