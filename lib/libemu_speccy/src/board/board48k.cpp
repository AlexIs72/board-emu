//#include <z80/mpu.h>

#include <speccy/board/board48k.h>

   
using namespace emu::speccy;

/*
ОЗУ распределяется примерно так:

#4000 - #5AFF - графический экран
#5B00 - #5BFF - буфер ZX Printer'а
#5C00 - #5CB5 - системные переменные бейсика
#5CB6 - #xxxx - другие сист. переменные/бейсик-программа/переменные
#xxxx - #FFFF - свободная область

*/

board48k::board48k():board() {
	_create_memory_segment("RAM", 0x4000, 49152);
//	attach_cpu()
}

board48k::~board48k() {
}

uint8_t board48k::run() {
	return 0;
}
