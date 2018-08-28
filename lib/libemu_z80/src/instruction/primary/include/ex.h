#ifndef __EMU_Z80_PRIMARY_EX_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_EX_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class ex_instruction : public primary_instruction {
			private:
				uint8_t _opcode;
            public:
                ex_instruction(uint8_t opcode, uint32_t value) : primary_instruction(value), _opcode(opcode) {}
                virtual ~ex_instruction() {}
                virtual std::string to_string();

				virtual size_t  get_size();
        };
    };
};

#endif