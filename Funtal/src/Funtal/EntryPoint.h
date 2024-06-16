#pragma once
#include <cstdio>

#include "../Funtal.h"

#ifdef FT_PLATFORM_WINDOWS

extern Funtal::Application* Funtal::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to Funtal Engine!\n");
	auto app = Funtal::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#endif
