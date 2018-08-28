#ifndef __EMU_Z80_XXEXTEDXX_INSTRUCTION_H__
#define __EMU_Z80_XXEXTEDXX_INSTRUCTION_H__

#include <z80/instruction.h>

namespace emu {
    namespace z80 {
        class xxEXTEDxx_instruction : public instruction {
            public:
                xxEXTEDxx_instruction(uint32_t value) : instruction(value) {}
                virtual ~xxEXTEDxx_instruction() {}

                virtual inline size_t  get_size() const { return 2; }

                static inline uint8_t get_opcode(uint32_t value) {
                    return ((value & 0x00FF0000) >> 16);
                }


            protected:
                virtual std::string _get_type() { return std::string("xxEXTEDxx"); }
                virtual inline uint8_t _get_opcode() {
                    return get_opcode(_get_raw_value());
                }
        };
    };
};



#endif
