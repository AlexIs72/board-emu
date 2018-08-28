#ifndef __EMU_Z80_JR_INSTRUCTION_H__
#define __EMU_Z80_JR_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class jr_instruction : public primary_instruction {
            public:
                jr_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~jr_instruction() {}
                virtual std::string to_string();

				virtual inline size_t  get_size() const { return 2; }
        };
    };
};

#endif