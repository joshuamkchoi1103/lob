cmake_minimum_required(VERSION 3.10)

# Project Name and Version
project(LimitOrderBook VERSION 1.0)

# We are using modern C++20 for the best performance features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable maximum compiler warnings (Crucial for writing safe quant code)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Set the highest optimization level for our Release builds
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")

# Tell CMake where to find our header files
include_directories(include)

# Create the main executable
add_executable(lob_engine src/main.cpp)