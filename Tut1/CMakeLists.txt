cmake_minimum_required(VERSION 3.26)
project(Tut1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tut1 main.cpp
        item.cpp
        item.h
        hero.cpp
        hero.h
        character.cpp
        character.h
        namespace_example.cpp)
