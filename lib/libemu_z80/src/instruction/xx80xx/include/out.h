#ifndef __EMU_Z80_XX80XX_OUT_INSTRUCTION_H__
#define __EMU_Z80_XX80XX_OUT_INSTRUCTION_H__


#include "../../include/xx80xx.h"

namespace emu {
    namespace z80 {
        class ed_out_instruction : public xx80xx_instruction {
            public:
                ed_out_instruction(uint32_t value) : xx80xx_instruction(value) {}
                virtual ~ed_out_instruction() {}
                virtual std::string to_string();
//				virtual size_t  get_size() {return 2;}
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif