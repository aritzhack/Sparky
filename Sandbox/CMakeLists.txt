cmake_minimum_required(VERSION 2.8)

project(Sandbox)

add_executable(Sandbox   src/Sandbox.cpp src/Test3D.cpp)
include_directories(src)
include_directories(../Sparky-core/src)

add_definitions(-DSP_CORE_DLL -DFREEIMAGE_LIB -DOPJ_STATIC -DSP_DEBUG -DGLEW_STATIC -DSP_PLATFORM_UNIX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -w")

target_link_libraries(Sandbox Sparky-core glfw FreeImage FreeType gorilla-audio)

target_compile_features(Sandbox PRIVATE cxx_nullptr)
