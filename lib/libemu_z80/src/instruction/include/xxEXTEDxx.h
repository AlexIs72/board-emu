#ifndef __EMU_Z80_XXEXTEDXX_INSTRUCTION_H__
#define __EMU_Z80_XXEXTEDXX_INSTRUCTION_H__

#include <z80/instruction.h>

namespace emu {
    namespace z80 {
        class xxEXTEDxx_instruction : public instruction {
            public:
                xxEXTEDxx_instruction(/*emu::mips::memory_cell &cell*/uint32_t value) : instruction(/*cell*/value) {}
                virtual ~xxEXTEDxx_instruction() {}

                virtual size_t  get_size() { return 2; }
				virtual std::string opcode_to_string();

            protected:
                virtual std::string _get_type() { return std::string("xxEXTEDxx"); }
        };
    };
};



#endif
