cmake_minimum_required(VERSION 3.10)

# Project name
project(OpenGL_Project VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GLAD
include_directories(libs/GLAD/include)

# GLFW
find_package(glfw3 3.3 REQUIRED)

# Executables and linking
add_executable(${PROJECT_NAME} libs/GLAD/src/glad.c src/ogl.cpp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} glfw)