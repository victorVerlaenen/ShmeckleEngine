#include "shmpch.h"

#include "Application.h"
#include "Window.h"
#include "Logger.h"

#include "Events\Event.h"
#include "Events\WindowEvent.h"
#include "Events\MouseEvent.h"
#include "Events\KeyEvent.h"

namespace Shmeckle
{

	Application::Application()
	{
		Logger::Initialize();
		EventBus::Initialize(); // This should probably happen somewhere else
		window_ = std::make_unique<Window>("Shmeckle");

		EventBus::Instance().Subscribe<WindowCloseEvent>([this](WindowCloseEvent& event) { return OnWindowCloseEvent(event); }, 0);
		EventBus::Instance().Subscribe<WindowResizeEvent>([this](WindowResizeEvent& event) { return OnEvent(event); }, 0);
		EventBus::Instance().Subscribe<MouseButtonPressedEvent>([this](MouseButtonPressedEvent& event) { return OnEvent(event); }, 0);
		EventBus::Instance().Subscribe<MouseButtonReleasedEvent>([this](MouseButtonReleasedEvent& event) { return OnEvent(event); }, 0);
		EventBus::Instance().Subscribe<KeyPressedEvent>([this](KeyPressedEvent& event) { return OnEvent(event); }, 0);
		EventBus::Instance().Subscribe<KeyReleasedEvent>([this](KeyReleasedEvent& event) { return OnEvent(event); }, 0);
		//EventBus::Instance().Subscribe<MouseMovedEvent>([this](MouseMovedEvent& event) { return OnEvent(event); }, 0);
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
		running_ = false;

		return OnEvent(event);
	}

	bool Application::OnEvent(Event& event)
	{
		Logger::TraceCore("{}", event.ToString());
		return false;
	}

}