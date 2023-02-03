cmake_minimum_required(VERSION 3.9)
project(03-ObeyLSP)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES obeyLSP.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
