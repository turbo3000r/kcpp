cmake_minimum_required(VERSION 3.14)
project(KCPP_Workspace LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LauncherMain main.cpp src/Launcher.cpp src/project.cpp)
target_include_directories(LauncherMain PRIVATE include)
target_compile_definitions(LauncherMain PRIVATE
    PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}"
    PROJECT_BINARY_DIR="${CMAKE_BINARY_DIR}"
    BUILD_TYPE="$<CONFIG>"
)

file(GLOB TASK_DIRS RELATIVE ${CMAKE_SOURCE_DIR} tasks/*)
foreach(TASK_DIR ${TASK_DIRS})
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${TASK_DIR}")
        add_subdirectory(${TASK_DIR})
    endif()
endforeach()
