cmake_minimum_required(VERSION 2.8)

project(libogg)

add_library(libogg STATIC src/bitwise.c src/framing.c)
include_directories(include)
set_target_properties(libogg PROPERTIES PREFIX "")

