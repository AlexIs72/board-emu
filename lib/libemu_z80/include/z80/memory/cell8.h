#ifndef __EMU_Z80_MEMORY_CELL_H__
#define __EMU_Z80_MEMORY_CELL_H__

#include <stdint.h>

// https://stackoverflow.com/questions/105252/how-do-i-convert-between-big-endian-and-little-endian-values-in-c
#include <endian.h>

#include <core/memory/cell.h>


namespace emu {
    namespace z80 {
		class memory_cell : public emu::core::memory_cell<uint8_t> {
			public:
				virtual ~memory_cell() {}
                memory_cell &operator=(const emu::core::memory_cell<uint8_t> &other) {
					emu::core::memory_cell<uint8_t>::address(other.address());
					emu::core::memory_cell<uint8_t>::value(other.value());
                    return *this;
                 }

                 virtual inline uint32_t address() const { return emu::core::memory_cell<uint8_t>::address(); }
                 virtual inline void address(uint32_t addr) { emu::core::memory_cell<uint8_t>::address(addr); }

				 virtual inline uint8_t value() const { return /*htobe32(*/emu::core::memory_cell<uint8_t>::value()/*)*/; }
				 virtual inline void value(uint8_t val) { emu::core::memory_cell<uint8_t>::value(/*htobe32(*/val/*)*/); }

/*			private:
				void _init(uint8_t address, T value) {
					_address = address;
					_value = value;
				}*/
		};
    };
};

#endif
