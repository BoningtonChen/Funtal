//
// Created by 陈奕锟 on 2022/10/23.
//
#include "ftpch.h"

#include "Application.h"

#include "Funtal/Events/ApplicationEvent.h"
#include "Funtal/Log.h"

#include <GLFW/glfw3.h>

namespace Funtal
{
    Funtal::Application::Application()
    {
        m_Window = std::unique_ptr<Window>( Window::Create() );
    }
    Application::~Application() = default;

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window -> OnUpdate();
        }
    }
}
