cmake_minimum_required(VERSION 3.28)
project(Uez5_tut)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uez5_tut main.cpp
        character.cpp
        hero.cpp
        item.cpp
        fighter.cpp
        npc.cpp
        sorcerer.cpp
        game.cpp
        )
