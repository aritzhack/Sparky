cmake_minimum_required(VERSION 2.8)

project(gorilla-audio)

add_library(gorilla-audio SHARED
						src/common/gc_common.c
						src/common/gc_thread.c
						src/devices/ga_openal.c
						src/ga.c
						src/gau.c
						src/ga_stream.c)

include_directories(src ../OpenAL/include)

set_target_properties(gorilla-audio PROPERTIES PREFIX "")

