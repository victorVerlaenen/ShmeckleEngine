#include "smpch.h"
#include "Application.h"

#include "Logger.h"
#include "Window.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "GLFW\glfw3.h"

namespace shmeckle
{
	Application::Application()
	{
		m_Window = Window::Create();
		m_Window->SetEventCallback([this](Event& event) 
		{
			OnEvent(event);
		});
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		m_IsRunning = true;

		while (m_IsRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->Update();
		}
	}

	void Application::OnEvent(Event& event)
	{
		Logger::CoreInfo("{0}", event);
	}

}
