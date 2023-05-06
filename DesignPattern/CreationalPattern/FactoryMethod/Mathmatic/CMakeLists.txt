cmake_minimum_required(VERSION 3.9)
project(08-Mathmatic)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Mathmatic.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
