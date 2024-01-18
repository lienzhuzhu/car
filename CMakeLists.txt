cmake_minimum_required(VERSION 3.28)
project(GeneticAlgo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Specify the directories for source and header files
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Include the directories for header files
include_directories(${INCLUDE_DIR})

# Add the executable
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")
add_executable(app ${SOURCES})

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

find_library(RAYLIB_LIBRARY raylib)

# Find the required frameworks and the raylib library
find_library(COCOA_LIBRARY Cocoa)
find_library(GLUT_LIBRARY GLUT)
find_library(OPENGL_LIBRARY OpenGL)
find_library(IOKIT_LIBRARY IOKit)
find_library(COREVIDEO_LIBRARY CoreVideo)

# Link the frameworks and the raylib library to your project
target_link_libraries(app Eigen3::Eigen ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OPENGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} ${RAYLIB_LIBRARY})
