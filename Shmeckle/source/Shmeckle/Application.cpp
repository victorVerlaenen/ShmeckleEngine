#include "Application.h"
#include "Events\Event.h"

namespace Shmeckle
{

	Application::Application()
	{
		EventBus::Initialize();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			EventBus::Instance().DispatchEvents();
		}
	}

}