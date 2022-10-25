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

    class FUNTAL_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset)
        {}

        [[nodiscard]] inline float GetXOffset() const { return m_XOffset; }
        [[nodiscard]] inline float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_XOffset;
        float m_YOffset;
    };

    class FUNTAL_API MouseButtonEvent : public Event
    {
    public:
        [[nodiscard]] inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        explicit MouseButtonEvent(int button)
            : m_Button(button)
        {}

        int m_Button;
    };

    class FUNTAL_API MouseButtonPressedEvent final : public MouseButtonEvent
    {
    public:
        explicit MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button)
        {}

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class FUNTAL_API MouseButtonReleasedEvent final : public MouseButtonEvent
    {
    public:
        explicit MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button)
        {}

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
