project(Lists
    VERSION 1.0.0
    LANGUAGES CXX)

find_package(Catch2 3 REQUIRED)

# add executables
add_executable(${PROJECT_NAME}  TestLists.cpp)

# link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain LISTS_LIB)

# include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${LISTS_HEADER_DIR})

add_executable(TestLinkList TestLinkList.cpp)
target_link_libraries(TestLinkList PRIVATE Catch2::Catch2WithMain LISTS_LIB)
target_include_directories(TestLinkList PRIVATE ${LISTS_HEADER_DIR})