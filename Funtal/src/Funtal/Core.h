//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_CORE_H
#define FUNTAL_CORE_H

    #define FT_PLATFORM_MACOS

#endif //FUNTAL_CORE_H
#pragma once

#ifdef FT_PLATFORM_MACOS

    #ifdef FT_BUILD_DLL
        #define FUNTAL_API __attribute(( visibility("default") ))
    #else
        #define FUNTAL_API __attribute(( visibility("default") ))
    #endif

#elif FT_PLATFORM_WINDOWS
    #ifdef FT_BUILD_DLL
        #define FUNTAL_API __declspec(dllimport)
    #else
        #define FUNTAL_API __declspec(dllexport)
    #endif

#elif FT_PLATFORM_UNIX
    #ifdef FT_BUILD_DLL
        #define FUNTAL_API __attribute(( visibility("default") ))
    #else
        #define FUNTAL_API __attribute(( visibility("default") ))
    #endif
#else
    #error Funtal UNSUPPORTED Platform, sorry!
#endif

#define BIT(x) (1 << x)