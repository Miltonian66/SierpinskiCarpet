cmake_minimum_required(VERSION 3.27)
project(SierpinskiCarpet)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS window graphics system REQUIRED)

add_executable(SierpinskiCarpet main.cpp)

target_link_libraries(SierpinskiCarpet sfml-graphics)