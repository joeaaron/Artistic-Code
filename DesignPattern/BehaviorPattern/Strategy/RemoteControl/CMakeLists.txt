cmake_minimum_required(VERSION 3.9)
project(05-RemoteControl)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES remoteControl.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
