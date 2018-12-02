project(cpplab)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
add_executable(cpplab main.cpp)

add_executable(
    sse 
    src/core/cpu/sse.cpp
    src/core/cpu/naive.cpp
    src/core/cpu/avx2.cpp
    src/core/bmath/complex.cpp
    sse.cpp
)

add_executable(
    complex 
    src/core/bmath/complex.cpp
    complex.cpp
)

add_executable(c_time time.cpp)

install(TARGETS cpplab RUNTIME DESTINATION bin)
