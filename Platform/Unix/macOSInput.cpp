//
// Created by 陈奕锟 on 2022/11/6.
//
#include "ftpch.h"

#include "macOSInput.h"
#include "Funtal/Application.h"

#include <GLFW/glfw3.h>

namespace Funtal
{
    Input* Input::s_Instance = new macOSInput();

    bool macOSInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(
                Application::Get().GetWindow().GetNativeWindow()
                );
        auto state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool macOSInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(
                Application::Get().GetWindow().GetNativeWindow()
        );
        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> macOSInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(
                Application::Get().GetWindow().GetNativeWindow()
        );
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        return { (float)xPos, (float)yPos };
    }

    float macOSInput::GetMouseXImpl()
    {
        auto[xPos, yPos] = GetMousePositionImpl();
        return xPos;
    }
    float macOSInput::GetMouseYImpl()
    {
        auto[xPos, yPos] = GetMousePositionImpl();
        return yPos;
    }

}
