cmake_minimum_required(VERSION 3.14)
project(IntVector)

set(CMAKE_CXX_STANDARD 17)

add_executable(run_tests
    int_vector_test.cpp
    int_vector.cpp
    catch_amalgamated.cpp
)
