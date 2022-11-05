//
// Created by 陈奕锟 on 2022/10/27.
//
#include "ftpch.h"

#include "macOSWindow.h"

#include "Funtal/Events/ApplicationEvent.h"
#include "Funtal/Events/MouseEvent.h"
#include "Funtal/Events/KeyEvent.h"

#include <glad/glad.h>

namespace Funtal
{
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        FT_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window* Window::Create(const Funtal::WindowProps &props)
    {
        return new macOSWindow(props);
    }

    macOSWindow::macOSWindow(const Funtal::WindowProps &props)
    {
        Init(props);
    }

    macOSWindow::~macOSWindow() noexcept
    {
        Shutdown();
    }

    void macOSWindow::Init(const Funtal::WindowProps &props)
    {
        m_Data.Title = props.Title;

        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        FT_CORE_INFO("Creating window{0} {1}, {2}", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
            // TODO: 在系统关闭时实现 glfwTerminate()
            int success = glfwInit();
            FT_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);

            s_GLFWInitialized = true;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        m_Window = glfwCreateWindow(
                (int)props.Width, (int)props.Height,
                m_Data.Title.c_str(),
                nullptr, nullptr
                );

        glfwMakeContextCurrent(m_Window);

        int status = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );
        FT_CORE_ASSERT(status, "Failed to initialize GLAD!");

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);


        // * Set GLFW Callback
        glfwSetWindowSizeCallback(
                m_Window,
                [](GLFWwindow* window, int width, int height)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                    data.Width = width;
                    data.Height = height;

                    WindowResizeEvent event(width, height);
                    data.EventCallback(event);
                } );

        glfwSetWindowCloseCallback(
                m_Window,
                [](GLFWwindow* window)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    WindowCloseEvent event;
                    data.EventCallback(event);
                });

        glfwSetKeyCallback(
                m_Window,
                [](GLFWwindow* window, int key, int scancode, int action, int mods)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    switch (action)
                    {
                        case GLFW_PRESS:
                        {
                            KeyPressedEvent event(key, 0);
                            data.EventCallback(event);
                            break;
                        }
                        case GLFW_RELEASE:
                        {
                            KeyReleasedEvent event(key);
                            data.EventCallback(event);
                            break;
                        }
                        case GLFW_REPEAT:
                        {
                            KeyPressedEvent event(key, 1);
                            data.EventCallback(event);
                            break;
                        }
                    }
                } );

        glfwSetMouseButtonCallback(
                m_Window,
                [](GLFWwindow* window, int button, int action, int mods)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                    switch (action)
                    {
                        case GLFW_PRESS:
                        {
                            MouseButtonPressedEvent event(button);
                            data.EventCallback(event);
                            break;
                        }
                        case GLFW_RELEASE:
                        {
                            MouseButtonReleasedEvent event(button);
                            data.EventCallback(event);
                            break;
                        }
                    }
                } );

        glfwSetScrollCallback(
                m_Window,
                [](GLFWwindow* window, double xOffset, double yOffset)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                    MouseScrolledEvent event( (float)xOffset, (float)yOffset );
                    data.EventCallback(event);
                } );

        glfwSetCursorPosCallback(
                m_Window,
                [](GLFWwindow* window, double xPos, double yPos)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                    MouseMovedEvent event( (float)xPos, (float)yPos );
                    data.EventCallback(event);
                } );
    }

    void macOSWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void macOSWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void macOSWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool macOSWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}