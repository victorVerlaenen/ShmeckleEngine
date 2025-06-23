#include "shmpch.h"

#include "Application.h"
#include "Events\Event.h"
#include "Events\WindowEvent.h"
#include "Logger.h"
#include "Window.h"

namespace Shmeckle
{

	Application::Application()
	{
		Logger::Initialize();
		EventBus::Initialize(); // This should probably happen somewhere else
		window_ = std::make_unique<Window>("Shmeckle");

		EventBus::Instance().Subscribe<WindowCloseEvent>([this](WindowCloseEvent& event) { return OnWindowCloseEvent(event); }, 0);
		EventBus::Instance().Subscribe<WindowResizeEvent>([this](WindowResizeEvent& event) { return OnWindowResizeEvent(event); }, 0);
	}

	Application::~Application()
	{
		EventBus::CleanUp();
	}

	void Application::Run()
	{
		while (running_)
		{
			window_->ProcessMessages();
			EventBus::Instance().DispatchAll(); // TODO: move to a beter location maybe?
		}
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& event)
	{
		Logger::TraceCore("{}", event.ToString());
		running_ = false;

		return true;
	}

	bool Application::OnWindowResizeEvent(WindowResizeEvent& event)
	{
		Logger::TraceCore("{}", event.ToString());

		return false;
	}

}