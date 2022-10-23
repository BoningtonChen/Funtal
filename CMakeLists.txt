cmake_minimum_required(VERSION 3.23)
project(Funtal)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fms-extensions")

file(COPY cmake-build-debug/lib/Funtal/libfuntal.dylib DESTINATION lib/Funtal FOLLOW_SYMLINK_CHAIN)
file(COPY cmake-build-debug/lib/Funtal/libfuntal.a     DESTINATION lib/Funtal FOLLOW_SYMLINK_CHAIN)
file(COPY cmake-build-debug/lib/Funtal/libfuntal.so    DESTINATION lib/Funtal FOLLOW_SYMLINK_CHAIN)

# ! Funtal 依赖目录和文件
set(LIB_DIR
        lib/Funtal
        )
set(FUNTAL_SRC_DIR
        Funtal/
        Funtal/src
        )
set(FUNTAL_SRC
        Funtal/src/Funtal.h

        Funtal/src/Funtal/Application.h
        Funtal/src/Funtal/Application.cpp

        Funtal/src/Funtal/Core.h

        Funtal/src/Funtal/EntryPoint.h

        Funtal/src/Funtal/Log.h
        Funtal/src/Funtal/Log.cpp
        )
set(FUNTAL_LIB
        libfuntal.dylib
        libfuntal.a
        libfuntal.so
        )

set(SANDBOX_SRC_DIR
        Sandbox/src
        )
set(SANDBOX_SRC
        Sandbox/src/SandboxApp.cpp
        )

# ! 第三方依赖目录
set(SPDLOG_INC_DIR
        Funtal/vendor/spdlog/include
        )

# ! 链接包含和链接目录
include_directories(
        # * Funtal 依赖
        ${FUNTAL_SRC_DIR}
        ${SANDBOX_SRC_DIR}
        # * 第三方依赖
        ${SPDLOG_INC_DIR}
        )
link_directories(
        ${LIB_DIR}
        )

# ! 添加库和可执行文件
add_library(funtal SHARED
        ${FUNTAL_SRC}
        )
add_executable(Funtal_App
        ${SANDBOX_SRC}
        )

# ! 链接库
target_link_libraries(Funtal_App
        ${FUNTAL_LIB}
        pthread
        )

# ! 链接 APPLE OpenGL 库
if (APPLE)
    foreach(EXECUTABLE ${EXECUTABLE_OUTPUT_PATH})
        target_link_libraries(${EXECUTABLE} "-framework OpenGL")
        target_link_libraries(${EXECUTABLE} "-framework GLUT")
    endforeach()
endif()
