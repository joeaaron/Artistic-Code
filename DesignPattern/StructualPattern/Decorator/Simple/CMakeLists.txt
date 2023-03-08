cmake_minimum_required(VERSION 3.9)
project(06-Decorator)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES decorator.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
