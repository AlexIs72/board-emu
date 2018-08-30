#include <core/board.h>

using namespace emu::core;

/*
bool board::_attach_central_unit(cu_chip *cu) {
	return false;
}

bool board::_attach_memory(i_memory_chip *mem) {
	return false;
}
*/

board::board() : _debug_interface(NULL), _cpu(NULL) { 

}

board::~board() { 
	if(_debug_interface) {
		delete _debug_interface;
		_debug_interface = NULL;
	}

	if(_cpu) {
		delete _cpu;
		_cpu = NULL;
	}
}


uint32_t board::get_memory_segment_address(const char *segment_name) {
	return 0;
}

bool board::load_memory_segment(const char *name, uint8_t *block_ptr, size_t size) {
	return false;
}

bool board::load_memory_segment(uint32_t address, uint8_t *block_ptr, size_t size) {
	return false;
}

bool board::load_memory_segment_from_file(const char *file_name, const char *segment_name, uint8_t *block_ptr, size_t size) {
	return false;
}

bool board::load_memory_segment_from_file(const char *file_name, uint32_t address, uint8_t *block_ptr, size_t size) {
	return false;
}


bool board::_create_memory_segment(const char *segment_name, uint32_t address, size_t size) {
printf("====> create memory segment with name: %s\n", segment_name);
	return false;
}

bool board::_attach_processor(processor *cpu) {
	_cpu = cpu;
	return true;
}
