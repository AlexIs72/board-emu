#include <speccy/board/board128k.h>

using namespace emu::speccy;

/*
#4000 - #7FFF - 16 килобайт ОЗУ, страница №5
#8000 - #BFFF - 16 килобайт ОЗУ, страница №2
#C000 - #FFFF - 16 килобайт ОЗУ, любая страница 0..7
Переключение страниц в области #C000 - #FFFF производится через порт #7FFD. ПЗУ так же переключаемое: 16 КБ ПЗУ стандартного бейсика 48К либо 16 КБ расширенного ПЗУ бейсика 128К.
*/

board128k::board128k():board() {
    _create_memory_segment("RAM page 5", 0x4000, 16384);
    _create_memory_segment("RAM page 2", 0x8000, 16384);
    _create_memory_segment("RAM page X", 0xC000, 16384);
//  attach_cpu()
}

board128k::~board128k() {
}

uint8_t board128k::run() {
    return 0;
}
