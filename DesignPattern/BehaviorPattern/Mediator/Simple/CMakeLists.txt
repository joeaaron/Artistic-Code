cmake_minimum_required(VERSION 3.9)
project(15-Mediator)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES mediator.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
