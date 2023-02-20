cmake_minimum_required(VERSION 3.9)
project(02-TemplateSingleton)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CSingleton.h)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
