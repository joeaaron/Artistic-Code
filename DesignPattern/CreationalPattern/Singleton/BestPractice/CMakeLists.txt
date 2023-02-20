cmake_minimum_required(VERSION 3.9)
project(02-BestPracticeSingleton)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES bestPracticeSingleton.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
