#ifndef __EMU_Z80_ED_CP_INSTRUCTION_H__
#define __EMU_Z80_ED_CP_INSTRUCTION_H__


#include "../../include/xxEXTEDxx.h"

namespace emu {
    namespace z80 {
        class ed_cp_instruction : public xxEXTEDxx_instruction {
            public:
                ed_cp_instruction(uint32_t value) : xxEXTEDxx_instruction(value) {}
                virtual ~ed_cp_instruction() {}
                virtual std::string to_string();
        };
    };
};

#endif