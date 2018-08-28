#include <iomanip>
#include <sstream>


#include <core/instruction.h>

using namespace emu::core;

/*instruction::instruction() {
	_init(0,0);
}
*/
#if 0
instruction::instruction(emu::core::memory_cell<uint32_t> &cell) {
	_init(cell.address(), cell.value());
}

instruction::instruction(uint32_t address, uint32_t value) {
	_init(address, value);
}

instruction::~instruction() {
}

void instruction::_init(uint32_t address, uint32_t value) {
	_address = address;
	_raw_value = value;
}

template <class T>
std::string instruction<T>::opcode_to_string() { 
    std::stringstream ss;
    size_t  size = get_size();
    uint32_t value = _get_raw_value();

    ss << std::hex << std::setfill(' ') << std::left << std::setw(2);
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
#endif
