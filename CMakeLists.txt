cmake_minimum_required(VERSION 3.29)
project(CPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPP main.cpp
        floor.cpp
        floor.h
        player.cpp
        player.h
        AABBCollision.cpp
        AABBCollision.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS window graphics audio network system REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(CPP sfml-system sfml-window sfml-graphics sfml-audio)
