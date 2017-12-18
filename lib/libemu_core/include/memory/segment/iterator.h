#ifndef __EMU_CORE_MEMORY_SEGMENT_ITERATOR_H__
#define __EMU_CORE_MEMORY_SEGMENT_ITERATOR_H__

#include <stdint.h>

#include <memory/cell.h>

namespace emu {
    namespace core {
		template <typename T> class memory_segment_iterator {
	    	private:
				uint32_t _address;
				T	_value;
				T	*_data;
	    	public:
				memory_segment_iterator() {
				}
				memory_segment_iterator(uint32_t address, T *data) {
					_address = address;
					_data = data;
				}

				bool operator != (memory_segment_iterator<T> const& other) const {
					return _data != other._data;
				}

				memory_segment_iterator<T> &operator++() {
					_address += sizeof(T);
    				_data++;
    				return *this;
				}

				inline uint32_t	get_address() const {
					return _address;
				}

				inline T get_value() const {
					return *_data;
				}

				inline memory_cell<T> get_cell() const {
					return memory_cell<T>(_address, *_data);
				}


				
/*				typename memory_cell operator*() const {
					return memory_cell(_address, *_data);
				}
*/
		};
    };
};

#endif