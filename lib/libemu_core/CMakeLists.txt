cmake_minimum_required(VERSION 3.0)

project(emu_core)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/../include")

#add_definitions(-Wall -Werror -Wextra -std=c++11 -ggdb)
add_definitions(-std=c++11 -ggdb)


set(SRC
#	core
#	src/core/instruction_processor.cpp
	src/board.cpp
	src/bus.cpp
	src/memory/segment.cpp
#	src/instruction.cpp
#	src/core/memory_block_iterator.cpp
#	factory
#    src/factory/board_factory.cpp
#    src/factory/chip_factory.cpp
#	hw
#	src/hw/

#	instruction_processor/base_instruction_processor.cpp
)

#add_library(${PROJECT_NAME} SHARED ${SRC})
add_library(${PROJECT_NAME} STATIC ${SRC})
#add_library(libemu_core SHARED ${SRCS})
add_library(LIBS::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
