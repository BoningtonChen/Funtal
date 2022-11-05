//
// Created by 陈奕锟 on 2022/10/23.
//
#define FT_PLATFORM_MACOS

#include <Funtal.h>

class ExampleLayer : public Funtal::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {

    }

    void OnUpdate() override
    {
        FT_INFO("ExampleLayer::Update");
    }

    void OnEvent(Funtal::Event& event) override
    {
        FT_TRACE("{0}", event);
    }
};

class Sandbox : public Funtal::Application
{
public:
    Sandbox()
    {
        PushLayer( new ExampleLayer() );
        PushOverlay( new Funtal::ImGuiLayer() );
    }
    ~Sandbox() override = default;
};

Funtal::Application* Funtal::CreateApplication()
{
    return new Sandbox();
}
