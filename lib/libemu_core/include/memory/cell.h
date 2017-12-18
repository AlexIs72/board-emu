#ifndef __EMU_CORE_MEMORY_CELL_H__
#define __EMU_CORE_MEMORY_CELL_H__

#include <stdint.h>

namespace emu {
    namespace core {
		template <typename T> class memory_cell {
    	    private:
        		T			_value;
                uint32_t	_address;

            public:
                 memory_cell() {
					_init(0,0);
				 }
                 memory_cell(T value) {
					_init(0, value);
				 }
                 memory_cell(uint32_t address, T value) {
					_init(address, value);
				 }
                 memory_cell(const memory_cell<T> &other) {
					_init(other._address, other._value);
				 }
                 ~memory_cell() {
				 }

                 inline uint32_t address() const { return _address; }
                 inline void address(uint32_t addr) { _address = addr; }

				 inline T value() const { return _value; }
				 inline void value(T val) { _value = val; }

			private:
				void _init(uint32_t address, T value) {
					_address = address;
					_value = value;
				}
		};
    };
};

#endif
