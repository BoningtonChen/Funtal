//
// Created by 陈奕锟 on 2022/10/28.
//

#include "ftpch.h"
#include "Layer.h"


namespace Funtal
{
    Layer::Layer(std::string debugName)
        : m_DebugName( std::move(debugName) )
    {}

    Layer::~Layer() = default;
}