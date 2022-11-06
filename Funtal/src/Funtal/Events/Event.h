//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_EVENT_H
#define FUNTAL_EVENT_H

#endif //FUNTAL_EVENT_H
#pragma once

#include "Funtal/Core.h"

namespace Funtal
{
    // * 事件系统主要用于阻塞当前事件
    // * 用于立即处理系统事件，目前alpha版本为非并行处理
    // * 未来可能会用更加复杂但清晰但系统代替当前beta版事件系统
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
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

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                            virtual EventType GetEventType() const override { return GetStaticType(); }\
                            virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class FUNTAL_API Event
    {
        // friend class EventDispatcher;
    public:
        virtual ~Event() = default;

        bool Handled = false;

        [[nodiscard]] virtual EventType GetEventType() const = 0;
        [[nodiscard]] virtual const char* GetName() const = 0;
        [[nodiscard]] virtual int GetCategoryFlags() const = 0;
        [[nodiscard]] virtual std::string ToString() const { return GetName(); }

        [[nodiscard]] inline bool IsInCategory(EventCategory category) const
        {
            return GetCategoryFlags()& category;
        }

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        explicit EventDispatcher(Event& event)
            : m_Event(event)
        {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if ( m_Event.GetEventType() == T::GetStaticType() )
            {
                m_Event.Handled |= func( *(T*)& m_Event );
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<< (std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}
