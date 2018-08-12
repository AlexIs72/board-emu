#ifndef __EMU_Z80_PRIMARY_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_INSTRUCTION_H__

#include <z80/instruction.h>

namespace emu {
    namespace z80 {
        class primary_instruction : public instruction {
            public:
				primary_instruction(/*emu::mips::memory_cell &cell*/uint32_t value) : instruction(/*cell*/value) {}
                virtual ~primary_instruction() {}
		
				virtual size_t  get_size() { return 1; }
//				virtual std::string opcode_to_string();
		
//				static emu::core::i_instruction *get(/*emu::mips::memory_cell &cell*/uint32_t value);
			protected:
				virtual std::string _get_type() { return std::string("primary"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
