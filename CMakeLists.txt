cmake_minimum_required(VERSION 3.15)
project(edgeDetection)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(edgeDetection main.cpp)
target_link_libraries(edgeDetection ${OpenCV_LIBS})