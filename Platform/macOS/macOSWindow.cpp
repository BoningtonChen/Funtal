//
// Created by 陈奕锟 on 2022/10/27.
//
#include "ftpch.h"

#include "macOSWindow.h"

namespace Funtal
{
    static bool s_GLFWInitialized = false;

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

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(
                (int)props.Width, (int)props.Height,
                m_Data.Title.c_str(),
                nullptr, nullptr
                );

        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
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