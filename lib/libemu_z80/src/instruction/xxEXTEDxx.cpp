#include <sstream>
#include <iomanip>

#include "include/xxEXTEDxx.h"

using namespace emu::z80;

#if 0

std::string xxEXTEDxx_instruction::opcode_to_string()  {
    std::stringstream ss;
    size_t  size = get_size();
    uint32_t value =  _get_raw_value();

/*    if(size == 2) {
        ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
        return ss.str();
    } else*/ if(size == 2) {
        ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0xFF000000) >> 24) << " ";
        ss << std::hex << std::setfill('0') << std::internal << std::setw(2) << ((value & 0x00FF0000) >> 16) << " ";
        return ss.str();
    }

    return emu::core::instruction<uint32_t>::opcode_to_string();
}

#endif