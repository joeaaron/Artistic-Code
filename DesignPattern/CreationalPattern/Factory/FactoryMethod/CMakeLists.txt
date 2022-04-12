cmake_minimum_required(VERSION 3.9)
project(FactoryMethod)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Shoes.h ShoesFactory.h)
add_executable(FactoryMethod ${SOURCE_FILES})
