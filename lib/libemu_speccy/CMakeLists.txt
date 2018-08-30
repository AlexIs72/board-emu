cmake_minimum_required(VERSION 3.0)

#project(z80)

#set (CMAKE_VERBOSE_MAKEFILE ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../libemu_core/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../libemu_z80/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../libemu_speccy/include")

add_definitions(-Wall -Werror -Wextra -std=c++11 -ggdb -O0)

set(SRC
	src/board.cpp
	src/board/board48k.cpp
	src/board/board128k.cpp
)

#add_library(${PROJECT_NAME} SHARED ${SRC})
add_library(emu_speccy ${SRC})
#add_library(libemu_core SHARED ${SRCS})
add_library(LIBS::emu_speccy ALIAS emu_speccy)
