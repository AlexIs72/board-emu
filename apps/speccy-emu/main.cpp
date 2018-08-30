#include <stdio.h>
#include <stdlib.h>

#include <speccy/board/board48k.h>

#define UNUSED(x) (void)sizeof(x)


int main(int argc, char **argv) {
	emu::speccy::board48k	brd;	

	brd.run();


	UNUSED(argc);
	UNUSED(argv);

	return 0;
}

