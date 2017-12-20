#ifndef __MIPS_IMMEDIATE_INSTRUCTION_H__
#define __MIPS_IMMEDIATE_INSTRUCTION_H__

#include <mips/instruction.h>

namespace emu {
    namespace mips {
        class immediate_instruction : public instruction {
            public:
				immediate_instruction(emu::mips::memory_cell &cell) : instruction(cell) {}
                virtual ~immediate_instruction() {}
		
				static emu::core::i_instruction *get(emu::mips::memory_cell &cell);
			protected:
				virtual std::string _get_type() { return std::string("IMMEDIATE"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
