#ifndef __EMU_Z80_PRIMARY_djnz_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_djnz_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class djnz_instruction : public primary_instruction {
            public:
                djnz_instruction(uint16_t value) : primary_instruction(value) {}
                virtual ~djnz_instruction() {}
                virtual std::string to_string();
				virtual size_t  get_size() {return 2;}
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif