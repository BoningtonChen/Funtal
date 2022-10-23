cmake_minimum_required(VERSION 3.23)
project(Funtal)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fms-extensions")


set(FUNTAL_SRC_DIR
        Funtal/
        Funtal/src
        )
set(FUNTAL_LIB_DIR
        Funtal/lib
        )
set(FUNTAL_SRC
        Funtal/src/Funtal.h

        Funtal/src/Funtal/Application.h
        Funtal/src/Funtal/Application.cpp

        Funtal/src/Funtal/Core.h
        Funtal/src/Funtal/Core.cpp

        Funtal/src/Funtal/EntryPoint.h
        )
set(FUNTAL_LIB
        libfuntal.dylib
        )

set(SANDBOX_SRC_DIR
        Sandbox/
        )
set(SANDBOX_SRC
        Sandbox/SandboxApp.cpp
        )

include_directories(
        ${FUNTAL_SRC_DIR}
        )
link_directories(
        ${FUNTAL_LIB_DIR}
        )

add_library(funtal SHARED
        ${FUNTAL_SRC}
        )
add_executable(Funtal_App
        ${SANDBOX_SRC}
        )

target_link_libraries(Funtal_App
        ${FUNTAL_LIB}
        pthread
        )

if (APPLE)
    foreach(EXECUTABLE ${EXECUTABLE_OUTPUT_PATH})
        target_link_libraries(${EXECUTABLE} "-framework OpenGL")
        target_link_libraries(${EXECUTABLE} "-framework GLUT")
    endforeach()
endif()