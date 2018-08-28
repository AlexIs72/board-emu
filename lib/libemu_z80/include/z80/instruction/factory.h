#ifndef __EMU_Z80_INSTRUCTION_FACTORY_H__
#define __EMU_Z80_INSTRUCTION_FACTORY_H__

#include <z80/memory/cell.h>
#include <z80/instruction.h>


namespace emu {
	namespace z80 {
		class factory {
			public:
				static emu::core::i_instruction *get_instruction(uint32_t value);
		};
	};
};

#endif