//
// Created by 陈奕锟 on 2022/10/23.
//

#include <Funtal.h>

#include "imgui.h"

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
            FT_TRACE("TAB Key is pressed! (poll)");
    }

    void OnImGuiRender() override
    {
        ImGui::Begin("Test :)");
        ImGui::Text("Hello Funtal. :)");
        ImGui::End();
    }

    void OnEvent(Funtal::Event& event) override
    {
        if (event.GetEventType() == Funtal::EventType::KeyPressed)
        {
            auto& e = (Funtal::KeyPressedEvent&)event;

            if ( (int)e.GetEventType() == FT_KEY_TAB )
                FT_TRACE("TAB Key is pressed! (event)");

            FT_TRACE( "{0}", (char)e.GetKeyCode() );
        }
    }
};

class Sandbox : public Funtal::Application
{
public:
    Sandbox()
    {
        PushLayer( new ExampleLayer() );
    }
    ~Sandbox() override = default;
};

Funtal::Application* Funtal::CreateApplication()
{
    return new Sandbox();
}
