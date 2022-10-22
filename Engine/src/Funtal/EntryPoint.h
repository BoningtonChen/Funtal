//
// Created by 陈奕锟 on 2022/10/16.
//

#ifndef FUNTAL_ENTRYPOINT_H
#define FUNTAL_ENTRYPOINT_H

#endif //FUNTAL_ENTRYPOINT_H
#pragma once

#ifdef FT_PLATFORM_MACOS

extern Funtal::Application* Funtal::CreateApplication();

int main(int argc, char** argv)
{
    std::cout << "Welcome to Funtal Engine. :)" << std::endl;
    auto app = Funtal::CreateApplication();
    app -> Run();
    delete app;
}

#else
    #error Funtal only support macOS FOR NOW !

#endif
