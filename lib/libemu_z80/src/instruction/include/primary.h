#ifndef __EMU_Z80_PRIMARY_INSTRUCTION_H__
#define __EMU_Z80_PRIMARY_INSTRUCTION_H__

#include <z80/instruction.h>

namespace emu {
    namespace z80 {
        class primary_instruction : public instruction {
            public:
				primary_instruction(uint32_t value) : instruction(value) {}
                virtual ~primary_instruction() {}
		
				virtual inline size_t  get_size() const { return 1; }
		
			protected:
				virtual std::string _get_type() { return std::string("primary"); }
        };
    };
};



#endif
