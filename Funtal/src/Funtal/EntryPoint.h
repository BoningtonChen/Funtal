#pragma once
#include <cstdio>


#ifdef FT_PLATFORM_WINDOWS

extern Funtal::Application* Funtal::CreateApplication();

int main(int argc, char** argv)
{
	Funtal::Log::Init();
	FT_CORE_WARN("Initialized Log!");
	// Test variable passed in 
	int variable = 5;
	FT_INFO("Hello! Var={0}.", variable);

	printf("Welcome to Funtal Engine!\n");
	auto app = Funtal::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#endif
