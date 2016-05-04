cmake_minimum_required(VERSION 2.8)

set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared GLFW")
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Base output directory for all projects")

add_subdirectory(Dependencies)
add_subdirectory(Sparky-core)
add_subdirectory(Sandbox)
