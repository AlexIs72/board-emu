#ifndef __EMU_SPECCY_BOARD48K_H__
#define __EMU_SPECCY_BOARD48K_H__


#include <stdint.h>

#include <string>

#include <speccy/board.h>

namespace emu {
    namespace speccy {
        class board48k : public board {
            public:
                board48k(); /* : board() { }*/
                virtual ~board48k(); /* { }*/
            
			    virtual std::string get_title() {
                    return std::string("Speccy 48K board");
                }

				virtual uint8_t run(); // { return 0; }

        };
    };
};


#endif
