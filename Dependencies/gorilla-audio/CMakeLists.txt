cmake_minimum_required(VERSION 2.8)

project(gorilla-audio)

add_library(gorilla-audio SHARED
						src/common/gc_common.c
						src/common/gc_thread.c
						src/devices/ga_openal.c
						src/ga.c
						src/gau.c
						src/ga_stream.c)

include_directories(src)
include_directories(../OpenAL/include)
include_directories(../libvorbis/include)
include_directories(../libogg/include)

set_target_properties(gorilla-audio PROPERTIES PREFIX "")
set_target_properties(gorilla-audio PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${BASE_DIR}/out)

find_package(Threads)
target_link_libraries(gorilla-audio "${CMAKE_CURRENT_SOURCE_DIR}/../OpenAL/libs/linux/64/libopenal.so")
target_link_libraries(gorilla-audio libvorbis)
target_link_libraries(gorilla-audio ${CMAKE_THREAD_LIB_INIT})
