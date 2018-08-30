#ifndef __EMU_Z80_MEMORY_SEGMENT_ITERATOR_H__
#define __EMU_Z80_MEMORY_SEGMENT_ITERATOR_H__

#include <stdint.h>

#include <core/memory/cell.h>

namespace emu {
    namespace z80 {
		template <typename T> class memory_segment_iterator : public emu::core::memory_segment_iterator<T> {
	    	public:
				inline emu::core::memory_cell<uint32_t> get_cell() const {
//fprintf(stderr, "----> %X:%d\n", _address, *_data);
					return emu::core::memory_cell<uint32_t>(emu::core::memory_segment_iterator<T>::get_address(), emu::core::memory_segment_iterator<T>::get_value());
				}
		};
    };
};

#endif