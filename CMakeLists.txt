cmake_minimum_required(VERSION 2.4.0)
project (data-structures)
set(CMAKE_BUILD_TYPE Debug)

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB DS-SOURCES src/*.c)

add_library(data-structures STATIC ${DS-SOURCES})
set_property(TARGET data-structures PROPERTY C_STANDARD 99)
target_link_libraries(data-structures m)

add_executable(ds-tests test.c)
target_link_libraries(ds-tests data-structures)

enable_testing()
add_test("LinkedLists" ds-tests "ll")
add_test("ArrayLists" ds-tests "al")
add_test("UnorderedLists" ds-tests "ul")
add_test("Hashmaps" ds-tests "hm")
add_test("Hashset" ds-tests "hs")
add_test("Optionals" ds-tests "op")
add_test("Tilemap" ds-tests "tl")
add_test("Slices" ds-tests "slice")
add_test("Shapes" ds-tests "shapes")
