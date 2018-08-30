#ifndef __EMU_CORE_BASE_PROCESSOR_H__
#define __EMU_CORE_BASE_PROCESSOR_H__

#include <string>
/*
typedef enum {
	UNKNOWN_CHIP = 0,
	MEMORY_CHIP,
	MPU_CHIP,
	MCU_CHIP
} chip_type_t;
*/

namespace emu {
	namespace core {
/*		class i_chip {
			virtual std::string get_name() = 0;
			virtual chip_type_t get_type() = 0;
		};
*/
		class processor /*: public i_chip*/ {
			public:
				processor() { }
				virtual ~processor() { }
				virtual std::string get_name() = 0;
//				virtual chip_type_t get_type() = 0;
//				virtual chip_type_t get_type() { return UNKNOWN_CHIP; }
		};
	};
};


#endif