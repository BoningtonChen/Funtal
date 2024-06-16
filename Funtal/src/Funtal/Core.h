#pragma once

#ifdef FT_PLATFORM_WINDOWS
	#ifdef FT_BUILD_DLL
		#define FUNTAL_API __declspec(dllexport)
	#else
		#define FUNTAL_API __declspec(dllimport)
	#endif
#else
	#error Funtal now only supports WINDOWS! 
#endif

