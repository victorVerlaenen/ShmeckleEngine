# Root directory

cmake_minimum_required(VERSION 3.29)
project(ShmeckleEngine VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin-int)

# Define platform-specific macros
if(WIN32)
    add_compile_definitions(SMECKLE_PLATFORM_WINDOWS)

    set(CMAKE_SYSTEM_VERSION "10.0")
    message(STATUS "Using Windows SDK version: ${CMAKE_SYSTEM_VERSION}")
endif()

# Set Unicode support
add_compile_options(/utf-8)

# Add subdirectories for Hazel and Sandbox projects
add_subdirectory(Shmeckle)
add_subdirectory(Sandbox)
