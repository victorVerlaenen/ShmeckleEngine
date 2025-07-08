#pragma once
#include <memory>

#include "Core.h"
#include "LayerStack.h"
#include "Window.h"

namespace Shmeckle
{
	class WindowCloseEvent;

	class Application
	{
	public:
		SHM_API Application();
		SHM_API virtual ~Application() = default;

		Application(const Application& other) = delete;
		Application(Application&& other) = delete;
		Application& operator=(const Application& other) = delete;
		Application& operator=(Application&& other) = delete;

		SHM_API void Run();
		SHM_API void PushLayer(std::unique_ptr<Layer> layer);
		SHM_API void PushOverlayLayer(std::unique_ptr<Layer> layer);

	protected:
		bool OnWindowCloseEvent(WindowCloseEvent& event);

		std::unique_ptr<Window> window_;
		bool running_{ true };
		LayerStack layerStack_;
	};

	// Needs to be defined in client
	std::unique_ptr<Application> CreateApplication();

}
