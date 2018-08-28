#ifndef __EMU_Z80_XX80XX_INSTRUCTION_H__
#define __EMU_Z80_XX80XX_INSTRUCTION_H__

#include <z80/instruction.h>

namespace emu {
    namespace z80 {
        class xx80xx_instruction : public instruction {
            public:
				xx80xx_instruction(uint32_t value) : instruction(value) {}
                virtual ~xx80xx_instruction() {}
		
				virtual inline size_t  get_size() const { return 2; }
		
			protected:
				virtual std::string _get_type() { return std::string("xx80xx"); }
        };
    };
};



#endif
