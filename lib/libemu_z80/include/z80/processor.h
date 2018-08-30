#ifndef __EMU_Z80_PROCESSOR_CHIP_H__
#define __EMU_Z80_PROCESSOR_CHIP_H__

#include <stdint.h>

#include <string>

//#include <core/chip/central_unit.h>
#include <core/chip/central_unit/mpu.h>

namespace emu {
    namespace z80 {
        class processor : public emu::core::processor {
            public:
                processor() : emu::core::processor() { }
                virtual ~processor() { }

				virtual std::string get_name() { return std::string("Zilog Z80"); } 

//				virtual chip_type_t get_type() { return MPU_CHIP; }
        };
    };
};


#endif
