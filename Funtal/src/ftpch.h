//
// Created by 陈奕锟 on 2022/10/26.
//

#ifndef FUNTAL_FTPCH_H
#define FUNTAL_FTPCH_H

#endif //FUNTAL_FTPCH_H
#pragma once

#include <iostream>
#include <cstdio>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Funtal/Log.h"

#ifdef FT_PLATFORM_MACOS
    #ifdef FT_DYNAMIC_LINK
        #ifdef FT_BUILD_DLL
            #define FUNTAL_API __attribute(( visibility("default") ))
        #else
            #define FUNTAL_API __attribute(( visibility("default") ))
        #endif
    #else
        #define FUNTAL_API
    #endif

#elif FT_PLATFORM_WINDOWS
    #include <Windows.h>
    #ifdef FT_DYNAMIC_LINK
        #ifdef FT_BUILD_DLL
            #define FUNTAL_API __declspec(dllimport)
        #else
            #define FUNTAL_API __declspec(dllexport)
        #endif
    #else
        #define FUNTAL_API
    #endif

#elif FT_PLATFORM_UNIX
    #ifdef FT_DYNAMIC_LINK
        #ifdef FT_BUILD_DLL
            #define FUNTAL_API __attribute(( visibility("default") ))
        #else
            #define FUNTAL_API __attribute(( visibility("default") ))
        #endif
    #else
        #define FUNTAL_API
    #endif
#else
    #error Funtal UNSUPPORTED Platform, sorry!
#endif

#define BIT(x) ( 1 << (x) )