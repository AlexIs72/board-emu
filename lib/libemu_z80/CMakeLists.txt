cmake_minimum_required(VERSION 3.0)

#project(z80)

#set (CMAKE_VERBOSE_MAKEFILE ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../libemu_core/include")

add_definitions(-Wall -Werror -Wextra -std=c++11 -ggdb -O0)

set(SRC
	src/instruction.cpp
	src/instruction/factory.cpp
#	src/instruction/primary.cpp

	src/instruction/primary/halt.cpp
	src/instruction/primary/di.cpp
	src/instruction/primary/ei.cpp
	src/instruction/primary/jr.cpp
	src/instruction/primary/rst.cpp
	src/instruction/primary/xor.cpp
	src/instruction/primary/or.cpp
	src/instruction/primary/cp.cpp
	src/instruction/primary/out.cpp
	src/instruction/primary/djnz.cpp
	src/instruction/primary/ld.cpp
	src/instruction/primary/dec.cpp
	src/instruction/primary/ex.cpp

	src/instruction/xx80xx/out.cpp

	src/instruction/xxBITxx.cpp
	src/instruction/xxBITxx/srl.cpp
	src/instruction/xxBITxx/rlc.cpp
	src/instruction/xxBITxx/rrc.cpp
	src/instruction/xxBITxx/rl.cpp
	src/instruction/xxBITxx/rr.cpp
)

#add_library(${PROJECT_NAME} SHARED ${SRC})
add_library(emu_z80 ${SRC})
#add_library(libemu_core SHARED ${SRCS})
add_library(LIBS::emu_z80 ALIAS emu_z80)
