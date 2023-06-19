cmake_minimum_required(VERSION 3.9)
project(17-NewMemento)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp originator.h memento.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
