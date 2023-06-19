cmake_minimum_required(VERSION 3.9)
project(17-Memento)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES memento.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
