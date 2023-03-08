cmake_minimum_required(VERSION 3.9)
project(06-MilkTea)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp component.h decorator.h)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
