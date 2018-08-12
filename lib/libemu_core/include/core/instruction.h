#ifndef __EMU_CORE_BASE_INSTRUCTION_H__
#define __EMU_CORE_BASE_INSTRUCTION_H__

#include <stdint.h>

#include <string>
#include <iomanip>
#include <sstream>


#include <core/memory/cell.h>

namespace emu {
	namespace core {
		class i_instruction {
			public:
				virtual std::string to_string() = 0;
				virtual std::string opcode_to_string() = 0 /* { return std::string()}*/;
				virtual size_t	get_size() = 0;
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

				virtual std::string to_string() { return std::string(); }
				virtual std::string opcode_to_string()  {
    				std::stringstream ss;
    				size_t  size = get_size();
    				uint32_t value = _get_raw_value();

    				ss << std::hex << std::setfill('0') << std::left << std::setw(2);
    				if(size == 4) {
        				ss << ((value & 0xFF000000) >> 24) << " ";
    				}
    				if(size >= 3) {
        				ss << ((value & 0x00FF0000) >> 16) << " ";
    				}
    				if(size >= 2) {
        				ss << ((value & 0x0000FF00) >> 8) << " ";
    				}
    				if(size >= 1) {
        				ss << (value & 0x000000FF);
    				}

    				return ss.str();
				}
 

//				inline T get_raw_value() { return _raw_value; }

			protected:
				virtual inline T	_get_raw_value() { return _raw_value; }
//				virtual inline uint32_t _get_address() { return _address; }

			private:
//				void _init(uint32_t address, uint32_t value);

		};

		class unknown_instruction : public instruction<uint32_t> {
			public:
//				unknown_instruction(emu::core::memory_cell<uint32_t> &cell) : instruction(cell) {};
				unknown_instruction() : instruction(0) {};
				unknown_instruction(uint32_t value) : instruction(value) {};
				virtual ~unknown_instruction() {};
				std::string to_string() { return std::string("Unknown instruction"); }
				virtual size_t  get_size() {return 1;}
		};
	};
};


#endif