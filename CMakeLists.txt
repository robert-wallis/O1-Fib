cmake_minimum_required(VERSION 3.15)
project(fib)

# doesn't work with google bench and gtest, because each one requires a different standard
# set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/benchmark)

add_executable(fibbench
        fibbench.cpp
        )
target_link_libraries(fibbench benchmark)

add_executable(fib
        fib.cpp
        )
