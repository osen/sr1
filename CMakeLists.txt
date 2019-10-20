cmake_minimum_required(VERSION 2.6)
project(SR1)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pedantic -Wall")

add_definitions(-DSTD_SR1_DEBUG)

include_directories(
  include
)

enable_testing()
add_executable(harness src/harness/main.cpp)

# Must Fail #########################################

add_executable(dangling_ref src/tests/dangling_ref.cpp)
add_test(dangling_ref harness ./dangling_ref)

add_executable(dangling_ref_vector src/tests/dangling_ref_vector.cpp)
add_test(dangling_ref_vector harness ./dangling_ref_vector)

add_executable(dangling_char_ref src/tests/dangling_char_ref.cpp)
add_test(dangling_char_ref harness ./dangling_char_ref)

add_executable(dangling_iterator src/tests/dangling_iterator.cpp)
add_test(dangling_iterator harness ./dangling_iterator)

add_executable(dangling_iterator_erase src/tests/dangling_iterator_erase.cpp)
add_test(dangling_iterator_erase harness ./dangling_iterator_erase)

add_executable(invalid_iterator_erase src/tests/invalid_iterator_erase.cpp)
add_test(invalid_iterator_erase harness ./invalid_iterator_erase)

add_executable(dangling_this src/tests/dangling_this.cpp)
add_test(dangling_this harness ./dangling_this)

add_executable(dangling_this_vector src/tests/dangling_this_vector.cpp)
add_test(dangling_this_vector harness ./dangling_this_vector)

add_executable(vector_oob src/tests/vector_oob.cpp)
add_test(vector_oob harness ./vector_oob)

add_executable(vector_resize src/tests/vector_resize.cpp)
add_test(vector_resize harness ./vector_resize)

add_executable(vector_lock src/tests/vector_lock.cpp)
add_test(vector_lock harness ./vector_lock)

add_executable(vector_erase_end src/tests/vector_erase_end.cpp)
add_test(vector_erase_end harness ./vector_erase_end)

add_executable(dangling_ref_vector_raw src/tests/dangling_ref_vector_raw.cpp)
add_test(dangling_ref_vector_raw harness ./dangling_ref_vector_raw)

add_executable(dangling_observer src/tests/dangling_observer.cpp)
add_test(dangling_observer harness ./dangling_observer)

add_executable(expired_observer src/tests/expired_observer.cpp)
add_test(expired_observer harness ./expired_observer)

# Must succeed #####################################

add_executable(shared_copy src/tests/shared_copy.cpp)
add_test(shared_copy shared_copy)

add_executable(shared_ptr src/tests/shared_ptr.cpp)
add_test(shared_ptr shared_ptr)

add_executable(weak_ptr src/tests/weak_ptr.cpp)
add_test(weak_ptr weak_ptr)

add_executable(iterator_erase src/tests/iterator_erase.cpp)
add_test(iterator_erase iterator_erase)

add_executable(observer_simple src/tests/observer_simple.cpp)
add_test(observer_simple ./observer_simple)

add_executable(vector_iterate src/tests/vector_iterate.cpp)
add_test(vector_iterate ./vector_iterate)

add_executable(observer_casting src/tests/observer_casting.cpp)
add_test(observer_casting ./observer_casting)
