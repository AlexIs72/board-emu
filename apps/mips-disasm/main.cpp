#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <memory>
#include <iostream>
//#include <fstream>

#include <memory/segment.h>
#include <memory/cell.h>


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

    emu::core::memory_segment bin_seg(0x80000000);
    emu::core::memory_segment::dword_iterator	it;
	emu::core::memory_cell<uint32_t>	cell;	
//    emu::core::instruction instr;
//    emu::core::instruction_formatter	formatter;

    bin_seg.load_from_file(argv[1]);

/*	bin_seg.set(0x80000000, 1);
	bin_seg.set(0x80000004, 2);
	bin_seg.set(0x80000008, 3);
	bin_seg.set(0x8000000C, 4);*/
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
		std::cout << std::hex << cell.address()  << "    " << cell.value() << std::endl;

//		cell = *it;	
//		std::cout << std::hex << cell.address()  << std::dec << "    " << cell.value() << std::endl;
//fprintf(stderr, "0x%X    %d\n",  cell.address()cell.value() << std::endl;
//	uint32_t addr = it.first;
//	instr.load(it);
//	std::cout << formatter.format(instr) << std::endl;
    }
     


    return 0;
}