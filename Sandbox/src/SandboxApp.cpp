//
// Created by 陈奕锟 on 2022/10/23.
//

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
        if ( Funtal::Input::IsKeyPressed(FT_KEY_TAB) )
            FT_TRACE("TAB Key is pressed!");
    }

    void OnEvent(Funtal::Event& event) override
    {
        // FT_TRACE("{0}", event);

        if (event.GetEventType() == Funtal::EventType::KeyPressed)
        {

        }
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
