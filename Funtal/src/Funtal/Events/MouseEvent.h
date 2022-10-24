//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_MOUSEEVENT_H
#define FUNTAL_MOUSEEVENT_H

#endif //FUNTAL_MOUSEEVENT_H
#pragma once

#include "Event.h"

#include <sstream>

namespace Funtal
{
    class FUNTAL_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y)
        {}

        [[nodiscard]] inline float GetX() const { return m_MouseX; }
        [[nodiscard]] inline float GetY() const { return m_MouseY; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX;
        float m_MouseY;
    };
}