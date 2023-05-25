cmake_minimum_required(VERSION 3.9)
project(15-LineEdit)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp widget.h mediator.h concreteMediator.h concreteColleague.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
