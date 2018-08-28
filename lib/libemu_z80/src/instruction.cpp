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

const char *instruction::reg_to_str(uint8_t reg) {
    if(reg < sizeof(reg_str)/sizeof(char*)) {
        return reg_str[reg][0];
    }
    
//    return MTR_INVALID_REG;
// TODO
	return 0;
}

#if 0
std::string instruction::opcode_to_string() {
    std::stringstream ss;
	size_t	size = get_size();
	uint32_t value = _get_raw_value();

/*    ss  << "lui "
        << t_reg_str << ", "
        << std::hex << "0x" << _get_immediate_data();
*/
	ss << std::hex << std::setfill(' ') << std::left << std::setw(2);
	if(size == 4) {
		ss << /*std::setw(2) << */((value & 0xFF000000) >> 24) << " ";
	} 
	if(size >= 3) {
		ss << /*std::setw(2) << */((value & 0x00FF0000) >> 16) << " ";
	} 
    if(size >= 2) {
		ss << /*std::setw(2) << */((value & 0x0000FF00) >> 8) << " ";
	} 
	if(size >= 1) {
		ss << /*std::setw(2) << */(value & 0x000000FF);
	}

    return ss.str();


}
#endif

