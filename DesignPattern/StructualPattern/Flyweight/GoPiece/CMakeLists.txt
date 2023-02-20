cmake_minimum_required(VERSION 3.9)
project(01-GoPiece)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES GoPiece.cpp GoPiece.h)
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})
