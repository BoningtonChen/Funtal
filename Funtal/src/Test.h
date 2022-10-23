//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_TEST_H
#define FUNTAL_TEST_H

#endif //FUNTAL_TEST_H
#pragma once

#include <iostream>
#include <cstdio>

#ifdef __cplusplus
extern "C"
{
#endif
    #include <stdio.h>
#ifdef __cplusplus
}
#endif

namespace Funtal
{
    __attribute(( visibility("default") )) __declspec(dllexport) void Print();
}
