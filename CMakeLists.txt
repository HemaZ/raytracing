cmake_minimum_required(VERSION 3.2)
project(raytracing)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(raytracing src/raytracing/image.cpp)
target_include_directories(raytracing PUBLIC include)

add_executable(demo src/demo_main.cpp)
target_link_libraries(demo raytracing)

include(tests/CMakeLists.txt)