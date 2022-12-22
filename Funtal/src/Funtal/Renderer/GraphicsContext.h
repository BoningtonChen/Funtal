//
// Created by 陈奕锟 on 2022/12/22.
//

#ifndef FUNTAL_GRAPHICSCONTEXT_H
#define FUNTAL_GRAPHICSCONTEXT_H

#endif //FUNTAL_GRAPHICSCONTEXT_H
#pragma once

namespace Funtal
{
    class GraphicsContext
    {
    public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };
}