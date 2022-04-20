cmake_minimum_required(VERSION 3.9)
project(TemplateSingleton)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CSingleton.h)
add_executable(TemplateSingleton ${SOURCE_FILES})
