#include <byteswap.h>

#include <z80/processor.h>
#include <z80/instruction.h>
#include <z80/instruction/factory.h>


using namespace emu::z80;

processor::processor() : emu::core::processor(), _current_registers_set(&_main) { 

	reset();

}

void processor::reset() {
	_main.set<uint8_t>("A", 0);
	_main.set<uint8_t>("F", 0);
	_main.set<uint8_t>("B", 0);
	_main.set<uint8_t>("C", 0);
	_main.set<uint8_t>("D", 0);
	_main.set<uint8_t>("E", 0);
	_main.set<uint8_t>("H", 0);
	_main.set<uint8_t>("L", 0);

	_secondary.set<uint8_t>("A'", 0);
	_secondary.set<uint8_t>("F'", 0);
	_secondary.set<uint8_t>("B'", 0);
	_secondary.set<uint8_t>("C'", 0);
	_secondary.set<uint8_t>("D'", 0);
	_secondary.set<uint8_t>("E'", 0);
	_secondary.set<uint8_t>("H'", 0);
	_secondary.set<uint8_t>("L'", 0);

	_special.set<uint8_t>("I", 0);
	_special.set<uint8_t>("R", 0);
	_special.set<uint16_t>("IX", 0);	//	Индексный регистр
	_special.set<uint16_t>("IY", 0);	//	Индексный регистр
	_special.set<uint16_t>("SP", 0);	//	Указатель стека
	_special.set<uint16_t>("PC", 0);	//	Счётчик команд

}

/*
https://stackoverflow.com/questions/105252/how-do-i-convert-between-big-endian-and-little-endian-values-in-c
*/

bool processor::next() {
	uint16_t address = _current_registers_set->get<uint16_t>("PC");

//	TODO Check is valid address
	
	uint32_t value = get_system_bus()->read_memory<uint32_t>(address);
//int32_t bswap_32(int32_t x)
	value = bswap_32(value);

	emu::core::i_instruction *instr = emu::z80::factory::get_instruction(value);
	

printf("===> address = 0x%04X, value = %08X, instr: [%lu] %s\n", address, value, instr->get_size(), instr->to_string().c_str());

	address += instr->get_size();
	_current_registers_set->set<uint16_t>("PC", address);

	return true;
}

