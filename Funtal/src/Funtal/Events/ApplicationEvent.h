//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_APPLICATIONEVENT_H
#define FUNTAL_APPLICATIONEVENT_H

#endif //FUNTAL_APPLICATIONEVENT_H
#pragma once

#include "Event.h"

#include <sstream>

namespace Funtal
{
    class FUNTAL_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height)
        {}

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizedEvent: " << m_Width <<", " << m_Height;
            return ss.str();
        }



    private:
        unsigned int m_Width;
        unsigned int m_Height;
    };
}