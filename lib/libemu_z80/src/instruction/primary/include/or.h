#ifndef __EMU_Z80_OR_INSTRUCTION_H__
#define __EMU_Z80_OR_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class or_instruction : public primary_instruction {
            public:
                or_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~or_instruction() {}
                virtual std::string to_string();

				virtual inline size_t  get_size() const ;
        };
    };
};

#endif