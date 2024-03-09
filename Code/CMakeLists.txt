cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(draw_all_funcs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#pbPlots
add_library(pbPlots SHARED pbPlots/supportLib.cpp pbPlots/pbPlots.cpp)

#Utilities
add_library(Utilities SHARED Utilities/basic_math.cpp Utilities/sine_helper.cpp)

#Sine_functions
add_library(sine_funcs SHARED 
Sine_functions/cordic.cpp 
Sine_functions/cordic_fixed_point.cpp 
Sine_functions/table_sine.cpp 
Sine_functions/taylor_series_sine.cpp 
)

add_library(abs_error SHARED test_accuracy/abs_error.cpp)

add_executable(draw_all_funcs DrawFunctions/draw_all_funcs.cpp)
add_executable(test_accuracy test_accuracy/test_accuracy.cpp)
#add_executable(taylor_accuracy DrawFunctions/taylor_accuracy.cpp)

target_link_libraries(draw_all_funcs pbPlots Utilities sine_funcs)
target_link_libraries(test_accuracy abs_error Utilities sine_funcs)
#target_link_libraries(taylor_accuracy pbPlots Utilities abs_error sine_funcs)