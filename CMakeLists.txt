cmake_minimum_required(VERSION 3.17)
project(file_copy_compare C)

set(CMAKE_C_STANDARD 11)

add_executable(fileCopy fileCopy.c io.c io.h)
add_executable(fileCompare fileCompare.c io.c io.h)