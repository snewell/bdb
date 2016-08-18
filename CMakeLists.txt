cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.0)

project("bdb"
        LANGUAGES CXX
        VERSION 0.1.0)

option(BUILD_TESTS "Build optional tests" ON)

enable_testing()

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)

if(BUILD_TESTS)
    find_library(GTEST gtest)
    find_library(GTEST_MAIN gtest_main)
    message(STATUS "gtest location: ${GTEST}")
    message(STATUS "gtest_main location: ${GTEST_MAIN}")
    if(GTEST AND GTEST_MAIN)
        set(BUILD_TESTS ON)
    else()
        message(WARNING "Could not find gtest libraries; unit tests disabled")
    endif()
endif()

if(BUILD_TESTS)
    function(create_test name)
        add_executable(${name} ${ARGN})
        target_link_libraries(${name}
                                ${GTEST}
                                ${GTEST_MAIN}
                             )
        add_test(${name} ${name})
    endfunction()
else()
    function(create_test name)
        #do nothing
    endfunction()
endif()

create_test(bdb_test bdb_test.cpp)
create_test(bdp_test bdp_test.cpp)

install(FILES
            bdb.h
            bdp.h
        DESTINATION include)
