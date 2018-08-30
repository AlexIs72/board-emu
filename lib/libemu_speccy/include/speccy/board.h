#ifndef __EMU_SPECCY_BOARD_H__
#define __EMU_SPECCY_BOARD_H__


#include <stdint.h>

#include <string>

#include <core/board.h>
//#include <core/bus.h>

//#include <z80/mpu.h>

namespace emu {
    namespace speccy {
        class board : public emu::core::board {
			private:
//				emu::core::i_bus *_system_bus;
//				emu::z80::mpu	*_mpu;
			public:

				board(); // : emu::core::board(), _system_bus(NULL)  { }
				virtual ~board(); // { }

				virtual std::string get_title() {
					return std::string("Speccy board");
				}

//				virtual inline emu::core::i_bus *get_bus() { return _system_bus; }

				virtual uint8_t run() { return 0; }
		};
	};
};


#endif
