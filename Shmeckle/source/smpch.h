#pragma once

// Platform specific includes
#ifdef SHMECKLE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // SHMECKLE_PLATFORM_WINDOWS

// Data structures
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// Common other includes
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

// Shmeckle includes
#include "Shmeckle\Logger.h"