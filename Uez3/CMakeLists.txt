cmake_minimum_required(VERSION 3.26)
project(Uez3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uez3 main.cpp
        npc.cpp
        npc.h
        sorcerer.cpp
        sorcerer.h
        fighter.cpp
        fighter.h
        character.cpp
        hero.cpp
        item.cpp)
