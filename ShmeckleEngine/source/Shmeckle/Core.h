#pragma once

#ifdef SM_PLATFORM_WINDOWS
	#ifdef SM_BUILD_DLL
		#define SHMECKLE_API __declspec(dllexport)
	#else 
		#define SHMECKLE_API __declspec(dllimport)
	#endif
#else
	#error Shmeckle only supports windows
#endif