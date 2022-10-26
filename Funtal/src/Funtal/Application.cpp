//
// Created by 陈奕锟 on 2022/10/23.
//

#include "Application.h"

#include "Funtal/Events/ApplicationEvent.h"
#include "Funtal/Log.h"

namespace Funtal
{
    Funtal::Application::Application() = default;
    Application::~Application() = default;

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        FT_TRACE(e);

        while (true);
    }
}
