#ifndef __EMU_CORE_BASE_INSTRUCTION_H__
#define __EMU_CORE_BASE_INSTRUCTION_H__

#include <stdint.h>

#include <string>

#include <core/memory/cell.h>

namespace emu {
	namespace core {
		class i_instruction {
			public:
				virtual std::string to_string() = 0;
		};

		template <typename T> 
		class instruction : public i_instruction {
			private:
				T	_raw_value;
//				uint32_t	_address;
			public:
				instruction() {}
//				instruction(emu::core::memory_cell<uint32_t> &cell);
//				instruction(uint32_t address, uint32_t value);
				instruction(T value) : _raw_value(value) {}
				virtual ~instruction() {}

				std::string to_string() { return std::string(); }

			protected:
				virtual inline T	_get_raw_value() { return _raw_value; }
//				virtual inline uint32_t _get_address() { return _address; }

			private:
//				void _init(uint32_t address, uint32_t value);

		};

		class unknown_instruction : public instruction<uint8_t> {
			public:
//				unknown_instruction(emu::core::memory_cell<uint32_t> &cell) : instruction(cell) {};
				unknown_instruction() : instruction(0) {};
				virtual ~unknown_instruction() {};
				std::string to_string() { return std::string("Unknown instruction"); }
		};
	};
};


#endif