#include "smpch.h"
#include "Application.h"

#include "Logger.h"
#include "Window.h"

#include "Events/Event.h"

#include "GLFW\glfw3.h"

namespace shmeckle
{
	Application::Application()
	{
		EventBus::Initialize();

		m_upWindow = Window::Create();
		/*m_upWindow->SetEventCallback([this](Event& event) 
		{
			OnEvent(event);
		});*/

		EventBus::Instance().RegisterListener(Event::Type::MouseButtonPressed, [this](Event& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener(Event::Type::WindowResized, [this](Event& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener(Event::Type::WindowClosed, [this](Event& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener(Event::Type::MouseButtonReleased, [this](Event& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener(Event::Type::MouseScrolled, [this](Event& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener(Event::Type::MouseMoved, [this](Event& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener(Event::Type::KeyPressed, [this](Event& event)
		{
			OnEvent(event);
		});

		EventBus::Instance().RegisterListener(Event::Type::KeyReleased, [this](Event& event)
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

}
