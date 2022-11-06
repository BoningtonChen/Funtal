//
// Created by 陈奕锟 on 2022/10/26.
//

#ifndef FUNTAL_MACOSWINDOW_H
#define FUNTAL_MACOSWINDOW_H

#endif //FUNTAL_MACOSWINDOW_H
#pragma once

#include "Funtal/Window.h"

#include <GLFW/glfw3.h>

namespace Funtal
{
    class macOSWindow : public Window
    {
    public:
        explicit macOSWindow(const WindowProps& props);
        ~macOSWindow() override;

        void OnUpdate() override;

        [[nodiscard]] inline unsigned int GetWidth() const override { return m_Data.Width; }
        [[nodiscard]] inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

        void SetVSync(bool enabled) override;
        [[nodiscard]] bool IsVSync() const override;

        [[nodiscard]] inline void* GetNativeWindow() const override { return m_Window; }

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
