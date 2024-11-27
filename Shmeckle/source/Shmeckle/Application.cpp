#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Logger.h"

namespace shmeckle
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			Logger::CoreInfo(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			Logger::CoreInfo(e.ToString());
		}
		while (true);
	}
}
