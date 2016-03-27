cmake_minimum_required(VERSION 2.6)
project(Dargon)

set(SOURCE_DIR ${Dargon_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SOURCE_DIR}/cmake")
set(BIN_DIR ${SOURCE_DIR}/bin)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
SET(CMAKE_INSTALL_RPATH "${SOURCE_DIR}/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

configure_file(${SOURCE_DIR}/include/templates_in/projectPaths.h.in ${SOURCE_DIR}/include/templates_out/projectPaths.h)
include_directories(include)
link_directories(${SOURCE_DIR}/lib)
set(TCOD_LIBRARY tcod tcodxx)
set(TCOD_LIBRARY_DEBUG tcod_debug tcodxx_debug)

file(GLOB SOURCES ./src/*.cpp)

add_executable(Dargon ${SOURCES})
target_link_libraries(Dargon debug ${TCOD_LIBRARY_DEBUG})
target_link_libraries(Dargon optimized ${TCOD_LIBRARY})
install(TARGETS Dargon RUNTIME DESTINATION ${BIN_DIR})
