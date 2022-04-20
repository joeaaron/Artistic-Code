cmake_minimum_required(VERSION 3.9)
project(ThreadSafetySingleton)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(ThreadSafetySingleton ${SOURCE_FILES})
