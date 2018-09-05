#include <core/bus.h>

using namespace emu::core;
/*
template <class T>
T bus::read_memory(uint32_t address) {
	return address;
}
*/
bool    bus::register_memory(memory_segment *mem) {
	
	memory_segment *tmp = _find_memory_by_address(mem->get_address()/*, mem->get_size()*/);

	if(tmp == NULL) {
		_memory_devices.push_back(mem);
		return true;
	}

	return false;
}

bool    bus::unregister_memory(memory_segment *mem) {
	for(memory_devices_list_t::iterator it =  _memory_devices.begin(); it !=  _memory_devices.end(); /*++it*/) {
		memory_segment *tmp = *it;		
		uint32_t tmp_addr = tmp->get_address();

		if(tmp->get_address() == mem->get_address()) {
			it = _memory_devices.erase(it);
		} else {
			++it;
		}
	}
	
	return true;
}


bool    bus::register_port(port *device) {
	return false;
}

bool    bus::unregister_port(port *device) {
	return false;
}

memory_segment  *bus::_find_memory_by_address(uint32_t address/*, size_t size*/) {
	for(memory_devices_list_t::iterator it =  _memory_devices.begin(); it !=  _memory_devices.end(); ++it) {
		memory_segment *tmp = *it;		
/*		uint32_t tmp_addr = tmp->get_address();
		uint32_t size = tmp->get_size<uint32_t>();
*/
/*		if(tmp->get_address() == address) {
			return tmp;
		}
*/
/*		if(address >=  tmp_addr && address <= tmp_addr+size) {
			return tmp;
		}
*/
		if(tmp->is_contain_address(address)) {
			return tmp;
		}
	}
	return NULL;
}

port *bus::_find_port_by_address(uint32_t address) {
	for(ports_list_t::iterator it =  _ports.begin(); it !=  _ports.end(); ++it) {
		
	}
	return NULL;
}

