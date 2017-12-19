#ifndef __EMU_MIPS_MEMORY_CELL_H__
#define __EMU_MIPS_MEMORY_CELL_H__

#include <stdint.h>

// https://stackoverflow.com/questions/105252/how-do-i-convert-between-big-endian-and-little-endian-values-in-c
#include <endian.h>


namespace emu {
    namespace mips {
		class memory_cell : public emu::core::memory_cell<uint32_t> {
			public:
                 memory_cell &operator=(const emu::core::memory_cell<uint32_t> &other) {
					emu::core::memory_cell<uint32_t>::address(other.address());
					emu::core::memory_cell<uint32_t>::value(other.value());
                    return *this;
                 }

                 virtual inline uint32_t address() const { return emu::core::memory_cell<uint32_t>::address(); }
                 virtual inline void address(uint32_t addr) { emu::core::memory_cell<uint32_t>::address(addr); }

				 virtual inline uint32_t value() const { return htobe32(emu::core::memory_cell<uint32_t>::value()); }
				 virtual inline void value(uint32_t val) { emu::core::memory_cell<uint32_t>::value(htobe32(val)); }

/*			private:
				void _init(uint32_t address, T value) {
					_address = address;
					_value = value;
				}*/
		};
    };
};

#endif
