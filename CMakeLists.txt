cmake_minimum_required(VERSION 3.16)
project(noonpost)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)


set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package (OpenGL REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})



set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/gl.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${LIB_DIR}/GLFW/include")



add_subdirectory(lib/glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


target_include_directories(${PROJECT_NAME} PRIVATE "${LIB_DIR}/glew/include")
add_subdirectory(lib/glew/build/cmake)

target_link_libraries(${PROJECT_NAME} "glad" glew glfw "${CMAKE_DL_LIBS}")
