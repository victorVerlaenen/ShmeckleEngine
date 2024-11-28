#include "smpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Logger.h"

namespace shmeckle
{
	Application::Application()
	{
		m_Window = Window::Create();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		m_IsRunning = true;

		/*WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			Logger::CoreInfo(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			Logger::CoreInfo(e.ToString());
		}*/

		while (m_IsRunning)
		{
			m_Window->Update();
		}
	}
}
