cmake_minimum_required(VERSION 3.23)
project(Funtal)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fms-extensions")

add_executable(Funtal

        # *Engine DIR
        Engine/src/Test.cpp
        Engine/src/Test.h

        # *Sandbox DIR
        Sandbox/Application.cpp
        )
