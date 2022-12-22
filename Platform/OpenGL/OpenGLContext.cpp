//
// Created by 陈奕锟 on 2022/12/22.
//
#include "ftpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Funtal
{
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
        : m_WindowHandle(windowHandle)
    {
        FT_CORE_ASSERT(windowHandle, "Window Handle is NULL!")
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );
        FT_CORE_ASSERT(status, "Failed to initialize GLAD!")
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}