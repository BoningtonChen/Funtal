//
// Created by 陈奕锟 on 2022/10/23.
//

#include "Application.h"

#ifndef FUNTAL_ENTRYPOINT_H
#define FUNTAL_ENTRYPOINT_H

#endif //FUNTAL_ENTRYPOINT_H
#pragma once

#ifdef FT_PLATFORM_MACOS

int main(int argc, char* argv[])
{
    Funtal::Log::Init();

    FT_CORE_WARN("Initialized Log!");
    FT_INFO("Hello! :)");

    auto app = Funtal::CreateApplication();
    app -> Run();

    delete app;

    return 0;
}

#endif