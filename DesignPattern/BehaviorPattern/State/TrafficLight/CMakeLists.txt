cmake_minimum_required(VERSION 3.9)
project(16-TrafficLight)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES state.h state.cpp concretestate.h context.h context.cpp main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
