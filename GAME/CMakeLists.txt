cmake_minimum_required(VERSION 3.26)
project(New_folder)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(New_folder
        include/CLASSES.hpp
        src/AI.cpp
        src/Game.cpp
        src/GameManager.cpp
        src/Player.cpp
<<<<<<< HEAD
        src/main.cpp
        src/main.cpp
        src/main.cpp
        src/main.cpp
        src/database.h)
=======
        src/database.cpp
        src/sqlite3.c
        include/database.h
	src/database.cpp
)
	
>>>>>>> 3b924b0d0ffdcb28f0b5ef682361bd55f15eddbe
