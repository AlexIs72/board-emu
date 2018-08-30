#ifndef __EMU_SPECCY_BOARD128K_H__
#define __EMU_SPECCY_BOARD128K_H__


#include <stdint.h>

#include <string>

#include <speccy/board.h>

namespace emu {
    namespace speccy {
        class board128k : public board {
            public:
                board128k();
                virtual ~board128k();

                virtual uint8_t run();
            /*
                virtual std::string get_title() {
                    return std::string("Speccy 128K board");
                }

*/
        };
    };
};


#endif
