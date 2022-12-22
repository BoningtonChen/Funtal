//
// Created by 陈奕锟 on 2022/12/22.
//

#ifndef FUNTAL_OPENGLCONTEXT_H
#define FUNTAL_OPENGLCONTEXT_H

#endif //FUNTAL_OPENGLCONTEXT_H
#pragma once

#include "Funtal/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Funtal
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        explicit OpenGLContext(GLFWwindow* windowHandle);

        void Init() override;
        void SwapBuffers() override;

    private:
        GLFWwindow* m_WindowHandle;
    };
}