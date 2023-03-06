cmake_minimum_required(VERSION 3.9)
project(05-Discount)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Consume.h Discount.h)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
