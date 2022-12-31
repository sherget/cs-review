cmake_minimum_required(VERSION 3.13)  # CMake version check
project(datastructures)               # Create project "DSA"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cc)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(datastructures ${SOURCE_FILES})
