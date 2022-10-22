//
// Created by 陈奕锟 on 2022/10/16.
//

#include <Funtal.h>

class Sandbox : public Funtal::Application
{
public:
    Sandbox()
    = default;

    ~Sandbox() override
    = default;
};

Funtal::Application* Funtal::CreateApplication()
{
    return new Sandbox();
}
