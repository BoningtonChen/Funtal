cmake_minimum_required(VERSION 3.20)
project(Funtal)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

# * 用于添加动态链接库和C、C++混编
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fms-extensions")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c23")

# * 强制使用CXX编译.c文件，防止出现C++出现找不到头文件STL的情况
set(C_SOURCE_FILES
        Funtal/vendor/GLAD/src/glad.c
        )
set_source_files_properties(${C_SOURCE_FILES} PROPERTIES LANGUAGE CXX)

# * 平台依赖目录和文件
set(PLATFORM_DIR
        Platform/Unix
        Platform/Windows
        Platform/Linux
        )
set(PLATFORM_SRC
        Platform/Unix/macOSWindow.h
        Platform/Unix/macOSWindow.cpp

        Platform/Windows/WindowsWindow.h
        Platform/Windows/WindowsWindow.cpp
        )

# * Funtal 依赖和文件
set(FUNTAL_LIB_DIR
        lib/Funtal
        )
set(FUNTAL_SRC_DIR
        Funtal/
        Funtal/src
        )
set(FUNTAL_SRC
        Funtal/src/ftpch.h
        Funtal/src/ftpch.cpp

        Funtal/src/Funtal.h

        Funtal/src/Funtal/Application.h
        Funtal/src/Funtal/Application.cpp

        Funtal/src/Funtal/Core.h

        Funtal/src/Funtal/EntryPoint.h

        Funtal/src/Funtal/Window.h

        Funtal/src/Funtal/Log.h
        Funtal/src/Funtal/Log.cpp

        Funtal/src/Funtal/Events/Event.h
        Funtal/src/Funtal/Events/ApplicationEvent.h
        Funtal/src/Funtal/Events/KeyEvent.h
        Funtal/src/Funtal/Events/MouseEvent.h

        Funtal/src/Funtal/Layer.h
        Funtal/src/Funtal/Layer.cpp
        Funtal/src/Funtal/LayerStack.h
        Funtal/src/Funtal/LayerStack.cpp
        )
set(FUNTAL_LIB
        libfuntal.dylib
        libfuntal.a
        libfuntal.so
        )

# * Sandbox应用程序 依赖和文件
set(SANDBOX_SRC_DIR
        Sandbox/src
        )
set(SANDBOX_SRC
        Sandbox/src/SandboxApp.cpp
        )

# * 第三方依赖目录和库
set(SPDLOG_INC_DIR
        Funtal/vendor/spdlog/include
        )

set(GLFW_INC_DIR
        Funtal/vendor/GLFW/include
        )
set(GLFW_LIB_DIR
        Funtal/vendor/GLFW/lib/lib-universal
        Funtal/vendor/GLFW/lib/lib-x86_64
        Funtal/vendor/GLFW/lib/lib-arm64
        )
set(GLFW_LIB
        libglfw.3.dylib
        libglfw3.a
        libglfw3.so
        )

set(GLAD_INC_DIR
        Funtal/vendor/GLAD/include
        )
set(GLAD_SRC
        Funtal/vendor/GLAD/include/glad/glad.h
        Funtal/vendor/GLAD/include/KHR/khrplatform.h
        Funtal/vendor/GLAD/src/glad.c
        )

# ! 链接包含和链接目录
include_directories(
        # * 第三方依赖
        ${GLAD_INC_DIR}
        ${GLFW_INC_DIR}
        ${SPDLOG_INC_DIR}

        # * 平台特化依赖
        ${PLATFORM_DIR}

        # * Funtal 依赖
        ${FUNTAL_SRC_DIR}
        ${SANDBOX_SRC_DIR}
        )

link_directories(
        # * 第三方依赖库
        ${GLFW_LIB_DIR}
        # * 项目库
        ${FUNTAL_LIB_DIR}
        )

# ! 添加库
add_library(funtal STATIC MODULE SHARED
        ${GLAD_SRC}
        ${FUNTAL_SRC}
        ${PLATFORM_SRC}
        ${SANDBOX_SRC}
        )

# ! 添加可执行文件
add_executable(Funtal_App
        ${GLAD_SRC}
        ${FUNTAL_SRC}
        ${PLATFORM_SRC}
        ${SANDBOX_SRC}
        )

# ! 设置预编译头文件
target_precompile_headers(funtal PUBLIC Funtal/src/ftpch.h)
target_precompile_headers(Funtal_App PUBLIC Funtal/src/ftpch.h)

# ! 链接库
target_link_libraries(funtal
        # * 第三方依赖库
        ${GLFW_LIB}
        # * 项目依赖库
        ${FUNTAL_LIB}
        pthread
        )
target_link_libraries(Funtal_App
        # * 第三方依赖库
        ${GLFW_LIB}
        # * 项目库
        ${FUNTAL_LIB}
        pthread
        )

# ! 链接 APPLE OpenGL 库
if (APPLE)
    target_link_libraries(funtal "-framework OpenGL")
    target_link_libraries(funtal "-framework GLUT")

    target_link_libraries(Funtal_App "-framework OpenGL")
    target_link_libraries(Funtal_App "-framework GLUT")
endif()
