cmake_minimum_required(VERSION 3.9)
project(21-Undo)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp command.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
