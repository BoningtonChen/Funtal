//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_EVENT_H
#define FUNTAL_EVENT_H

#endif //FUNTAL_EVENT_H
#pragma once

#include "Funtal/Core.h"

#include <string>
#include <functional>

namespace Funtal
{
    // * 事件系统主要用于阻塞当前事件
    // * 用于立即处理系统事件，非并行处理
    // * 未来可能会用更加复杂但清晰但系统代替当前beta版事件系统
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

#define EVENT_CLASS_CATEGORY(category) vitual int GetCategoryFlags() const override { return category; }

    class FUNTAL_API Event
    {
        friend class EventDispatcher;

    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsIntCategory(EventCategory category)
        {
            return GetCategoryFlags()& category;
        }

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {

    };
}