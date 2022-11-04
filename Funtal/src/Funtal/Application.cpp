//
// Created by 陈奕锟 on 2022/10/23.
//
#include "ftpch.h"

#include "Application.h"

#include "Funtal/Events/ApplicationEvent.h"
#include "Funtal/Log.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Funtal
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>( Window::Create() );
        m_Window -> SetEventCallback( BIND_EVENT_FN(OnEvent) );
    }
    Application::~Application() = default;

    void Application::PushLayer(Funtal::Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Funtal::Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>( BIND_EVENT_FN(OnWindowClose) );

        for ( auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it) -> OnEvent(e);

            if (e.Handled)
                break;
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack)
                layer -> OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }
}
