#pragma once
#include "Core.h"
#include "Window.h"

namespace shmeckle
{
	class SHMECKLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		Application(const Application& other) = delete;
		Application& operator=(const Application& other) = delete;
		Application(Application&& other) = delete;
		Application& operator=(Application&& other) = delete;

		void Run();

	private:
		std::unique_ptr<Window> m_Window{ nullptr };
		bool m_IsRunning{ false };
	};

	// To be defined in the CLIENT
	Application* CreateApplication();
}

