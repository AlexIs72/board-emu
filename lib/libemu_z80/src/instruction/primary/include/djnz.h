#ifndef __EMU_Z80_PRIMARY_djnz_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_djnz_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class djnz_instruction : public primary_instruction {
            public:
                djnz_instruction(uint32_t value) : primary_instruction(value) {}
                virtual ~djnz_instruction() {}
                virtual std::string to_string();
				virtual inline size_t  get_size() const { return 2; }
        };
    };
};

#endif