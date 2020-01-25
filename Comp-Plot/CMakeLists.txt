cmake_minimum_required(VERSION 3.15)
project(CompPlot C)

set(CMAKE_C_STANDARD 11)

add_library(PlotLib abb.h abb.c list.h list.c)

add_executable(CompPlot main.c)

target_link_libraries(CompPlot PlotLib)