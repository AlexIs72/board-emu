//#include <stdexcept>

#include <memory/segment.h>



/*
http://en.cppreference.com/w/cpp/error/exception
*/

using namespace emu::core;


memory_segment::memory_segment() {
	_init(0, 0);
}

memory_segment::memory_segment(uint32_t address) {
    _init(address, 0);
}

memory_segment::memory_segment(uint32_t address, size_t size) {
    _init(address, size);
}

memory_segment::~memory_segment() {
    if(_data) {
		free(_data);
    }
}

void memory_segment::_init(uint32_t address, size_t size) {
    _address = address;
    _data = NULL;
    _size = size;

	if(_size) {
		// TODO Move to seperate method
		_data = reinterpret_cast<uint8_t *>(calloc(_size, sizeof(uint8_t)));
	}
}

int memory_segment::load_from_file(uint32_t offset, const char *filename) {
    std::ifstream ifs (filename, std::ifstream::binary);

    if(ifs) {
		std::filebuf* pbuf = ifs.rdbuf();
	// get file size using buffer's members
		size_t size = pbuf->pubseekoff (0,ifs.end,ifs.in);
		pbuf->pubseekpos (0,ifs.in);
//	ifs.close();
		return load(offset, pbuf, size);
    }
    
    throw std::invalid_argument("Invalid input file!");
}

int memory_segment::load(uint32_t offset, std::streambuf *stream, size_t size) {
    if(_data) {
    // TODO Add realloc and using offset
		free(_data);
		_data = NULL;
    }
    // allocate memory to contain file data
	// TODO Move to seperate method
	_data = reinterpret_cast<uint8_t *>(calloc(size, sizeof(uint8_t)));

    // get file data
    stream->sgetn(reinterpret_cast<char *>(_data+offset), size);

	// TODO need to fix size+offset
	_size = size;

    return 0;
}

