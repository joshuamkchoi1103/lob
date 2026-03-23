cmake_minimum_required(VERSION 3.10)

# Project Name and Version
project(lob_engine VERSION 2.0)

# Specify the C++ standard (C++17 is a solid baseline for modern features)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aggressive compiler optimizations for HFT
# -O3: Maximize speed
# -march=native: Optimize for the specific CPU architecture of the host machine
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -Wall -Wextra -Werror")

# Tell CMake where to find the header files
include_directories(include)

# Define the source files explicitly 
# (Better practice than GLOBing, as it tracks changes reliably)
set(SOURCES
    src/PriceLevel.cpp
    src/OrderPool.cpp
    src/LimitOrderBook.cpp
    src/main.cpp
)

# Create the executable from the source files
add_executable(lob_engine ${SOURCES})