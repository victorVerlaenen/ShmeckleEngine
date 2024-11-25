#pragma once

#ifdef SMECKLE_PLATFORM_WINDOWS
	#ifdef SMECKLE_BUILD_DLL
		#define SHMECKLE_API __declspec(dllexport)
	#else 
		#define SHMECKLE_API __declspec(dllimport)
	#endif
#else
	#error Shmeckle only supports windows
#endif