cmake_minimum_required(VERSION 2.8)

project(libvorbis)

add_library(libvorbis STATIC
							lib/analysis.c
							lib/barkmel.c
							lib/bitrate.c
							lib/block.c
							lib/codebook.c
							lib/envelope.c
							lib/floor0.c
							lib/floor1.c
							lib/info.c
							lib/lookup.c
							lib/lpc.c
							lib/lsp.c
							lib/mapping0.c
							lib/mdct.c
							lib/psy.c
							lib/registry.c
							lib/res0.c
							lib/sharedbook.c
							lib/smallft.c
							lib/synthesis.c
							lib/tone.c
							lib/vorbisenc.c
							lib/vorbisfile.c
							lib/window.c)

include_directories(include ../libogg/include lib)
target_link_libraries(libvorbis libogg)

set_target_properties(libvorbis PROPERTIES PREFIX "")
set_target_properties(libvorbis PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BASE_DIR}/out)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
