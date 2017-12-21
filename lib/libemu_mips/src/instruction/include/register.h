#ifndef __MIPS_REGISTER_INSTRUCTION_H__
#define __MIPS_REGISTER_INSTRUCTION_H__

#include <mips/instruction.h>

namespace emu {
    namespace mips {
        class register_instruction : public instruction {
            public:
				register_instruction(/*emu::mips::memory_cell &cell*/uint32_t value) : instruction(/*cell*/value) {}
                virtual ~register_instruction() {}
		
				static emu::core::i_instruction *get(/*emu::mips::memory_cell &cell*/uint32_t value);
			protected:
				virtual std::string _get_type() { return std::string("REGISTER"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
