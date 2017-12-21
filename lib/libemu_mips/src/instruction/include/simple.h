#ifndef __MIPS_SIMPLE_INSTRUCTION_H__
#define __MIPS_SIMPLE_INSTRUCTION_H__

#include <mips/instruction.h>

namespace emu {
    namespace mips {
        class simple_instruction : public instruction {
            public:
				simple_instruction(/*emu::mips::memory_cell &cell*/uint32_t value) : instruction(/*cell*/value) {}
                virtual ~simple_instruction() {}
		
				static emu::core::i_instruction *get(/*emu::mips::memory_cell &cell*/uint32_t value);
			protected:
				virtual std::string _get_type() { return std::string("SIMPLE"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
