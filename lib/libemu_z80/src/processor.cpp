#include <stdio.h>
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
	uint16_t address =  _special.get<uint16_t>("PC");

//	TODO Check is valid address
	
	uint32_t value = get_system_bus()->read_memory<uint32_t>(address);
//int32_t bswap_32(int32_t x)
	value = bswap_32(value);

	emu::core::i_instruction *instr = emu::z80::factory::get_instruction(value);
	

printf("===> address = 0x%04X, value = %08X, instr: [%lu] %s\n", address, value, instr->get_size(), instr->to_string().c_str());

	if(instr->exec()) {
		
	}

	dump();

	address += instr->get_size();
	 _special.set<uint16_t>("PC", address);

	return true;
}

void processor::dump() {
// TODO add return string
	emu::core::processor::dump();
	_registers_dump();	
	puts("------------------------------------");
}

void processor::_registers_dump() {
// TODO add return string
	const char *curr = "(current)";

	printf("    Main set");
	if(_current_registers_set == &_main) {
		printf(curr);
	}
	puts(":");

	printf("      A: %02X B: %02X C: %02X D: %02X\n", 
			_main.get<uint8_t>("A"),
			_main.get<uint8_t>("B"),
			_main.get<uint8_t>("C"),
			_main.get<uint8_t>("D")
			);
	printf("      D: %02X E: %02X H: %02X L: %02X\n", 
			_main.get<uint8_t>("D"),
			_main.get<uint8_t>("E"),
			_main.get<uint8_t>("H"),
			_main.get<uint8_t>("L")
			);

	printf("    Secondary set");
	if(_current_registers_set == &_secondary) {
		printf(curr);
	}
	puts(":");

	printf("      A': %02X B': %02X C': %02X D': %02X\n", 
			_secondary.get<uint8_t>("A"),
			_secondary.get<uint8_t>("B"),
			_secondary.get<uint8_t>("C"),
			_secondary.get<uint8_t>("D")
			);
	printf("      D': %02X E': %02X H': %02X L': %02X\n", 
			_secondary.get<uint8_t>("D"),
			_secondary.get<uint8_t>("E"),
			_secondary.get<uint8_t>("H"),
			_secondary.get<uint8_t>("L")
			);

	puts("    Special:");
	printf("      I: %02X R: %02X\n", 
			_special.get<uint8_t>("I"),
			_special.get<uint8_t>("R")
			);
	printf("      IX: %04X IY: %04X SP: %04X PC: %04X\n", 
			_special.get<uint16_t>("IX"),
			_special.get<uint16_t>("IY"),
			_special.get<uint16_t>("SP"),
			_special.get<uint16_t>("PC")
			);
}
