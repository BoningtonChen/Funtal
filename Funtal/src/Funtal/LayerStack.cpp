//
// Created by 陈奕锟 on 2022/10/28.
//
#include "ftpch.h"
#include "LayerStack.h"

namespace Funtal
{
    LayerStack::LayerStack()
    {

    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
            delete layer;
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto iterator = std::find(
                m_Layers.begin(), m_Layers.end(),
                layer
                );

        if ( iterator != m_Layers.end() )
        {
            m_Layers.erase(iterator);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverLay(Layer *overlay)
    {
        auto iterator = std::find(
                m_Layers.begin(), m_Layers.end(),
                overlay
                );

        if ( iterator != m_Layers.end() )
            m_Layers.erase(iterator);
    }
}