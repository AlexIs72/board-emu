#ifndef __EMU_MIPS_INSTRUCTION_FACTORY_H__
#define __EMU_MIPS_INSTRUCTION_FACTORY_H__

#include <mips/memory/cell.h>
#include <mips/instruction.h>


namespace emu {
	namespace mips {
		class factory {
			public:
				static emu::core::i_instruction *get_instruction(emu::mips::memory_cell &cell);
       			
/*				static emu::core::i_instruction *get_simple_instruction(emu::core::memory_cell<uint32_t> &cell);
        		static emu::core::i_instruction *get_register_instruction(emu::core::memory_cell<uint32_t> &cell);
        		static emu::core::i_instruction *get_jump_instruction(emu::core::memory_cell<uint32_t> &cell);
        		static emu::core::i_instruction *get_cop_instruction(emu::core::memory_cell<uint32_t> &cell);
        		static emu::core::i_instruction *get_immediate_instruction(emu::core::memory_cell<uint32_t> &cell);
*/
		};
	};
};

#endif