#ifndef __EMU_CORE_BUS_H__
#define __EMU_CORE_BUS_H__

#include <stdint.h>

#include <vector>

#include <core/memory/segment.h>
#include <core/port.h>

namespace emu {
    namespace core {
		class i_bus {
			public:
		};

		class i_bus_listener {
			public:
				
		};

		class bus : public i_bus {
			private:
				typedef std::vector<memory_segment *>	memory_devices_list_t;
				memory_devices_list_t	_memory_devices;		

				typedef std::vector<port *>	ports_list_t;
				ports_list_t	_ports;		

			public:

				bool	register_memory(memory_segment *device);				
				bool	unregister_memory(memory_segment *device);				

				bool	register_port(port *device);				
				bool	unregister_port(port *device);				


				template<class T>
				T read_memory(uint32_t address) {
					memory_segment *mem = _find_memory_by_address(address);
					if(mem) {
						memory_cell<T> cell  = mem->get_raw<T>(address);
						return cell.value();
					}

					// TODO need to add exception
					return 0;
				}    

				template<class T>
				T read_port(uint32_t address) { /*address = 0;*/ return address; }

				template<class T>
				bool write_memory(uint32_t address, T value) { /*address = 0;*/ return false; }

				template<class T>
				bool write_port(uint32_t address, T value) { /*address = 0;*/ return false; }

			private:
				memory_segment 	*_find_memory_by_address(uint32_t address/*, size_t size*/);								
				port 			*_find_port_by_address(uint32_t address);								

		};
	};
};

#endif