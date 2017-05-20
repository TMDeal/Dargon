project(Dargon)
cmake_minimum_required(VERSION 2.8)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(RES_DIR ${SOURCE_DIR}/res)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++1y")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

set(SDL2PP_WITH_IMAGE ON CACHE BOOL "Enable SDL2_image support")
set(SDL2PP_WITH_TTF ON CACHE BOOL "Enable SDL2_ttf support")
set(SDL2PP_WITH_MIXER ON CACHE BOOL "Enable SDL2_mixer support")
add_subdirectory(third_party/libSDL2pp)

set(JSONCPP_WITH_TESTS OFF CACHE BOOL "Compile and (for jsoncpp_check) run JsonCpp test executables")
set(JSONCPP_WITH_PKGCONFIG_SUPPORT OFF CACHE BOOL "Generate and install .pc files")
add_subdirectory(third_party/jsoncpp)

include_directories(include)
include_directories(SYSTEM ${SDL2PP_INCLUDE_DIRS})
include_directories(SYSTEM ${JSONCPP_INCLUDE_DIR})

add_subdirectory(res/sprite_data)
add_subdirectory(include)
add_subdirectory(src)
