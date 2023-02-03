cmake_minimum_required(VERSION 3.9)
project(04-ObeyISP)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES obeyISP.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
