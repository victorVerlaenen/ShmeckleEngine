#pragma once
#include "Core.h"

namespace Shmeckle
{

	class SHM_API Application
	{
	public:
		Application() noexcept;
		virtual ~Application();

		void Run();
	};

	// Needs to be defined in client
	Application* CreateApplication();
}
