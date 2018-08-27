#ifndef __EMU_Z80_ED_LD_INSTRUCTION_H__
#define __EMU_Z80_ED_LD_INSTRUCTION_H__


#include "../../include/xxEXTEDxx.h"

namespace emu {
    namespace z80 {
        class ed_ld_instruction : public xxEXTEDxx_instruction {
			private:
				uint8_t _opcode;

            public:
                ed_ld_instruction(uint8_t opcode, uint32_t value) : xxEXTEDxx_instruction(value), _opcode(opcode) {}
                virtual ~ed_ld_instruction() {}
                virtual std::string to_string();
//				virtual std::string opcode_to_string();

//				virtual size_t  get_size();
        };
    };
};


//virtual std::string opcode_to_string() { return std::string(); }

#endif