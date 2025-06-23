#pragma once
#include <memory>

#include "Core.h"

namespace Shmeckle
{
	class Event;
	class WindowCloseEvent;
	class WindowResizeEvent;
	class MouseButtonPressedEvent;
	class MouseButtonReleasedEvent;
	class MouseMovedEvent;
	class KeyPressedEvent;
	class KeyReleasedEvent;
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
		bool OnEvent(Event& event);

		bool OnWindowCloseEvent(WindowCloseEvent& event);
		bool OnWindowResizeEvent(WindowResizeEvent& event);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);

		std::unique_ptr<Window> window_;
		bool running_{ true };
	};

	// Needs to be defined in client
	std::unique_ptr<Application> CreateApplication();

}
