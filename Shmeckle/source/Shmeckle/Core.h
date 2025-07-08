#pragma once

#ifdef SHM_BUILD_DLL
	#define SHM_API __declspec(dllexport)
#else
	#define SHM_API __declspec(dllimport)
#endif

constexpr int Bit(int x)
{
	return 1 << x;
}