#include "shmpch.h"

#include "Application.h"
#include "Window.h"
#include "Logger.h"

#include "Events\Event.h"
#include "Events\WindowEvent.h"

#include "CoreSystemsLayer.h"

namespace Shmeckle
{

	Application::Application()
	{
		layerStack_.PushLayer(std::make_unique<CoreSystemsLayer>());

		window_ = std::unique_ptr<Window>(Window::Create());

		EventBus::Instance().Subscribe<WindowCloseEvent>([this](WindowCloseEvent& event) { return OnWindowCloseEvent(event); }, 0);
	}

	void Application::Run()
	{
		while (running_)
		{
			window_->Update();
			for (auto& layer : layerStack_)
			{
				layer->Update();
			}
		}
	}

	void Application::PushLayer(std::unique_ptr<Layer> layer)
	{
		layerStack_.PushLayer(std::move(layer));
	}

	void Application::PushOverlayLayer(std::unique_ptr<Layer> layer)
	{
		layerStack_.PushOverlayLayer(std::move(layer));
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& event)
	{
		// Unused param
		(void)event;

		running_ = false;

		return true;
	}

}