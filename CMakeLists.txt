cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.0)

project("bdb"
        LANGUAGES CXX
        VERSION 0.1.0)

enable_testing()

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)

add_executable(bdb_test bdb_test.cpp)
target_link_libraries(bdb_test gtest gtest_main)
add_test(bdb_test bdb_test)
