//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_KEYEVENT_H
#define FUNTAL_KEYEVENT_H

#endif //FUNTAL_KEYEVENT_H
#pragma once

#include "Event.h"

#include <sstream>

namespace Funtal
{
    class FUNTAL_API KeyEvent : public Event
    {
    public:
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        explicit KeyEvent(int keycode)
            : m_KeyCode(keycode)
        {}

        int m_KeyCode;
    };

    class FUNTAL_API KeyPressedEvent final : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount)
        {}

        [[nodiscard]] inline int GetRepeatCount() const { return m_RepeatCount; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)



    private:
        int m_RepeatCount;
    };

    class FUNTAL_API KeyReleasedEvent final : public KeyEvent
    {
    public:
        explicit KeyReleasedEvent(int keycode)
            : KeyEvent(keycode)
        {}

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeReleased)
    };
}