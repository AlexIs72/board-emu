//#include <map>

#include <core/board.h>

using namespace emu::core;

board::board() : _debug_interface(NULL)/*, _cpu(NULL)*/ { 

}

board::~board() { 
	if(_debug_interface) {
		delete _debug_interface;
		_debug_interface = NULL;
	}
/*
	if(_cpu) {
		delete _cpu;
		_cpu = NULL;
	}
*/
//	if(_memory_segments_list.count()) {
//		std::map<std::string, memory_segment *>::iterator it; // = std::map::begin();
		for(memory_segments_list_t::iterator it = _memory_segments_list.begin(); it != _memory_segments_list.end(); ++it) {
printf("====> destroy segment with name: %s\n", it->first.c_str());
			_delete_memory_segment(it);			
		}
//	}
}


uint32_t board::get_memory_segment_address(const char *segment_name) {
	return 0;
}

bool board::load_memory_segment(const char *name, uint8_t *block_ptr, size_t size) {
/*
	memory_segments_list_t::iterator it = _memory_segments_list.find(segment_name);
    if(it != _memory_segments_list.end()) {
		// ...
		return true;
	}
*/
	return false;
}

/*
bool board::load_memory_segment(uint32_t address, uint8_t *block_ptr, size_t size) {
	return false;
}
*/

bool board::load_memory_segment_from_file(const char *file_name, const char *segment_name/*, uint8_t *block_ptr, size_t size*/) {
	memory_segments_list_t::iterator it = _memory_segments_list.find(segment_name);
    if(it != _memory_segments_list.end()) {
		it->second->load_from_file(file_name);
		return true;
	}
	return false;
}

/*
bool board::load_memory_segment_from_file(const char *file_name, uint32_t address) {
	return false;
}
*/

bool board::_create_memory_segment(const char *segment_name, uint32_t address, size_t size) {
printf("====> create memory segment with name: %s\n", segment_name);
	memory_segments_list_t::iterator it = _memory_segments_list.find(segment_name);	
	if(it != _memory_segments_list.end()) {
		_delete_memory_segment(segment_name);
	}

	memory_segment *seg = new memory_segment(address, size);

	_memory_segments_list[segment_name] = seg;

	_get_system_bus()->register_memory(seg);

	return false;
}

bool board::_delete_memory_segment(const char *segment_name) {
	return _delete_memory_segment(_memory_segments_list.find(segment_name));
}

bool board::_delete_memory_segment(memory_segments_list_t::iterator it) {
	if (it != _memory_segments_list.end()) {
		_get_system_bus()->unregister_memory(it->second);
		delete it->second;
    	_memory_segments_list.erase (it);	
		return true;
	}
	return false;
}

