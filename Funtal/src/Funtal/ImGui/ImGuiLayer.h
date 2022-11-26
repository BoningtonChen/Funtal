//
// Created by 陈奕锟 on 2022/11/5.
//

#ifndef FUNTAL_IMGUILAYER_H
#define FUNTAL_IMGUILAYER_H

#endif //FUNTAL_IMGUILAYER_H
#pragma once

#include "Funtal/Layer.h"

#include "Funtal/Events/ApplicationEvent.h"
#include "Funtal/Events/KeyEvent.h"
#include "Funtal/Events/MouseEvent.h"

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

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
}