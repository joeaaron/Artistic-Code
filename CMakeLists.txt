set_property(GLOBAL PROPERTY USE_FOLDERS ON)
cmake_minimum_required (VERSION 3.10) 
project (ArtisticCode)

set(VERSION 1.0.0)
configure_file(version.h.in "${PROJECT_SOURCE_DIR}/version.h")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/")
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/lib )

link_directories(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories("${CMAKE_SOURCE_DIR}/include/")

option(BUILD_PATTERN	"Build Pattern" 	ON)

if(BUILD_PATTERN)
	add_subdirectory(DesignPattern)
endif(BUILD_PATTERN)

