#pragma once
#include "Core.h"
#include <memory>

namespace shmeckle
{
	class Event;
	class WindowCloseEvent;
	class Window;

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
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_upWindow{ nullptr };
		bool m_IsRunning{ false };
	};

	// To be defined in the CLIENT
	Application* CreateApplication();
}

