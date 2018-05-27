#include <z80/instruction.h>

using namespace emu::z80;

const char *reg_str[][2] = {
	{"",""}
};


instruction::instruction(emu::z80::memory_cell &cell) : emu::core::instruction(cell.address(), cell.value()) {

}

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

/*
void instruction::_init(uint32_t address, uint32_t value) {
	_address = address;
	_raw_value = value;
}*/
