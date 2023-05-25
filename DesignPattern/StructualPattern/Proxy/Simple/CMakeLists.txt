cmake_minimum_required(VERSION 3.9)
project(13-Proxy)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES proxy.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
