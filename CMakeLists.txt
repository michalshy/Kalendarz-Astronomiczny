cmake_minimum_required(VERSION 3.20)
project(kalendarz_astronomiczny)

set(CMAKE_CXX_STANDARD 14)

add_executable(kalendarz_astronomiczny
        main.cpp
        ListElement.h
        List.h
        Date.cpp
        Date.h
        InputManager.cpp
        InputManager.h
        EventManager.cpp
        EventManager.h
        )
