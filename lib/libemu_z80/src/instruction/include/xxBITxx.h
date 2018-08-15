#ifndef __EMU_Z80_XXBITXX_INSTRUCTION_H__
#define __EMU_Z80_XXBITXX_INSTRUCTION_H__

#include <z80/instruction.h>

namespace emu {
    namespace z80 {
        class xxBITxx_instruction : public instruction {
            public:
                xxBITxx_instruction(/*emu::mips::memory_cell &cell*/uint32_t value) : instruction(/*cell*/value) {}
                virtual ~xxBITxx_instruction() {}

                virtual size_t  get_size() { return 2; }
				virtual std::string opcode_to_string();
//              virtual std::string opcode_to_string();

//              static emu::core::i_instruction *get(/*emu::mips::memory_cell &cell*/uint32_t value);
            protected:
                virtual std::string _get_type() { return std::string("xxBITxx"); }
//                virtual std::string to_string() { return std::string("Unknown instruction: COP type"); }
        };
    };
};



#endif
