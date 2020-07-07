project(cpplab)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Set c++ c11 version
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
#add_executable(c_time time.cpp)

#install(TARGETS cpplab RUNTIME DESTINATION bin)
