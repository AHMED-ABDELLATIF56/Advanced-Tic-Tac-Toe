cmake_minimum_required(VERSION 3.26)
project(New_folder)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(New_folder
        include/CLASSES.hpp
        include/database.h
        src/AI.cpp
        src/Game.cpp
        src/GameManager.cpp
        src/Player.cpp
        src/database.cpp
)

