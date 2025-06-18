#pragma once
#include <memory>

#include "Core.h"

namespace Shmeckle
{

	class SHM_API Application
	{
	public:
		Application();
		virtual ~Application();

		Application(const Application& other) = delete;
		Application(Application&& other) = delete;
		Application& operator=(const Application& other) = delete;
		Application& operator=(Application&& other) = delete;

		void Run();
	};

	// Needs to be defined in client
	std::unique_ptr<Application> CreateApplication();

}
