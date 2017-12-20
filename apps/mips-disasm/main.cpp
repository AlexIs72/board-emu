#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
// https://stackoverflow.com/questions/105252/how-do-i-convert-between-big-endian-and-little-endian-values-in-c
#include <endian.h>

#include <memory>
#include <iostream>
#include <iomanip>
//#include <fstream>

#include <core/memory/segment.h>
#include <mips/memory/cell.h>
#include <mips/instruction.h>
#include <mips/instruction/factory.h>


int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    struct stat   stat_info;

    if(argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return -1;
    }

    if(stat (argv[1], &stat_info) != 0) {
        perror("Error");
        return -1;
    }

    emu::core::memory_segment bin_seg(0x80000000, 16);
    emu::core::memory_segment_iterator<uint32_t>	it;
	emu::mips::memory_cell	cell;	
//    emu::core::instruction instr;
//    emu::core::instruction_formatter	formatter;

    bin_seg.load_from_file(argv[1]);
/*
	bin_seg.set(0x80000000, 1);
	bin_seg.set(0x80000004, 2);
	bin_seg.set(0x80000008, 3);
	bin_seg.set(0x8000000C, 4);
*/
//	bin_seg.set(0x80000010, 5);
/*

	cell = bin_seg.get<uint32_t>(0x80000000);
		std::cout << std::hex << cell.address()  << "    " << cell.value() << std::endl;
	cell = bin_seg.get<uint32_t>(0x80000004);
		std::cout << std::hex << cell.address()  << "    " << cell.value() << std::endl;
	cell = bin_seg.get<uint32_t>(0x80000008);
		std::cout << std::hex << cell.address()  << "    " << cell.value() << std::endl;
	cell = bin_seg.get<uint32_t>(0x8000000C);
		std::cout << std::hex << cell.address()  << "    " << cell.value() << std::endl;

*/
    for(it = bin_seg.begin<uint32_t>(); it != bin_seg.end<uint32_t>(); ++it) {
		cell = it.get_cell();
//		std::cout << std::hex << cell.address()  << "    " << htobe32(cell.value()) << std::endl;
//		std::cout << std::hex << cell.address()  << "      " << cell.value() << std::endl;
//		emu::mips::instruction	instr(cell);
		emu::core::i_instruction *instr = emu::mips::factory::get_instruction(cell);
		std::cout << 
					std::hex << std::setfill('0') << std::setw(8) << cell.address()  << 
					"    " << 
					std::hex << std::setfill('0') << std::setw(8) << cell.value() << 
					"    " << instr->to_string() << 
					std::endl;

//		cell.value(0x01020304);
//		std::cout << std::hex << cell.address()  << "  ->  " << cell.value() << std::endl;

//		cell = *it;	
//		std::cout << std::hex << cell.address()  << std::dec << "    " << cell.value() << std::endl;
//fprintf(stderr, "0x%X    %d\n",  cell.address()cell.value() << std::endl;
//	uint32_t addr = it.first;
//	instr.load(it);
//	std::cout << formatter.format(instr) << std::endl;
    }
     


    return 0;
}