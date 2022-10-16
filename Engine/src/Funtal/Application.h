//
// Created by 陈奕锟 on 2022/10/16.
//

#ifndef FUNTAL_APPLICATION_H
#define FUNTAL_APPLICATION_H

#define FT_PLATFORM_MACOS
#define FT_BUILD_DLL

#endif //FUNTAL_APPLICATION_H
#pragma once

#include "Core.h"

namespace Funtal
{
    class FUNTAL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}
