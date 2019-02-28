cmake_minimum_required(VERSION 2.6)
project(SR1)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -pedantic -Wall")

add_definitions(-DSTD_SR1_DEBUG)

include_directories(
  include
)

enable_testing()
add_executable(harness src/harness/main.cpp)

add_executable(dangling_ref src/tests/dangling_ref.cpp)
add_test(dangling_ref harness ./dangling_ref)

add_executable(dangling_ref_vector src/tests/dangling_ref_vector.cpp)
add_test(dangling_ref_vector harness ./dangling_ref_vector)

add_executable(shared_copy src/tests/shared_copy.cpp)
add_test(shared_copy shared_copy)

add_executable(dangling_iterator src/tests/dangling_iterator.cpp)
add_test(dangling_iterator harness ./dangling_iterator)

add_executable(dangling_this src/tests/dangling_this.cpp)
add_test(dangling_this harness ./dangling_this)

add_executable(dangling_this_vector src/tests/dangling_this_vector.cpp)
add_test(dangling_this_vector harness ./dangling_this_vector)
