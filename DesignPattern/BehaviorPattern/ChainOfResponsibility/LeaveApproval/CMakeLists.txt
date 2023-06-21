cmake_minimum_required(VERSION 3.9)
project(19-LeaveApproval)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES leader.h main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
