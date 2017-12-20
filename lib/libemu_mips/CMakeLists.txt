cmake_minimum_required(VERSION 3.0)

#project(mips)

#set (CMAKE_VERBOSE_MAKEFILE ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../libemu_core/include")

add_definitions(-Wall -Werror -Wextra -std=c++11 -ggdb -O0)

set(SRC
#	src/factory.cpp
#	src/instruction_processor.cpp
	src/instruction.cpp
	src/instruction/factory.cpp
	src/instruction/cop.cpp  
	src/instruction/factory.cpp  
	src/instruction/immediate.cpp  
	src/instruction/jump.cpp  
	src/instruction/register.cpp  
	src/instruction/simple.cpp

	src/instruction/immediate/lui.cpp
	src/instruction/immediate/addiu.cpp
)

#add_library(${PROJECT_NAME} SHARED ${SRC})
add_library(emu_mips ${SRC})
#add_library(libemu_core SHARED ${SRCS})
add_library(LIBS::emu_mips ALIAS emu_mips)
