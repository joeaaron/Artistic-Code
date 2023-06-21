cmake_minimum_required(VERSION 3.9)
project(18-FileSystem)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES leaf.h component.h composite.h fileFactory.h main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
