#include <mips/instruction.h>

using namespace emu::mips;

const char *reg_str[][2] = {
	{"$zero","CPU_REG_ZERO"},
	{"$at","CPU_REG_AT"}, 		
	{"$v0","CPU_REG_V0"},		
	{"$v1","CPU_REG_V1"},
	{"$a0","CPU_REG_A0"},		
	{"$a1","CPU_REG_A1"},
	{"$a2","CPU_REG_A2"},
	{"$a3","CPU_REG_A3"},
	{"$t0","CPU_REG_T0"},		
	{"$t1","CPU_REG_T1"},
	{"$t2","CPU_REG_T2"},
	{"$t3","CPU_REG_T3"},
	{"$t4","CPU_REG_T4"},
	{"$t5","CPU_REG_T5"},
	{"$t6","CPU_REG_T6"},
	{"$t7","CPU_REG_T7"},
	{"$s0","CPU_REG_S0"},		
	{"$s1","CPU_REG_S1"},
	{"$s2","CPU_REG_S2"},
	{"$s3","CPU_REG_S3"},
	{"$s4","CPU_REG_S4"},
	{"$s5","CPU_REG_S5"},
	{"$s6","CPU_REG_S6"},
	{"$s7","CPU_REG_S7"},
	{"$t8","CPU_REG_T8"},		
	{"$t9","CPU_REG_T9"},
	{"$k0","CPU_REG_K0"},		
	{"$k1","CPU_REG_K1"},
	{"$gp","CPU_REG_GP"},		
	{"$sp","CPU_REG_SP"},
	{"$fp","CPU_REG_FP"},
	{"$ra","CPU_REG_RA"}
};


instruction::instruction(emu::mips::memory_cell &cell) : emu::core::instruction(cell.address(), cell.value()) {

}

instruction::~instruction() {
}

const char *instruction::reg_to_str(uint8_t reg) {
    if(reg < sizeof(reg_str)/sizeof(char*)) {
        return reg_str[reg][0];
    }
    
    return MTR_INVALID_REG;
}

/*
void instruction::_init(uint32_t address, uint32_t value) {
	_address = address;
	_raw_value = value;
}*/
