#ifndef __EMU_CORE_BASE_INSTRUCTION_H__
#define __EMU_CORE_BASE_INSTRUCTION_H__

#include <stdint.h>

#include <core/memory/cell.h>

namespace emu {
	namespace core {
		class instruction {
			protected:
				uint32_t	_raw_value;
				uint32_t	_address;
			public:
				instruction();
				instruction(emu::core::memory_cell<uint32_t> &cell);
				instruction(uint32_t address, uint32_t value);
				virtual ~instruction();

			protected:
				virtual inline uint32_t	_get_value() { return _raw_value; }
				virtual inline uint32_t _get_address() { return _address; }

			private:
				void _init(uint32_t address, uint32_t value);

		};
	};
};


#endif