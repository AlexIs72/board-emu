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

#include <core/bus.h>

namespace emu {
	namespace core {
/*		class i_chip {
			virtual std::string get_name() = 0;
			virtual chip_type_t get_type() = 0;
		};
*/
		class processor : public i_bus_listener/*: public i_chip*/ {
			private:
				bus	*_system_bus;
			public:
				processor() : _system_bus(NULL) { }
				virtual ~processor() { }

				virtual std::string get_name() = 0;
				virtual void reset() = 0;
				virtual bool next() = 0;

				inline virtual bool connect_to_bus(bus *system_bus) {
					_system_bus = system_bus;
					return true;
				}

			protected:
				// TODO Need to add exception
				inline bus *get_system_bus() { return _system_bus; }

//				virtual chip_type_t get_type() = 0;
//				virtual chip_type_t get_type() { return UNKNOWN_CHIP; }
		};
	};
};


#endif