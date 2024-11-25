# Sandbox directory

project(Sandbox)

# Create an executable
add_executable(Sandbox
    source/SandboxApplication.cpp
)

# Include directories
target_include_directories(Sandbox PRIVATE
    ../Shmeckle/vendor/spdlog/include
    ../Shmeckle/source
)

# Link the Shmeckle library
target_link_libraries(Sandbox Shmeckle)

# Set target-specific output directories
set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Sandbox
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Sandbox
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin-int/Sandbox
)