//
// Created by 陈奕锟 on 2022/10/28.
//

#ifndef FUNTAL_LAYER_H
#define FUNTAL_LAYER_H

#endif //FUNTAL_LAYER_H
#pragma once

#include "Funtal/Core.h"
#include "Funtal/Events/Event.h"

namespace Funtal
{
    class FUNTAL_API Layer
    {
    public:
        explicit Layer(std::string  name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        [[nodiscard]] inline const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
}