#pragma once

#ifdef SHMECKLE_PLATFORM_WINDOWS
	#ifdef SHMECKLE_BUILD_DLL
		#define SHMECKLE_API __declspec(dllexport)
	#else 
		#define SHMECKLE_API __declspec(dllimport)
	#endif // SHMECKLE_BUILD_DLL
#else
	#error Shmeckle only supports windows
#endif // SHMECKLE_PLATFORM_WINDOWS

constexpr int Bit(int x) {
	return 1 << x;
}