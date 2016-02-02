cmake_minimum_required(VERSION 3.3)
project(Calculator)
link_libraries(wininet)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BUILD_CALC Calculator)
set(SOURCE_FILES_CALC Calculator.cpp)
add_executable(${BUILD_CALC} ${SOURCE_FILES_CALC})

