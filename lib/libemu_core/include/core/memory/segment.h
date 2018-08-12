#ifndef __EMU_CORE_MEMORY_SEGMENT_H__
#define __EMU_CORE_MEMORY_SEGMENT_H__

#include <stdint.h>

#include <fstream>
#include <streambuf>
#include <stdexcept>

#include <core/memory/segment/iterator.h>
#include <core/memory/cell.h>


namespace emu {
    namespace core {
		class memory_segment {
	    	private:
				uint8_t		*_data;
				uint32_t	_address;
				size_t 		_size;

	    	public:
				memory_segment();
				memory_segment(uint32_t address);
				memory_segment(uint32_t address, size_t size);
				~memory_segment();

				template<typename T> size_t get_size() {
					if(_size == 0) {
						throw std::runtime_error("Segment is empty!");
					}
					if(_size % sizeof(T) != 0) {
						throw std::invalid_argument("Invalid size alignment for current type");
					}

					return _size / sizeof(T);
				}

				inline uint32_t get_address() {
					return _address;
				}


				template<typename T> void set(memory_cell<T> &cell) {
				}

				template<typename T> void set(uint32_t address, T value) {
//fprintf(stderr, "[%s] ====> 0x%X, %ld, %ld\n", __FUNCTION__, address, sizeof(T), address % sizeof(T));
					if(address < _address || address >= _address + _size) {
						throw std::invalid_argument("Invalid address");
					}
					if(address % sizeof(T) != 0) {
						throw std::invalid_argument("Invalid address alignment");
					}

					size_t offs = address - _address;
//fprintf(stderr, "[%s] ====> offs = %ld\n", __FUNCTION__, offs);
					T* addr = reinterpret_cast<T*>(_data + offs);
//fprintf(stderr, "[%s] ====> addr = %p\n", __FUNCTION__, addr);
					*addr = value;
				}
				
				template<typename T> memory_cell<T> get(uint32_t address) {
//fprintf(stderr, "[%s] ====> 0x%X, 0x%X, %ld, %ld\n", __FUNCTION__, _address, address, sizeof(T), address % sizeof(T));
					if(address < _address || address >= _address + _size) {
						throw std::invalid_argument("Invalid address");
					}
					if(address % sizeof(T) != 0) {
						throw std::invalid_argument("Invalid address alignment");
					}
					size_t offs = address - _address;
//fprintf(stderr, "[%s] ====> offs = %ld\n", __FUNCTION__, offs);
					T* addr = reinterpret_cast<T*>(_data + offs);
//fprintf(stderr, "[%s] ====> addr = %p\n", __FUNCTION__, addr);
					T value = *addr;
//fprintf(stderr, "[%s] ====> value = %d\n", __FUNCTION__, value);
					return memory_cell<T>(address, value);
				}

				template<typename T> memory_segment_iterator<T>  begin() {
					return memory_segment_iterator<T>(_address, reinterpret_cast<T*>(_data));
				}

				template<typename T> memory_segment_iterator<T>  end() {
					size_t offset = get_size<T>();
					return memory_segment_iterator<T>(_address + offset,(reinterpret_cast<T*>(_data)+offset));
				}

				inline int load_from_file(const char *filename) {
		    		return load_from_file(0, filename);
				}
				inline int load_from_file(const char *filename, size_t size) {
		    		return load_from_file(0, filename, size);
				}
				int load_from_file(uint32_t offset, const char *filename);
				int load_from_file(uint32_t offset, const char *filename, size_t size);
				int load(uint32_t offset, std::streambuf *stream, size_t size);

	    	private:
				void _init(uint32_t address, size_t size);
		};
    };
};

#endif
