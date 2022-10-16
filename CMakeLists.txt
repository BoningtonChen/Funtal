cmake_minimum_required(VERSION 3.23)
project(Funtal)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdeclspec")

include_directories(
        Engine/src
        Sandbox/src
)

add_executable(Funtal

        # *Engine DIR
        Engine/src/Funtal.h
        Engine/src/Funtal/Core.h
        Engine/src/Funtal/EntryPoint.h

        Engine/src/Funtal/Application.cpp
        Engine/src/Funtal/Application.h

        # *Sandbox DIR
        Sandbox/SandboxApp.cpp
        )
