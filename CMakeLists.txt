cmake_minimum_required(VERSION 3.15)
project(OpenGlAndVulkanPlayground)

set(CMAKE_CXX_STANDARD 17)

# -- set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion")
# -- set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

# -------------- Start Internal sources setup ---------------------------------------------------
set(InternalSourcesRoot InternalSources)

set(InternalSourcesFiles
        ${InternalSourcesRoot}/Shader/shader.hpp
        ${InternalSourcesRoot}/Shader/shader.cpp
        ${InternalSourcesRoot}/GpuData/gpu_data.hpp
        ${InternalSourcesRoot}/GpuData/gpu_data.cpp)

include_directories(${InternalSourcesRoot})

# -------------- Sop Internal headers setup ------------------------------------------------------

# -------------- Start External sources setup ---------------------------------------------------

# Set the variable ExternalSources path to the root directory
set(ExternalSourcesRoot Dependencies/Sources)
# Set the ExternalSources actual files
set(ExternalSourcesFiles
        ${ExternalSourcesRoot}/glad/glad.h
        ${ExternalSourcesRoot}/KHR/khrplatform.h
        ${ExternalSourcesRoot}/glad.c)
# Set the include directories to the external headers root for analysis when writing includes
include_directories(${ExternalSourcesRoot})

# -------------- Stop External headers setup ------------------------------------------------------

# -------------- Start External libraries setup ---------------------------------------------------

# Set external libraries root
#set(ExternalLibrariesRoot Dependencies/Libraries)
# Set actual libs path
#set(ExternalLibrariesFilePaths ${ExternalLibrariesRoot}/GLFW/Debug)
# Include link paths
#link_directories(${ExternalLibrariesFilePaths})

#add_library(glfw3StaticLib STATIC IMPORTED) # or STATIC instead of SHARED
#set_target_properties(glfw3StaticLib PROPERTIES
#        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/${ExternalLibrariesRoot}/GLFW/Debug/glfw3.lib"
#        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/${ExternalSourcesRoot}/GLFW"
#        )


# Build glfw from sources together with the project
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/Dependencies/SourcesToBuild/glfw-3.3.2)
# -------------- Stop External libraries setup ----------------------------------------------------

# -------------- OpenGL Setup ---------------------------------------------------------------------
find_package(OpenGL REQUIRED)
# -------------- OpenGL Setup ---------------------------------------------------------------------


add_executable(OpenGlAndVulkanPlayground main.cpp ${ExternalSourcesFiles} ${InternalSourcesFiles})
target_link_libraries(OpenGlAndVulkanPlayground glfw)
target_link_libraries(OpenGlAndVulkanPlayground OpenGL::GL)

# -------------- Copy assets ----------------------------------------------------------------------
file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_BINARY_DIR})


#target_link_libraries(OpenGlAndVulkanPlayground glfw3.lib opengl32.lib)
#target_link_libraries(OpenGlAndVulkanPlayground glfw3StaticLib)
