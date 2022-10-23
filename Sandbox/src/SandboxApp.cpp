//
// Created by 陈奕锟 on 2022/10/23.
//
#include <Funtal.h>

#define FT_PLATFORM_MACOS

class Sandbox : public Funtal::Application
{
public:
    Sandbox() = default;
    ~Sandbox() override = default;
};

Funtal::Application* Funtal::CreateApplication()
{
    return new Sandbox();
}
