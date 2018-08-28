#ifndef __EMU_Z80_PRIMARY_LD_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_LD_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class ld_instruction : public primary_instruction {
            public:
                ld_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~ld_instruction() {}
                virtual std::string to_string();
				virtual std::string opcode_to_string();

				virtual inline size_t  get_size() const ;
        };
    };
};

#endif