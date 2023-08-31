cmake_minimum_required(VERSION 3.15)

project(DataStructures
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "prictice of data structures"
    )


# Options
option(BUILD_TESTING "Build tests" ON)

# Basic paths
set(DATA_STRUCTURES_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_DIR ${DATA_STRUCTURES_ROOT}/src)
set(SOURCE_DIR_LISTS ${SOURCE_DIR}/lists)
set(TEST_DIR ${DATA_STRUCTURES_ROOT}/tests)

include(${DATA_STRUCTURES_ROOT}/cmake/lists.cmake)

add_subdirectory(src)

# Testing
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()





