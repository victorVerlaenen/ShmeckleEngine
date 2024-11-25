# Shmeckle directory

project(Shmeckle)

# Create a shared library
add_library(Shmeckle SHARED
    source/Shmeckle.h
    source/Shmeckle/Core.h
    source/Shmeckle/EntryPoint.h
    source/Shmeckle/Application.h
    source/Shmeckle/Application.cpp
    source/Shmeckle/Logger.h
    source/Shmeckle/Logger.cpp
)

# Include directories
target_include_directories(Shmeckle PRIVATE
    vendor/spdlog/include
    source # This is so that you can just include the Shmeckle.h header easily
)

# Preprocessor definitions
target_compile_definitions(Shmeckle PRIVATE
    SMECKLE_BUILD_DLL
)

# Preprocessor definitions
target_compile_definitions(Shmeckle
    PUBLIC
        $<$<CONFIG:Debug>:SMECKLE_DEBUG>
        $<$<CONFIG:Release>:SMECKLE_RELEASE>
        $<$<CONFIG:Dist>:SMECKLE_DIST>
)

# Configuration-specific compile options
target_compile_options(Shmeckle
    PUBLIC
        $<$<CONFIG:Debug>:-g>                # Enable debugging symbols for Debug
        $<$<CONFIG:Release>:-O3>             # Enable high optimization for Release
        $<$<CONFIG:Dist>:-O3>                # Enable high optimization for Dist
)

# Set target-specific output directories
set_target_properties(Shmeckle PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Shmeckle
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Shmeckle
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin-int/Shmeckle
)

# Post-build command on windows
if(WIN32)
    add_custom_command(TARGET Shmeckle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Shmeckle> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Sandbox
    )
endif()
