cmake_minimum_required(VERSION 3.9)
project(14-Adapter)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES adapter.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
