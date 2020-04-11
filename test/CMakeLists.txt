cmake_minimum_required(VERSION 3.0)
project(BINTREE_VIEW_TEST)

include_directories(../inlcude)

set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_DIRECTORY lib)

add_executable(bintree_view test.cpp)
target_link_libraries(bintree_view view)