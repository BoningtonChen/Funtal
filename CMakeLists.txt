cmake_minimum_required(VERSION 3.20)
project(Funtal)

# * 设置 C/C++ 语言版本
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# * 用于添加动态链接库和 C/C++ 混编
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -fms-extensions")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c23")

# * 添加平台适配的项目预定义宏环境
if(APPLE)
    add_definitions(-D FT_PLATFORM_MACOS -D GLFW_INCLUDE_NONE -D FT_DEBUG)
elseif(MINGW)
    add_definitions(-D FT_PLATFORM_WINDOWS -D GLFW_INCLUDE_NONE -D FT_DEBUG)
elseif(MSVC)
    add_definitions(-D FT_PLATFORM_WINDOWS -D GLFW_INCLUDE_NONE -D FT_DEBUG)
endif()

# * 强制使用CXX编译.c文件，防止出现C++出现找不到头文件STL的情况
set(C_SRC
        Funtal/vendor/GLAD/src/glad.c
        )
set_source_files_properties(${C_SRC} PROPERTIES LANGUAGE CXX)


# * 平台依赖目录和文件
set(PLATFORM_DIR
        Platform/Unix
        Platform/Windows
        Platform/Linux
        Platform/OpenGL
        )
set(PLATFORM_SRC
        # * Unix(macOS)
        Platform/Unix/macOSWindow.h
        Platform/Unix/macOSWindow.cpp

        Platform/Unix/macOSInput.h
        Platform/Unix/macOSInput.cpp

        # * Windows
        Platform/Windows/WindowsWindow.h
        Platform/Windows/WindowsWindow.cpp

        # * OpenGL
        Platform/OpenGL/OpenGLContext.h
        Platform/OpenGL/OpenGLContext.cpp
        )

# * Funtal 依赖和文件
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

        Funtal/src/Funtal/Input.h
        Funtal/src/Funtal/Input.cpp

        Funtal/src/Funtal/KeyCodes.h
        Funtal/src/Funtal/MouseButtonCodes.h

        Funtal/src/Funtal/ImGui/ImGuiLayer.h
        Funtal/src/Funtal/ImGui/ImGuiLayer.cpp
        Funtal/src/Funtal/ImGui/ImGuiBuild.cpp

        Funtal/src/Funtal/Renderer/GraphicsContext.h
        )
set(FUNTAL_LIB_DIR
        lib/Funtal
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
        Funtal/vendor/GLAD/include/KHR/khrplatform.h

        Funtal/vendor/GLAD/include/glad/glad.h
        Funtal/vendor/GLAD/src/glad.c
        )

set(IMGUI_CHERNO_INC_DIR
        Funtal/vendor/ImGui_Cherno
        Funtal/vendor/ImGui_Cherno/backends
        )
set(IMGUI_CHERNO_SRC
        Funtal/vendor/ImGui_Cherno/imgui.h
        Funtal/vendor/ImGui_Cherno/imgui.cpp

        Funtal/vendor/ImGui_Cherno/imconfig.h
        Funtal/vendor/ImGui_Cherno/imgui_internal.h
        Funtal/vendor/ImGui_Cherno/imstb_rectpack.h
        Funtal/vendor/ImGui_Cherno/imstb_textedit.h
        Funtal/vendor/ImGui_Cherno/imstb_truetype.h

        Funtal/vendor/ImGui_Cherno/imgui_demo.cpp
        Funtal/vendor/ImGui_Cherno/imgui_draw.cpp
        Funtal/vendor/ImGui_Cherno/imgui_tables.cpp
        Funtal/vendor/ImGui_Cherno/imgui_widgets.cpp

        Funtal/vendor/ImGui_Cherno/backends/imgui_impl_opengl3.h
        Funtal/vendor/ImGui_Cherno/backends/imgui_impl_opengl3.cpp
        )

set(GLM_INC_DIR
        Funtal/vendor/glm
        )


# ! 链接包含和链接目录
include_directories(
        # * 第三方依赖
        ${GLAD_INC_DIR}
        ${GLFW_INC_DIR}
        ${SPDLOG_INC_DIR}
        ${IMGUI_CHERNO_INC_DIR}
        ${GLM_INC_DIR}

        # * 平台适配依赖
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
add_library(funtal STATIC
        # * 第三方源
        ${GLAD_SRC}
        ${IMGUI_CHERNO_SRC}

        # * 项目源
        ${FUNTAL_SRC}
        ${PLATFORM_SRC}
        ${SANDBOX_SRC}
        )


# ! 添加可执行文件
add_executable(Funtal_App
        # * 第三方源
        ${GLAD_SRC}
        ${IMGUI_CHERNO_SRC}

        # * 项目源
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

# * 设置自动化拷贝生成的库文件
set(GENERATED_LIB
        cmake-build-debug/libfuntal.a
        cmake-build-debug/libfuntal.dylib
        cmake-build-debug/libfuntal.so
        )
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_LIB} ${FUNTAL_LIB_DIR})
