cmake_minimum_required(VERSION 3.0)

project(mips-disasm)

include_directories("${PROJECT_SOURCE_DIR}/../../lib/libemu_core/include" )
include_directories("${PROJECT_SOURCE_DIR}/../../lib/libemu_mips/include" )

add_definitions(-O0 -ggdb -Wall -Werror -Wextra -std=c++11)

#find_library(LIBEMU_CORE emu_core
#    PATHS
#    ${PROJECT_SOURCE_DIR}/../../build/lib/libemu_core
#)


set(SRC
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
#add_library(emu_core STATIC IMPORTED)

add_library(emu_core STATIC IMPORTED)
#set_property(TARGET netutil PROPERTY
#             IMPORTED_LOCATION Binary/game_client/libnetutil.a)
set_property(TARGET emu_core 
    PROPERTY 
    IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../build/lib/libemu_core/libemu_core.a)

add_library(emu_mips STATIC IMPORTED)
#set_property(TARGET netutil PROPERTY
#             IMPORTED_LOCATION Binary/game_client/libnetutil.a)
set_property(TARGET emu_mips
    PROPERTY 
    IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../build/lib/libemu_mips/libemu_mips.a)


target_link_libraries(${PROJECT_NAME}
	emu_mips
	emu_core
)

