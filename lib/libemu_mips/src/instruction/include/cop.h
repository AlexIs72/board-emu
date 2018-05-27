#ifndef __MIPS_COP_INSTRUCTION_H__
#define __MIPS_COP_INSTRUCTION_H__

//#include <mips/instruction/cop/unknown.h>

#include <mips/instruction.h>

namespace emu {
    namespace mips {
        class cop_instruction : public instruction {
            public:
				cop_instruction(/*emu::mips::memory_cell &cell*/ uint32_t value) : instruction(/*cell*/value) {}
                virtual ~cop_instruction() {}
		
				static emu::core::i_instruction *get(/*emu::mips::memory_cell &cell*/uint32_t value);
			protected:
				virtual std::string _get_type() { return std::string("COP"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
