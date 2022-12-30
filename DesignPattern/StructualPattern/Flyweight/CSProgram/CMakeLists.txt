cmake_minimum_required(VERSION 3.9)
project(CSFlyweight)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Flyweight.h ConcreteFlyweight.h FlyweightFactory.h)
add_executable(CSFlyweight ${SOURCE_FILES})
