#pragma once
#include "Core.h"
#include <memory>

#include "Layers\LayerStack.h"

namespace shmeckle
{
	class Window;

	class Event;
	class WindowCloseEvent;
	
	class Layer;

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

		void PushLayer(Layer* layer);
		void PushOverlayLayer(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_upWindow{ nullptr };
		bool m_IsRunning{ false };
		LayerStack m_LayerStack;
	};

	// To be defined in the CLIENT
	Application* CreateApplication();
}

