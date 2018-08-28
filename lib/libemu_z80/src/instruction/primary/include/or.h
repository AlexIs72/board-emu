#ifndef __EMU_Z80_OR_INSTRUCTION_H__
#define __EMU_Z80_OR_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class or_instruction : public primary_instruction {
			private:
				uint8_t	_opcode;
            public:
                or_instruction(uint8_t opcode, uint16_t value) : primary_instruction(value), _opcode(opcode) {}
                virtual ~or_instruction() {}
                virtual std::string to_string();

				virtual size_t  get_size();
        };
    };
};

#endif