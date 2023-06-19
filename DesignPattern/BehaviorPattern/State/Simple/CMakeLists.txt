cmake_minimum_required(VERSION 3.9)
project(16-State)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES state.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
