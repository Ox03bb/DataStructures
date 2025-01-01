cmake_minimum_required(VERSION 3.10)
project(DataStructures)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(src/include)

# Source files
set(SOURCES
    src/lib/crud.cpp
    src/lib/func.cpp
    src/lib/node.cpp
    src/main.cpp
)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Add executable
add_executable(DataStructures ${SOURCES})