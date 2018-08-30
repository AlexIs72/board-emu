#ifndef __EMU_Z80_INSTRUCTION_H__
#define __EMU_Z80_INSTRUCTION_H__

#include <stdint.h>

#include <core/instruction.h>
#include <z80/memory/cell.h>

#define 	MTR_INVALID_REG	"$$$$$"

namespace emu {
	namespace z80 {
		class instruction : public emu::core::instruction<uint32_t> {
			private:
				uint8_t		_size;
			public:
				instruction(uint32_t value) : emu::core::instruction<uint32_t>(value) {}
				virtual ~instruction();

				virtual std::string to_string() { return std::string("Unknown instruction(type: " + _get_type() + ")!"); }
//				virtual std::string opcode_to_string();

				static inline uint8_t get_opcode(uint32_t value) {
    				return ((value & 0xFF000000) >> 24);
				}

			protected:
				const char *_reg_to_str(uint8_t reg);

				virtual inline uint8_t _get_byte_value() const  {
    				return (_get_raw_value() & 0x00FF0000) >> 16;
				}

				virtual inline uint16_t _get_halfword_value() const {
					uint32_t value = _get_raw_value();
					return ((value & 0x00FF0000) >> 16) | (value & 0x0000FF00);
//	    			return (_get_raw_value() & 0x00FFFF00) >> 8;
				}
//				virtual uint32_t _get_word_value() const ;

				virtual inline std::string _get_type() { return std::string("unknown"); }

				virtual inline uint8_t _get_opcode() const {
    				return get_opcode(_get_raw_value());
				}

				
		};
	};
};


#endif