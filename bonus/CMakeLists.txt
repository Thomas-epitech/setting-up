cmake_minimum_required(VERSION 3.5)

# Use the provided project name or default to "setting_up" if not set
set(PROJECT_NAME_DEFAULT "Project")
set(PROJECT_NAME "${PROJECT_NAME_DEFAULT}" CACHE STRING "Project name")

project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 11)

# Enable generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the directory containing header files
include_directories("${CMAKE_CURRENT_LIST_DIR}/include")

# Look for .c files in the directory where this CMakeLists.txt is located
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.c")

# Print found source files for debugging
message(STATUS "Found source files: ${SOURCES}")

# Ensure that SOURCES is not empty before trying to add the executable
if(SOURCES)
    add_executable(setting_up ${SOURCES})
else()
    message(FATAL_ERROR "No source files found in the current directory!")
endif()
