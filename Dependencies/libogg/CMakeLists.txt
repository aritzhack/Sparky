cmake_minimum_required(VERSION 2.8)

project(libogg)

add_library(libogg STATIC src/bitwise.c src/framing.c)
include_directories(include)
set_target_properties(libogg PROPERTIES PREFIX "")
set_target_properties(libogg PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BASE_DIR}/out)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
