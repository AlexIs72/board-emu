#include <stdio.h>

#include <core/processor.h>


using namespace emu::core;

void processor::dump() {
    puts("------------------------------------");
    printf("    Processor: %s \n", get_name().c_str());

}