#ifndef __MIPS_JUMP_INSTRUCTION_H__
#define __MIPS_JUMP_INSTRUCTION_H__

#include <mips/instruction.h>

namespace emu {
    namespace mips {
        class jump_instruction : public instruction {
            public:
				jump_instruction(emu::mips::memory_cell &cell) : instruction(cell) {}
                virtual ~jump_instruction() {}
		
				static emu::core::i_instruction *get(emu::mips::memory_cell &cell);
			protected:
				virtual std::string _get_type() { return std::string("JUMP"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
