cmake_minimum_required(VERSION 3.9)
project(07-Bridge)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES bridge.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
