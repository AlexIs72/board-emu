#include <stdio.h>
#include <stdlib.h>

#include <speccy/board/board48k.h>

#define UNUSED(x) (void)sizeof(x)


int main(int argc, char **argv) {
	emu::speccy::board48k	brd;	

	brd.load_memory_segment_from_file("/home/alexey/projects/board-emu/dumps/zx_spectrum/tests/TEST48.BIN", "ROM");

	brd.run();


	UNUSED(argc);
	UNUSED(argv);

	return 0;
}

