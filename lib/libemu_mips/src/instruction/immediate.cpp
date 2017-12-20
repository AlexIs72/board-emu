#include "include/immediate.h"

#include "immediate/include/lui.h"
#include "immediate/include/addiu.h"


using namespace emu::mips;


immediate_instruction::immediate_instruction(emu::mips::memory_cell &cell) : instruction(cell) {
	_type_format.raw = _get_raw_value();
}


/*
struct mips_instruction_handler op_i_handlers[OP_HANDLERS_LIST_SIZE] = {
/ * 0x00 * /      { 0xFF, NULL, NULL, NULL, NULL },		//	SPECIAL
/ * 0x01 * /      { 0x01, "bgez", __mtr_asm_decode_branch_if_great_then_zero, __mtr_c_decode_branch_if_great_then_zero, __mtr_execute_bgez },
/ * 0x02 * /      { 0xFF, NULL, NULL, NULL, NULL },
/ * 0x03 * /      { 0xFF, NULL, NULL, NULL, NULL },
/ * 0x04 * /      { 0x04, "beq", __mtr_asm_decode_branches, __mtr_c_decode_beq, __mtr_execute_beq },			/ *	beq rs, rt, label 		000100 			0x04 	Branch on equal	* /
/ * 0x05 * /      { 0x05, "bne", __mtr_asm_decode_branches, __mtr_c_decode_bne, NULL },						/ *	bne rs, rt, label 		000101 			0x05 	Branch on not equal	* /
/ * 0x06 * /      { 0x06, "blez", __mtr_asm_decode_branch_if_zero, __mtr_c_decode_blez, NULL },				/ *	blez rs, label 			000110 rt=00000 0x06 	Branch on less than or equal to zero 	* /
/ * 0x07 * /      { 0x07, "bgtz", __mtr_asm_decode_branch_if_zero, __mtr_c_decode_bgtz, NULL },				/ *	bgtz rs, label 			000111 rt=00000 0x07 	Branch on greater than zero 			* /
/ * 0x08 * /      { 0x08, "addi", __mtr_asm_decode_two_reg_i, __mtr_c_decode_addi, __mtr_execute_addi },		/ *	addi rt, rs, immediate 	001000 			0x08 	Add immediate (with overflow) 			* /
/ * 0x09 * /      { 0x09, "addiu", __mtr_asm_decode_two_reg_i, __mtr_c_decode_addi, __mtr_execute_addi },		/ *	addiu rt, rs, immediate 001001 			0x09 	Add immediate unsigned (no overflow) 	* /
/ * 0x0A * /      { 0x0A, "slti", __mtr_asm_decode_two_reg_i, __mtr_c_decode_slti, NULL },					/ *	slti rt, rs, immediate 	001010 			0x0A 	Set on less than immediate (signed) 	* /
/ * 0x0B * /      { 0x0B, "sltiu", __mtr_asm_decode_two_reg_i, __mtr_c_decode_slti, NULL },					/ *	sltiu rt, rs, immediate 001011 			0x0B 	Set on less than immediate unsigned 	* /
/ * 0x0C * /      { 0x0C, "andi", __mtr_asm_decode_two_reg_i, __mtr_c_decode_bitwise_i, __mtr_execute_andi },	/ *	andi rt, rs, immediate 	001100 			0x0C 	Bitwise and immediate 					* /
/ * 0x0D * /      { 0x0D, "ori", __mtr_asm_decode_two_reg_i, __mtr_c_decode_bitwise_i, __mtr_execute_ori },	/ *	ori rt, rs, immediate 	001101 			0x0D 	Bitwise or immediate					* /
/ * 0x0E * /      { 0x0E, "xori", __mtr_asm_decode_two_reg_i, __mtr_c_decode_bitwise_i, __mtr_execute_xori },	/ *	xori rt, rs, immediate 	001110 			0x0E 	Bitwise exclusive or immediate 			* /
/ * 0x0F * /      { 0x0F, "lui", __mtr_asm_decode_one_reg, __mtr_c_decode_lui, __mtr_execute_lui },			/ *	lui rt, immediate 		001111 			0x0F 	Load upper immediate 					* /
/ * 0x10 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x11 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x12 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x13 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x14 * /      { 0x14, "beql", __mtr_asm_decode_branches, __mtr_c_decode_beql, NULL },	/ *	* /
/ * 0x15 * /      { 0x15, "bnel", __mtr_asm_decode_branches, __mtr_c_decode_bnel, NULL },	/ *	* /
/ * 0x16 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x17 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x18 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x19 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x1A * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x1B * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x1C * /      { 0x1C, "special2", __mtr_asm_decode_special2, __mtr_c_decode_special2, NULL },	/ *	* /		// SPECIAL2
/ * 0x1D * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x1E * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x1F * /      { 0x1F, "special3", __mtr_asm_decode_special3, __mtr_c_decode_special3, NULL },	/ *	* /
/ * 0x20 * /      { 0x20, "lb", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	lb rt, immediate(rs) 	100000 			0x20 	Load byte 								* /
/ * 0x21 * /      { 0x21, "lh", __mtr_asm_decode_one_reg, __mtr_c_decode_load, __mtr_execute_lh },	/ *	lh rt, immediate(rs) 	100001 			0x21 	Load halfword 							* /
/ * 0x22 * /      { 0x22, "lwl", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	* /
/ * 0x23 * /      { 0x23, "lw", __mtr_asm_decode_one_reg, __mtr_c_decode_load, __mtr_execute_lw },		/ *	lw rt, immediate(rs) 	100011 			0x23 	Load word 								* /
/ * 0x24 * /      { 0x24, "lbu", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	lbu rt, immediate(rs) 	100100 			0x24 	Load byte unsigned 						* /
/ * 0x25 * /      { 0x25, "lhu", __mtr_asm_decode_one_reg, __mtr_c_decode_load, __mtr_execute_lhu },	/ *	lhu rt, immediate(rs) 	100101 			0x25 	Load halfword unsigned 					* /
/ * 0x26 * /      { 0x26, "lwr", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	* /
/ * 0x27 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x28 * /      { 0x28, "sb", __mtr_asm_decode_one_reg, __mtr_c_decode_save, NULL },	/ *	sb rt, immediate(rs) 	101000 			0x28 	Store byte 								* /
/ * 0x29 * /      { 0x29, "sh", __mtr_asm_decode_one_reg, __mtr_c_decode_save, __mtr_execute_sh },	/ *	sh rt, immediate(rs) 	101001 			0x29 	Store halfword 							* /
/ * 0x2A * /      { 0x2A, "swl", __mtr_asm_decode_one_reg, __mtr_c_decode_save, NULL },	/ *	* /
/ * 0x2B * /      { 0x2B, "sw", __mtr_asm_decode_one_reg, __mtr_c_decode_save, __mtr_execute_sw },		/ *	sw rt, immediate(rs) 	101011 			0x2B 	Store word 								* /
/ * 0x2C * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x2D * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x2E * /      { 0x2E, "swr", __mtr_asm_decode_one_reg,  __mtr_c_decode_save, NULL },	/ *	* /
/ * 0x2F * /      { 0x2F, "cache", __mtr_asm_decode_cache, __mtr_c_decode_cache, NULL },	/ *	CACHE op, offset(base)	* /
/ * 0x30 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x31 * /      { 0x31, "lwc1", __mtr_asm_decode_one_reg, NULL, NULL },	/ *	lwc1 rt, immediate(rs) 	110001 			0x31 	Load word coprocessor 1 				* /
/ * 0x32 * /      { 0x32, "swc1", __mtr_asm_decode_one_reg, NULL, NULL },	/ *	swc1 rt, immediate(rs) 	111001 			0x39 	Store word coprocessor 1 				* /
/ * 0x33 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x34 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x35 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x36 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x37 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x38 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x39 * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x3A * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x3B * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x3C * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x3D * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /  
/ * 0x3E * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
/ * 0x3F * /      { 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
};
*/


