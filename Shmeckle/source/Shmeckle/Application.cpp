#include "smpch.h"
#include "Application.h"

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

		EventBus::Instance().RegisterListener<WindowCloseEvent>([this](WindowCloseEvent& event)
		{
			OnWindowClose(event);
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

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlayLayer(Layer* layer)
	{
		m_LayerStack.PushOverlayLayer(layer);
	}
}
