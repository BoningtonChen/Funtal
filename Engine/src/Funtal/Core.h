//
// Created by 陈奕锟 on 2022/10/16.
//

#ifndef FUNTAL_CORE_H
#define FUNTAL_CORE_H

#endif //FUNTAL_CORE_H
#pragma once

#ifdef FT_PLATFORM_MACOS
    #ifdef FT_BUILD_DLL
        #define FUNTAL_API __declspec(dllexport)
    #else
        #define FUNTAL_API __declspec(dllimport)
    #endif
#else
    #error Funtal only support macOS FOR NOW !
#endif
