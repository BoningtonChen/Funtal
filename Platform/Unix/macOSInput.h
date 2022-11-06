//
// Created by 陈奕锟 on 2022/11/6.
//

#ifndef FUNTAL_MACOSINPUT_H
#define FUNTAL_MACOSINPUT_H

#endif //FUNTAL_MACOSINPUT_H
#pragma once

#include "Funtal/Input.h"

namespace Funtal
{
    class macOSInput : public Input
    {
    protected:
        bool IsKeyPressedImpl(int keycode) override;

        bool IsMouseButtonPressedImpl(int button) override;

        std::pair<float, float> GetMousePositionImpl() override;
        float GetMouseXImpl() override;
        float GetMouseYImpl() override;
    };
}