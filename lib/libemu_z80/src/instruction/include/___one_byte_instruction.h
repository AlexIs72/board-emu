#ifndef __EMU_Z80_ONE_BYTE_INSTRUCTION_H__
#define __EMU_Z80_ONE_BYTE_INSTRUCTION_H__

#include <z80/instruction.h>

namespace emu {
    namespace z80 {
        class one_byte_instruction : public instruction {
            public:
				one_byte_instruction(/*emu::mips::memory_cell &cell*/uint8_t value) : instruction(/*cell*/value) {}
                virtual ~one_byte_instruction() {}
		
//				static emu::core::i_instruction *get(/*emu::mips::memory_cell &cell*/uint32_t value);
			protected:
//				virtual std::string _get_type() { return std::string("primary"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
