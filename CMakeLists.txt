cmake_minimum_required(VERSION 3.23)
project(Funtal)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

set(LIBRARY_OUTPUT_DIRECTORY lib/Funtal)
set(ARCHIVE_OUTPUT_DIRECTORY lib/Funtal)

set(SANDBOX
        Sandbox/SandboxApp.cpp
)
set(FUNTAL_SRC
        Engine/src/Funtal.h

        Engine/src/Funtal/Application.cpp
        Engine/src/Funtal/Application.h
        Engine/src/Funtal/Core.h
        Engine/src/Funtal/EntryPoint.h
)
set(INCLUDE_DIR
        Engine/src
        Engine/src/Funtal
        Sandbox/src
)

include_directories(
        ${INCLUDE_DIR}
)

add_library(Funtal STATIC SHARED MODULE
        ${FUNTAL_SRC}
        )

add_executable(SandboxApp
        ${SANDBOX}
        )

#target_link_libraries(SandboxApp
#        lib/Funtal/
#        pthread
#        )
