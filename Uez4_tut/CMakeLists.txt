cmake_minimum_required(VERSION 3.26)
project(Uez3_tut)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uez3_tut main.cpp
        character.cpp
        hero.cpp
        item.cpp
        npc.cpp
        npc.h
        sorcerer.cpp
        sorcerer.h
        fighter.cpp
        fighter.h
        exceptions.h
)
