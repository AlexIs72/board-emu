#ifndef __EMU_Z80_PRIMARY_OUT_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_OUT_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class out_instruction : public primary_instruction {
            public:
                out_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~out_instruction() {}
                virtual std::string to_string();
				virtual inline size_t  get_size() const { return 2; }
        };
    };
};

#endif