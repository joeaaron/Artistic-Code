cmake_minimum_required(VERSION 3.9)
project(01-SimpleFlyweight)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES simpleFlyWeight.cpp)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
