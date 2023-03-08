cmake_minimum_required(VERSION 3.9)
project(07-HandSet)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp HandsetSoft.h HandsetBrand.h)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
