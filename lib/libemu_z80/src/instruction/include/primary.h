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
		
			protected:
				virtual std::string _get_type() { return std::string("primary"); }
        };
    };
};



#endif
