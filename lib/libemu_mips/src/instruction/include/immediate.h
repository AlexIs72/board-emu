#ifndef __MIPS_IMMEDIATE_INSTRUCTION_H__
#define __MIPS_IMMEDIATE_INSTRUCTION_H__

#include <sstream>

#include <mips/instruction.h>


typedef union {
    uint32_t    raw;
    struct {
                            //  ooooooss sssttttt iiiiiiii iiiiiiii
        uint16_t i : 16;    //  i   16  Immediate data. These 16 bits of immediate data are interpreted differently for different instructions.
                            //          2's-complement encoding is used to represent a number between -2(15) and 2(15-1).
        uint16_t t : 5;     //  t   5   Second register, in the range 0-31.
        uint16_t s : 5;     //  s   5   First register, in the range 0-31.
        uint16_t o : 6;     //  o   6   Instruction opcode. Determines which operation is to be performed. Values for this field are documented in the tables at the bottom of this page.
    }   format;
} immediate_type_format_t;


namespace emu {
    namespace mips {
        class immediate_instruction : public instruction {
			private:
				immediate_type_format_t _type_format;
            public:
				immediate_instruction(/*emu::mips::memory_cell &cell*/uint32_t value);
                virtual ~immediate_instruction() {}

                virtual std::string to_string() { 
					std::stringstream sstream;
					std::string str = instruction::to_string();
//					immediate_type_format_t tf;
    				
//					tf.raw = _get_raw_value();
					sstream << std::hex << static_cast<int16_t>(_get_opcode());

					str += "(opcode: 0x" + sstream.str() +")";
					return str;
				}
		
				static emu::core::i_instruction *get(/*emu::mips::memory_cell &cell*/uint32_t value);
			protected:

				inline uint8_t _get_opcode() const { return _type_format.format.o; }
				inline uint8_t _get_s_reg() const { return _type_format.format.s; }
				inline uint8_t _get_t_reg() const { return _type_format.format.t; }
				inline uint16_t _get_immediate_data() const { return _type_format.format.i; }

				virtual std::string _get_type() { return std::string("IMMEDIATE"); }
        };
    };
};



#endif
