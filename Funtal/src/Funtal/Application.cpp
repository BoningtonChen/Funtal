//
// Created by 陈奕锟 on 2022/10/23.
//
#include "ftpch.h"

#include "Application.h"

#include "Funtal/Events/ApplicationEvent.h"
#include "Funtal/Log.h"

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
            m_Window -> OnUpdate();
        }
    }
}
