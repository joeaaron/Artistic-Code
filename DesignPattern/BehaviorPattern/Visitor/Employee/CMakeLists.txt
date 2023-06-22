cmake_minimum_required(VERSION 3.9)
project(22-Employee)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp visitor.h element.h concreteElement.h concreteVisitor.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
