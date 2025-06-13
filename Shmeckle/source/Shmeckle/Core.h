#pragma once

#ifdef SM_PLATFORM_WINDOWS
	#ifdef SM_BUILD_DLL
		#define SM_API __declspec(dllexport)
	#else
		#define SM_API __declspec(dllimport)
	#endif
#else
	#error Smeckle only supports Windows!
#endif