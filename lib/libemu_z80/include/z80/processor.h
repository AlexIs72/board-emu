#ifndef __EMU_Z80_PROCESSOR_CHIP_H__
#define __EMU_Z80_PROCESSOR_CHIP_H__

#include <stdint.h>

#include <string>

//#include <core/chip/central_unit.h>
//#include <core/chip/central_unit/mpu.h>
#include <core/processor.h>
#include <core/registers.h>
#include <z80/registers.h>


namespace emu {
    namespace z80 {
        class processor : public emu::core::processor {
//			private:
/*
http://www.igorkov.org/pdf/Z80-Central-Processor-Unit.pdf

Аккумулятор
A (8)
Флаги
F (8)
Аккумулятор
A´ (8)
Флаги
F´ (8)
B (8/16) C (8) B´ (8/16) C´ (8)
D (8/16) E (8) D´ (8/16) E´ (8)
H (8/16) L (8) H´ (8/16) L´ (8)
Регистры
общего
назначения
Вектор прерывания
I (8)
Регенерация памяти
R (8)
Индексный регистр IX (16)
Индексный регистр IY (16)
Указатель стека SP (16)
Счётчик команд PC (16) 

*/
			private:
				registers_set	_main;
				registers_set	_secondary;
				registers_set	_special;
				registers_set	*_current_registers_set;

//				emu::core::bus 	*_system_bus;
            public:
                processor(); // : emu::core::processor() { }
                virtual ~processor() { }

				virtual void reset();
				virtual bool next();

				virtual std::string get_name() { return std::string("Zilog Z80"); } 

//				virtual chip_type_t get_type() { return MPU_CHIP; }
        };
    };
};


#endif
