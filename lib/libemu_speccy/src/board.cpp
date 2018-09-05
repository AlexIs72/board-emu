#include <speccy/board.h>

using namespace emu::speccy;
/*
Memory

http://zxpress.ru/book_articles.php?id=1659
http://dev.speccy.info/index.php?title=Устройство_памяти
http://zxpress.ru/book_articles.php?id=1659&lng=eng
http://zxpress.ru/book_articles.php?id=2179&lng=eng

*/


board::board() : emu::core::board() { 
	_create_memory_segment("ROM", 0x0000, 16384);


/*	_system_bus = new emu::core::bus();
	_mpu = new emu::z80::mpu();

	attach_central_unit(_mpu);
*/
//printf("=====> MPU: %s\n", _mpu->get_name().c_str());
}

board::~board() { 
/*	if(_system_bus) {
		delete _system_bus;
		_system_bus = NULL;
	}

	if(_mpu) {
		delete _mpu;
		_mpu = NULL;
	}
*/
}

/*
void board:: reset() {
	_mpu->reset();
}

uint8_t board::run() {
	emu::core::bus *system_bus = _get_system_bus();

	reset();

	if(system_bus == NULL) {
		return 1;
	}

//	while(1) {
	for(int i=0; i<100; i++) {
			
	}

	return 0;
}

*/