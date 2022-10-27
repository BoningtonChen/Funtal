//
// Created by 陈奕锟 on 2022/10/27.
//

#include "WindowsWindow.h"

namespace Funtal
{
    static bool s_GLFWInitialized = false;

    WindowsWindow::WindowsWindow(const Funtal::WindowProps &props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow() noexcept
    {
        Shutdown();
    }

    void WindowsWindow::Init(const Funtal::WindowProps &props)
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

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}