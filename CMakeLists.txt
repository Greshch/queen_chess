cmake_minimum_required(VERSION 3.16)
project(app)

add_executable(app src/main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
add_dependencies(app OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS} )

target_link_libraries(app OpenGL::OpenGL ${GLUT_LIBRARY} )


