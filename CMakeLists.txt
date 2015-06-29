cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project('gitterlite')

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}")
find_package(Curl REQUIRED)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable( GitterLite src/gitterlite.c)
target_link_libraries(GitterLite ${CURSES_LIBRARIES})
