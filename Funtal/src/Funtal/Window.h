//
// Created by 陈奕锟 on 2022/10/26.
//

#ifndef FUNTAL_WINDOW_H
#define FUNTAL_WINDOW_H

#endif //FUNTAL_WINDOW_H
#pragma once

#include "ftpch.h"

#include "Funtal/Core.h"
#include "Funtal/Events/Event.h"

namespace Funtal
{

    // * Window API
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        explicit WindowProps(
                std::string  title = "Funtal Engine",
                unsigned int width = 1280,
                unsigned int height = 720
                )
            : Title( std::move(title) ), Width(width), Height(height)
        {}
    };

    // * 给PC端应用创建的图形界面接口
    class FUNTAL_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enable) = 0;
        [[nodiscard]] virtual bool IsVSync() const = 0;

        static Window* Create( const WindowProps& props = WindowProps() );
    };
}