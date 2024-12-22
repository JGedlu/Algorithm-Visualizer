cmake_minimum_required(VERSION 3.16) # Updated to a commonly supported version
project(algorithmVisualizer)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files
set(SOURCE_FILES
        src/main.cpp
        src/graph.cpp
        src/dijkstra.cpp
        src/astar.cpp
        src/bfs.cpp
)

# Add header files (optional for clarity, not mandatory for compilation)
set(HEADER_FILES
        include/graph.h
        include/algorithms.h
        include/utils.h
)

# Create the executable
add_executable(algorithmVisualizer ${SOURCE_FILES} ${HEADER_FILES})