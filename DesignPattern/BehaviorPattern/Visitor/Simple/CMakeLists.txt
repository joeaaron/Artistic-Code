cmake_minimum_required(VERSION 3.9)
project(22-Visitor)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES visitor.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
