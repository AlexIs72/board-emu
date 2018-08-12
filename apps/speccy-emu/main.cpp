#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



#include <memory>
#include <iostream>
#include <iomanip>
//#include <fstream>

#include <core/memory/segment.h>
//#include <z80/memory/segment/iterator.h>
#include <z80/memory/cell.h>
//#include <emu/memory/cell.h>
#include <z80/instruction.h>
#include <z80/instruction/factory.h>



int main(int argc, char *argv[]) {
//	printf("argc = %d; argv[0] = %s\n", argc, argv[0]);
    struct stat   stat_info;

    if(argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return -1;
    }

    if(stat (argv[1], &stat_info) != 0) {
        perror("Error");
        return -1;
    }

    emu::core::memory_segment bin_seg(0x0000/*, 16384*/);
    emu::core::memory_segment_iterator<uint32_t>    it;
//	emu::core::memory_cell<uint8_t>	cell;
    emu::z80::memory_cell  cell;
//    emu::core::instruction instr;
//    emu::core::instruction_formatter  formatter;

    bin_seg.load_from_file(argv[1], 0x104);
	std::cout << "Memory block with size " << bin_seg.get_size<uint8_t>() << " loaded to address " << bin_seg.get_address() << std::endl; 		

	for(it = bin_seg.begin<uint32_t>(); it != bin_seg.end<uint32_t>(); /*++it*/) {
		cell = it.get_cell();
//		std::cout << std::hex << std::setw(4) << std::setfill('0') << cell.address()  << "    " << std::setw(2) << (int)cell.value() << std::endl;

		emu::core::i_instruction *instr = emu::z80::factory::get_instruction(cell.value());


/*		if(emu::z80::factory::is_valid_cell(cell)) {

		} else {
			cell = it.get_cell()
		}
*/

//		size_t	cell_size = emu::z80::factory::get_instruction_size(cell.value());

//      std::cout << std::hex << cell.address()  << "      " << cell.value() << std::endl;
//      	emu::z80::instruction  instr(cell);
//        emu::core::i_instruction *instr = emu::mips::factory::get_instruction(cell.value());
        std::cout << 
                    std::hex << std::internal << std::setfill('0') << std::setw(4) << cell.address()  <<
                    "    " <<
                    std::hex << std::left << std::setfill(' ') << std::setw(12) << /*cell.value()*/instr->opcode_to_string() <<
                    "    " << 
					std::dec << std::setw(1) << instr->get_size() << 
                    "    " << 
					instr->to_string() <<
                    std::endl;

		it += instr->get_size();
	}



    return 0;
}

