#ifndef __EMU_CORE_MIPS_INSTRUCTION_H__
#define __EMU_CORE_MIPS_INSTRUCTION_H__

#include <stdint.h>

#include <core/instruction.h>
#include <mips/memory/cell.h>

namespace emu {
	namespace mips {
		class instruction : public emu::core::instruction {
/*			private:
				uint32_t	_raw_value;
				uint32_t	_address;
*/
			public:
				instruction(emu::mips::memory_cell &cell);
				virtual ~instruction();

			protected:
				virtual inline uint32_t	_get_raw_value() { return _raw_value; }
				virtual inline uint32_t _get_address() { return _address; }

/*			private:
				void _init(uint32_t address, uint32_t value);
*/
		};
	};
};


#endif