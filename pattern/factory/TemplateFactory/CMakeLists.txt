cmake_minimum_required(VERSION 3.9)
project(TemplateFactory)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Shoes.h ShoesFactory.h)
add_executable(TemplateFactory ${SOURCE_FILES})
