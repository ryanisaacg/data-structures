cmake_minimum_required(VERSION 2.4.0)
project (data-structures)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB SOURCES src/*.c)

add_library(data-structures SHARED ${SOURCES})
