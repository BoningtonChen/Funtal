//
// Created by 陈奕锟 on 2022/10/23.
//

namespace Funtal
{
    __attribute(( visibility("default") )) __declspec(dllimport) void Print();
}

int main()
{
    Funtal::Print();
}