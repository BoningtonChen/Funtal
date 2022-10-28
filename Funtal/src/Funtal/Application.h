//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_APPLICATION_H
#define FUNTAL_APPLICATION_H

    #define FT_PLATFORM_MACOS
    #define FT_BUILD_DLL

#endif //FUNTAL_APPLICATION_H
#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Funtal
{
    class FUNTAL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        LayerStack m_LayerStack;
    };

    // TO be defined in the CLIENT
    Application* CreateApplication();
}