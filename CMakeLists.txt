cmake_minimum_required(VERSION 2.6)
project(Dargon)

set(SOURCE_DIR ${Dargon_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SOURCE_DIR}/cmake")
set(BIN_DIR ${SOURCE_DIR}/bin)

SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
SET(CMAKE_INSTALL_RPATH "${SOURCE_DIR}/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

configure_file(${SOURCE_DIR}/include/templates_in/projectPaths.h.in ${SOURCE_DIR}/include/templates_out/projectPaths.h)
include_directories(include)
link_directories(${SOURCE_DIR}/lib)
set(TCOD_LIBRARY tcod tcodxx)

file(GLOB SOURCES ./src/*.cpp)

add_executable(Dargon ${SOURCES})
target_link_libraries(Dargon ${TCOD_LIBRARY})
install(TARGETS Dargon RUNTIME DESTINATION ${BIN_DIR})
