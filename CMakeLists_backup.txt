cmake_minimum_required(VERSION 3.15)
project(OpenGlAndVulkanPlayground)

set(CMAKE_CXX_STANDARD 17)

# -------------- Start External headers setup ---------------------------------------------------

# Set the variable ExternalHeaders path to the root directory
set(ExternalSourcesRoot Dependencies/Sources)
# Set the ExternalHeaders actual files
set(ExternalSourcesFiles
        ${ExternalSourcesRoot}/GLFW/glfw3.h
        ${ExternalSourcesRoot}/GLFW/glfw3native.h
        ${ExternalSourcesRoot}/glad/glad.h
        ${ExternalSourcesRoot}/KHR/khrplatform.h
        ${ExternalSourcesRoot}/glad.c)
# Set the include directories to the external headers root for analysis when writing includes
include_directories(${ExternalSourcesRoot})

# -------------- Stop External headers setup ------------------------------------------------------

# -------------- Start External libraries setup ---------------------------------------------------

# Set external libraries root
set(ExternalLibrariesRoot Dependencies/Libraries)
# Set actual libs path
#set(ExternalLibrariesFilePaths ${ExternalLibrariesRoot}/GLFW/Debug)
# Include link paths
#link_directories(${ExternalLibrariesFilePaths})

add_library(glfw3StaticLib STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(glfw3StaticLib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/${ExternalLibrariesRoot}/GLFW/Debug/glfw3.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/${ExternalSourcesRoot}/GLFW"
        )

# -------------- Stop External libraries setup ----------------------------------------------------

add_executable(OpenGlAndVulkanPlayground main.cpp InternalHeaders/TestHeader.h ${ExternalSourcesFiles})
#target_link_libraries(OpenGlAndVulkanPlayground glfw3.lib opengl32.lib)
target_link_libraries(OpenGlAndVulkanPlayground glfw3StaticLib)

# ! Works with visual studio toolkit for the moment because of glfw3.lib - I can't compile it with mingw64 gcc for some reason