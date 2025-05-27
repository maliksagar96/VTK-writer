cmake_minimum_required(VERSION 3.10)
project(MyVTKProject)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/vtkWriter.cpp
)

# Build type specific output name
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EXECUTABLE_NAME MyExecutable_debug)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(EXECUTABLE_NAME MyExecutable_release)
else()
    set(EXECUTABLE_NAME MyExecutable)
endif()

# Create the executable
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Find and link VTK
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
target_link_libraries(${EXECUTABLE_NAME} ${VTK_LIBRARIES})

# Optional definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${EXECUTABLE_NAME} PRIVATE DEBUG_MODE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${EXECUTABLE_NAME} PRIVATE RELEASE_MODE)
endif()
