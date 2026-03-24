cmake_minimum_required(VERSION 3.14)
project(HomeworkWorkspace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LauncherMain main.cpp src/Launcher.cpp)
target_include_directories(LauncherMain PRIVATE include)
target_compile_definitions(LauncherMain PRIVATE
    PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}"
    PROJECT_BINARY_DIR="${CMAKE_BINARY_DIR}"
    BUILD_TYPE="$<CONFIG>"
)

add_subdirectory(tasks/Task1)
add_subdirectory(tasks/Task2)
add_subdirectory(tasks/Task3)
