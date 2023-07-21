cmake_minimum_required(VERSION 3.9)
project(ProducerConsumer)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BlockingQueue.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
