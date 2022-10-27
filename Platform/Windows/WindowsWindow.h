//
// Created by 陈奕锟 on 2022/10/27.
//

#ifndef FUNTAL_WINDOWSWINDOW_H
#define FUNTAL_WINDOWSWINDOW_H

#endif //FUNTAL_WINDOWSWINDOW_H
#pragma once

#include "Funtal/Window.h"

#include <GLFW/glfw3.h>

namespace Funtal
{
    class WindowsWindow : public Window
    {
    public:
        explicit WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        [[nodiscard]] inline unsigned int GetWidth() const override { return m_Data.Width; }
        [[nodiscard]] inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

        void SetVSync(bool enabled) override;
        [[nodiscard]] bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}
