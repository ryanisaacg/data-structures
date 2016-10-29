cmake_minimum_required(VERSION 2.4.0)
project (data-structures)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB DS-SOURCES src/*.c)

add_library(data-structures SHARED ${DS-SOURCES})

add_executable(ds-tests test.c)
target_link_libraries(ds-tests data-structures)

enable_testing()
add_test("LinkedLists" ds-tests "ll")
add_test("ArrayLists" ds-tests "al")
add_test("UnorderedLists" ds-tests "ul")
add_test("Hashmaps" ds-tests "hm")
add_test("Optionals" ds-tests "op")
add_test("Tilemap" ds-tests "tl")
add_test("Slices" ds-tests "slice")
add_test("Shapes" ds-tests "shapes")
