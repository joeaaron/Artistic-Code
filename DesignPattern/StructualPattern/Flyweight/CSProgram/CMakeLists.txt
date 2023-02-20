cmake_minimum_required(VERSION 3.9)
project(01-CSFlyweight)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES csFlyWeight.cpp Flyweight.h ConcreteFlyweight.h FlyweightFactory.h)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
