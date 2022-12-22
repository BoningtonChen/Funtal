//
// Created by 陈奕锟 on 2022/10/28.
//

#ifndef FUNTAL_LAYERSTACK_H
#define FUNTAL_LAYERSTACK_H

#endif //FUNTAL_LAYERSTACK_H
#pragma once

#include "Core.h"
#include "Layer.h"

#include <vector>

namespace Funtal
{
    class FUNTAL_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverLay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}