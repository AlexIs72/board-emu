#ifndef __EMU_Z80_PRIMARY_EX_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_EX_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class ex_instruction : public primary_instruction {
            public:
                ex_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~ex_instruction() {}
                virtual std::string to_string();

				virtual size_t  get_size() const;
        };
    };
};

#endif