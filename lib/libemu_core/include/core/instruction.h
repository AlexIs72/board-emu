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
				virtual size_t	get_size() const = 0;
				virtual bool exec() = 0;
		};

		template <typename T> 
		class instruction : public i_instruction {
			private:
				T	_raw_value;
			public:
				instruction() : _raw_value(0) {}
				instruction(T value) : _raw_value(value) {}
				virtual ~instruction() {}

				virtual std::string to_string() { return std::string(); }

				virtual std::string opcode_to_string()  {
    				std::stringstream ss;
    				size_t  size = get_size();
    				uint32_t value = _get_raw_value();
    				if(size == 4) {
        				ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
						value <<= 8;
    				}
    				if(size >= 3) {
        				ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
//						value >>= 8;
						value <<= 8;
					
    				}
    				if(size >= 2) {
//        				ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0x0000FF00) >> 8) << " ";
        				ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
						value <<= 8;
    				}
    				if(size >= 1) {
//        				ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << (value & 0x000000FF);
        				ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
						value <<= 8;
    				}

    				return ss.str();
				}
 
			protected:
				virtual inline T	_get_raw_value() const { 
					return _raw_value; 
				}

		};

		class unknown_instruction : public instruction<uint32_t> {
			public:
//				unknown_instruction(emu::core::memory_cell<uint32_t> &cell) : instruction(cell) {};
				unknown_instruction() : instruction(0) {};
				unknown_instruction(uint32_t value) : instruction(value) {};
				virtual ~unknown_instruction() {};
				std::string to_string() { return std::string("Unknown instruction"); }
				virtual inline size_t  get_size() const {
					return 1;
				}
				virtual inline bool exec() {
					return false;
				}
		};
	};
};


#endif