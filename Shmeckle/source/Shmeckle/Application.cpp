#include "smpch.h"
#include "Application.h"

#include "Logger.h"
#include "Window.h"

#include "Events\Event.h"
#include "Events\ApplicationEvents.h"
#include "Events\MouseEvents.h"
#include "Events\KeyEvents.h"

#include "GLFW\glfw3.h"

#define DISABLE_VLD
#if !defined(DISABLE_VLD)
	#ifdef VLD_AVAILABLE
		#include <vld.h>
	#endif // VLD_AVAILABLE
#endif // DISABLE_VLD

namespace shmeckle
{
	Application::Application()
	{
		EventBus::Initialize();

		m_upWindow = Window::Create();

		EventBus::Instance().RegisterListener<MouseButtonPressedEvent>([this](MouseButtonPressedEvent& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener<WindowResizeEvent>([this](WindowResizeEvent& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener<WindowCloseEvent>([this](WindowCloseEvent& event)
		{
			OnWindowClose(event);
		});

		EventBus::Instance().RegisterListener<MouseButtonReleasedEvent>([this](MouseButtonReleasedEvent& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener<MouseScrolledEvent>([this](MouseScrolledEvent& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener<MouseMovedEvent>([this](MouseMovedEvent& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener<KeyPressedEvent>([this](KeyPressedEvent& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener<KeyReleasedEvent>([this](KeyReleasedEvent& event)
		{
			OnEvent(event);
		});
	}

	Application::~Application()
	{
		EventBus::CleanUp();
	}

	void Application::Run()
	{
		m_IsRunning = true;

		while (m_IsRunning)
		{
			EventBus::Instance().DispatchEvents();

			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_upWindow->Update();
		}
	}

	void Application::OnEvent(Event& event)
	{
		Logger::CoreInfo("{0}", event);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_IsRunning = false;
		return true;
	}
}
