cmake_minimum_required(VERSION 3.15)
project(ShadowSpy)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE FIGURES_FILES glutHelper/**.cpp glutHelper/**.h)
file(GLOB_RECURSE GAME_FILES gameHelper/**.cpp gameHelper/**.h)

add_executable(ShadowSpy ShadowSpy.cpp ${FIGURES_FILES} ${GAME_FILES})

target_link_libraries(ShadowSpy -lOpenGL32 -lfreeGLUT -lGLU32)