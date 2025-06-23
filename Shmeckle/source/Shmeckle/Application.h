#pragma once
#include <memory>

#include "Core.h"

namespace Shmeckle
{
	class Event;
	class WindowCloseEvent;
	class WindowResizeEvent;
	class Window;

	class Application
	{
	public:
		SHM_API Application();
		SHM_API virtual ~Application();

		Application(const Application& other) = delete;
		Application(Application&& other) = delete;
		Application& operator=(const Application& other) = delete;
		Application& operator=(Application&& other) = delete;

		SHM_API void Run();

	protected:
		bool OnWindowCloseEvent(WindowCloseEvent& event);
		bool OnWindowResizeEvent(WindowResizeEvent& event);

		std::unique_ptr<Window> window_;
		bool running_{ true };
	};

	// Needs to be defined in client
	std::unique_ptr<Application> CreateApplication();

}