emu::core::i_instruction *immediate_instruction::get(__attribute__((unused)) emu::mips::memory_cell &cell) {
	immediate_type_format_t tf;	
	emu::core::i_instruction *instruction = NULL;	

	tf.raw = cell.value();

	switch(tf.format.o) {
/*		case 0x00:       	//{ 0xFF, NULL, NULL, NULL, NULL },		//	SPECIAL
			break;
*/
        case 0x01:          //{ 0x01, "bgez", __mtr_asm_decode_branch_if_great_then_zero, __mtr_c_decode_branch_if_great_then_zero, __mtr_execute_bgez },
			break;
/*        case 0x02:          //{ 0xFF, NULL, NULL, NULL, NULL },
			break;
        case 0x03:          //{ 0xFF, NULL, NULL, NULL, NULL },
			break;
*/
        case 0x04:          //{ 0x04, "beq", __mtr_asm_decode_branches, __mtr_c_decode_beq, __mtr_execute_beq },			/ *	beq rs, rt, label 		000100 			0x04 	Branch on equal	* /
			break;
        case 0x05:          //{ 0x05, "bne", __mtr_asm_decode_branches, __mtr_c_decode_bne, NULL },						/ *	bne rs, rt, label 		000101 			0x05 	Branch on not equal	* /
			break;
        case 0x06:          //{ 0x06, "blez", __mtr_asm_decode_branch_if_zero, __mtr_c_decode_blez, NULL },				/ *	blez rs, label 			000110 rt=00000 0x06 	Branch on less than or equal to zero 	* /
			break;
        case 0x07:          //{ 0x07, "bgtz", __mtr_asm_decode_branch_if_zero, __mtr_c_decode_bgtz, NULL },				/ *	bgtz rs, label 			000111 rt=00000 0x07 	Branch on greater than zero 			* /
			break;
        case 0x08:          //{ 0x08, "addi", __mtr_asm_decode_two_reg_i, __mtr_c_decode_addi, __mtr_execute_addi },		/ *	addi rt, rs, immediate 	001000 			0x08 	Add immediate (with overflow) 			* /
			break;
        case 0x09:          //{ 0x09, "addiu", __mtr_asm_decode_two_reg_i, __mtr_c_decode_addi, __mtr_execute_addi },		/ *	addiu rt, rs, immediate 001001 			0x09 	Add immediate unsigned (no overflow) 	* /
			instruction = new addiu_instruction(cell);
			break;
        case 0x0A:          //{ 0x0A, "slti", __mtr_asm_decode_two_reg_i, __mtr_c_decode_slti, NULL },					/ *	slti rt, rs, immediate 	001010 			0x0A 	Set on less than immediate (signed) 	* /
			break;
        case 0x0B:          //{ 0x0B, "sltiu", __mtr_asm_decode_two_reg_i, __mtr_c_decode_slti, NULL },					/ *	sltiu rt, rs, immediate 001011 			0x0B 	Set on less than immediate unsigned 	* /
			break;
        case 0x0C:          //{ 0x0C, "andi", __mtr_asm_decode_two_reg_i, __mtr_c_decode_bitwise_i, __mtr_execute_andi },	/ *	andi rt, rs, immediate 	001100 			0x0C 	Bitwise and immediate 					* /
			break;
        case 0x0D:          //{ 0x0D, "ori", __mtr_asm_decode_two_reg_i, __mtr_c_decode_bitwise_i, __mtr_execute_ori },	/ *	ori rt, rs, immediate 	001101 			0x0D 	Bitwise or immediate					* /
			break;
        case 0x0E:          //{ 0x0E, "xori", __mtr_asm_decode_two_reg_i, __mtr_c_decode_bitwise_i, __mtr_execute_xori },	/ *	xori rt, rs, immediate 	001110 			0x0E 	Bitwise exclusive or immediate 			* /
			break;
        case 0x0F:          //{ 0x0F, "lui", __mtr_asm_decode_one_reg, __mtr_c_decode_lui, __mtr_execute_lui },			/ *	lui rt, immediate 		001111 			0x0F 	Load upper immediate 					* /
			instruction = new lui_instruction(cell);
			break;
/*        case 0x10:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x11:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x12:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x13:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
*/
        case 0x14:          //{ 0x14, "beql", __mtr_asm_decode_branches, __mtr_c_decode_beql, NULL },	/ *	* /
			break;
        case 0x15:          //{ 0x15, "bnel", __mtr_asm_decode_branches, __mtr_c_decode_bnel, NULL },	/ *	* /
			break;
/*        case 0x16:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x17:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x18:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x19:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x1A:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x1B:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
*/
        case 0x1C:          //{ 0x1C, "special2", __mtr_asm_decode_special2, __mtr_c_decode_special2, NULL },	/ *	* /		// SPECIAL2
			break;
/*        case 0x1D:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;l
        case 0x1E:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
*/
        case 0x1F:          //{ 0x1F, "special3", __mtr_asm_decode_special3, __mtr_c_decode_special3, NULL },	/ *	* /
			break;
        case 0x20:          //{ 0x20, "lb", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	lb rt, immediate(rs) 	100000 			0x20 	Load byte 								* /
			break;
        case 0x21:          //{ 0x21, "lh", __mtr_asm_decode_one_reg, __mtr_c_decode_load, __mtr_execute_lh },	/ *	lh rt, immediate(rs) 	100001 			0x21 	Load halfword 							* /
			break;
        case 0x22:          //{ 0x22, "lwl", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	* /
			break;
        case 0x23:          //{ 0x23, "lw", __mtr_asm_decode_one_reg, __mtr_c_decode_load, __mtr_execute_lw },		/ *	lw rt, immediate(rs) 	100011 			0x23 	Load word 								* /
			break;
        case 0x24:          //{ 0x24, "lbu", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	lbu rt, immediate(rs) 	100100 			0x24 	Load byte unsigned 						* /
			break;
        case 0x25:          //{ 0x25, "lhu", __mtr_asm_decode_one_reg, __mtr_c_decode_load, __mtr_execute_lhu },	/ *	lhu rt, immediate(rs) 	100101 			0x25 	Load halfword unsigned 					* /
			break;
        case 0x26:          //{ 0x26, "lwr", __mtr_asm_decode_one_reg, __mtr_c_decode_load, NULL },	/ *	* /
			break;
/*        case 0x27:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
*/
        case 0x28:          //{ 0x28, "sb", __mtr_asm_decode_one_reg, __mtr_c_decode_save, NULL },	/ *	sb rt, immediate(rs) 	101000 			0x28 	Store byte 								* /
			break;
        case 0x29:          //{ 0x29, "sh", __mtr_asm_decode_one_reg, __mtr_c_decode_save, __mtr_execute_sh },	/ *	sh rt, immediate(rs) 	101001 			0x29 	Store halfword 							* /
			break;
        case 0x2A:          //{ 0x2A, "swl", __mtr_asm_decode_one_reg, __mtr_c_decode_save, NULL },	/ *	* /
			break;
        case 0x2B:          //{ 0x2B, "sw", __mtr_asm_decode_one_reg, __mtr_c_decode_save, __mtr_execute_sw },		/ *	sw rt, immediate(rs) 	101011 			0x2B 	Store word 								* /
			break;
/*        case 0x2C:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x2D:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
*/
        case 0x2E:          //{ 0x2E, "swr", __mtr_asm_decode_one_reg,  __mtr_c_decode_save, NULL },	/ *	* /
			break;
        case 0x2F:          //{ 0x2F, "cache", __mtr_asm_decode_cache, __mtr_c_decode_cache, NULL },	/ *	CACHE op, offset(base)	* /
			break;
/*        case 0x30:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
*/
        case 0x31:          //{ 0x31, "lwc1", __mtr_asm_decode_one_reg, NULL, NULL },	/ *	lwc1 rt, immediate(rs) 	110001 			0x31 	Load word coprocessor 1 				* /
			break;
        case 0x32:          //{ 0x32, "swc1", __mtr_asm_decode_one_reg, NULL, NULL },	/ *	swc1 rt, immediate(rs) 	111001 			0x39 	Store word coprocessor 1 				* /
			break;
/*        case 0x33:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x34:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x35:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x36:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x37:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x38:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x39:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x3A:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x3B:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x3C:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x3D:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x3E:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
        case 0x3F:          //{ 0xFF, NULL, NULL, NULL, NULL },	/ *	* /
			break;
*/
		default:
			instruction = new immediate_instruction(cell);
			break;
	}

	if(instruction == NULL) {
		instruction = new immediate_instruction(cell);
	}

    return instruction;
}

