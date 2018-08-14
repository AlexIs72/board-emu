#ifndef __EMU_Z80_PRIMARY_LD_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_LD_INSTRUCTION_H__


#include "../../include/primary.h"

namespace emu {
    namespace z80 {
        class ld_instruction : public primary_instruction {
			private:
				uint8_t _opcode;
            public:
                ld_instruction(uint8_t opcode, uint32_t value) : primary_instruction(value), _opcode(opcode) {}
                virtual ~ld_instruction() {}
                virtual std::string to_string();
				virtual std::string opcode_to_string();

				virtual size_t  get_size();
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif