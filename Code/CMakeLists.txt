cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(draw_all_funcs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(pbPlots STATIC pbPlots/supportLib.cpp pbPlots/pbPlots.cpp)

add_executable(draw_all_funcs DrawFunctions/draw_all_funcs.cpp pbPlots)

target_link_libraries(draw_all_funcs pbPlots)