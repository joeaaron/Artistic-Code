cmake_minimum_required(VERSION 3.9)
project(12-Fund)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp fund.h shares.h)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
