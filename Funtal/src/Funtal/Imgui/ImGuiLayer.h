//
// Created by 陈奕锟 on 2022/11/5.
//

#ifndef FUNTAL_IMGUILAYER_H
#define FUNTAL_IMGUILAYER_H

#endif //FUNTAL_IMGUILAYER_H
#pragma once

#include "Funtal/Layer.h"

#include "Funtal/Events/KeyEvent.h"
#include "Funtal/Events/MouseEvent.h"
#include "Funtal/Events/ApplicationEvent.h"

namespace Funtal
{
    class FUNTAL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);

    private:
        float m_Time = 0.0f;
    };
}