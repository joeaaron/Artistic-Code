cmake_minimum_required(VERSION 3.9)
project(MemoryPool)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp StackAlloc.h MemoryPool.h MemoryPool.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
