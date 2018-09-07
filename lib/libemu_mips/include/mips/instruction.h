#ifndef __EMU_CORE_MIPS_INSTRUCTION_H__
#define __EMU_CORE_MIPS_INSTRUCTION_H__

#include <stdint.h>

#include <core/instruction.h>
#include <mips/memory/cell.h>

#define 	MTR_INVALID_REG	"$$$$$"

namespace emu {
	namespace mips {
		class instruction : public emu::core::instruction<uint32_t> {
/*			private:
				uint32_t	_raw_value;
				uint32_t	_address;
*/
			public:
//				instruction(emu::mips::memory_cell &cell);
				instruction(uint32_t value) : emu::core::instruction<uint32_t>(value) {}
				virtual ~instruction() {}

				virtual std::string to_string() { return std::string("Unknown instruction(type: " + _get_type() + ")!"); }
				virtual inline size_t  get_size() const { return sizeof(uint32_t);}

				virtual bool exec() {
printf("===> exec for '%s' not implemented yet!\n", to_string().c_str());
    				return  false;
				}


			protected:
				const char *reg_to_str(uint8_t reg);
				virtual inline std::string _get_type() { return std::string("unknown"); }

/*			private:
				void _init(uint32_t address, uint32_t value);
*/
		};
	};
};


#endif
