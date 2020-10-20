cmake_minimum_required(VERSION 3.16)
project(noonpost)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp lib/glad/src/gl.c)


set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")


find_package (OpenGL REQUIRED)

find_package (glfw3 REQUIRED)

add_executable(noonpost main.cpp)

set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/gl.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" glfw "${CMAKE_DL_LIBS}")
