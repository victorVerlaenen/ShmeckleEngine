# Shmeckle directory

project(Shmeckle)

# Build GLFW as a static library
set(GLFW_BUILD_STATIC ON CACHE BOOL "Build GLFW as a static library")

# Disable building of GLFW examples, tests, and docs
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Do not build GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Do not build GLFW tests")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Do not build GLFW documentation")

# Add GLFW
add_subdirectory(vendor/GLFW)

# Add OpenGL if using GLFW for rendering
find_package(OpenGL REQUIRED)

# Create a shared library
add_library(Shmeckle SHARED
    # General files
    source/Shmeckle.h
    source/Shmeckle/Core.h
    source/Shmeckle/EntryPoint.h
    source/Shmeckle/Application.h
    source/Shmeckle/Application.cpp
    source/Shmeckle/Logger.h
    source/Shmeckle/Logger.cpp
    source/Shmeckle/Window.h
    source/Shmeckle/Layers/Layer.h
    source/Shmeckle/Layers/Layer.cpp
    source/Shmeckle/Layers/LayerStack.h
    source/Shmeckle/Layers/LayerStack.cpp
    # Event files
    source/Shmeckle/Events/Event.h
    source/Shmeckle/Events/Event.cpp
    source/Shmeckle/Events/ApplicationEvents.h
    source/Shmeckle/Events/KeyEvents.h
    source/Shmeckle/Events/MouseEvents.h
    # Platform specifics
    source/Platform/Windows/WindowsWindow.h
    source/Platform/Windows/WindowsWindow.cpp
)

# Add VLD 
set(VLD_BASE_PATH "C:/Program Files (x86)/Visual Leak Detector")

if(EXISTS "${VLD_BASE_PATH}/include" AND EXISTS "${VLD_BASE_PATH}/lib/Win64/vld.lib")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /DEBUG")
    target_include_directories(Shmeckle PRIVATE "${VLD_BASE_PATH}/include")
    target_link_libraries(Shmeckle PRIVATE "${VLD_BASE_PATH}/lib/Win64/vld.lib")
    target_compile_definitions(Shmeckle PRIVATE VLD_AVAILABLE)
else()
    message(WARNING "Visual Leak Detector not found. Skipping its configuration.")
endif()

# Link GLFW and OpenGL
target_link_libraries(Shmeckle 
    PRIVATE 
        glfw
        OpenGL::GL
)


# Include directories
target_include_directories(Shmeckle 
    PRIVATE
        vendor/spdlog/include
        vendor/GLFW/include
        source # This is so that you can just include the Shmeckle.h header easily
)

# Preprocessor definitions
target_compile_definitions(Shmeckle 
    PRIVATE
        SHMECKLE_BUILD_DLL
)

# Precompiled header
target_precompile_headers(Shmeckle
    PRIVATE
        source/smpch.h
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
