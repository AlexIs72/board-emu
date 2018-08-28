#include <z80/instruction.h>

using namespace emu::z80;

const char *reg_str[][2] = {
       {"",""}
};


/*
instruction::instruction(emu::z80::memory_cell &cell) : emu::core::instruction(cell.address(), cell.value()) {

}
*/
instruction::~instruction() {
}

const char *instruction::_reg_to_str(uint8_t reg) {
    if(reg < sizeof(reg_str)/sizeof(char*)) {
        return reg_str[reg][0];
    }
    
//    return MTR_INVALID_REG;
// TODO
	return 0;
}
/*
uint8_t instruction::_get_byte_value() const {
	return (_get_raw_value() & 0x00FF0000) >> 16;
}

uint16_t instruction::_get_halfword_value() {
	return (_get_raw_value() & 0x00FFFF00) >> 8;
}

uint32_t _get_word_value() {
}
*/

#if 0
std::string instruction::opcode_to_string()  {
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

uint8_t instruction::get_opcode() {
	return get_opcode(_get_raw_value());
}

uint8_t instruction::get_opcode(uint32_t value) {
	return ((value & 0xFF000000) >> 24);
}
#endif
