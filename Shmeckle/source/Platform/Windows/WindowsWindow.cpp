#include "smpch.h"
#include "WindowsWindow.h"
#include "Shmeckle/Logger.h"
#include "Shmeckle/Events/ApplicationEvents.h"
#include "Shmeckle/Events/KeyEvents.h"
#include "Shmeckle/Events/MouseEvents.h"

namespace shmeckle
{
	bool Window::sm_GLFWInitialized{ false };

	// Platform specific implementation that created the correct window
	std::unique_ptr<Window> Window::Create(const WindowProperties& properties)
	{
		// This implicitly moves because it is a temporary object and those are implicitly rvalues
		return std::make_unique<WindowsWindow>(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		Initialize(properties);
	}

	void WindowsWindow::Initialize(const WindowProperties& properties)
	{
		m_Data.title = properties.title;
		m_Data.width = properties.width;
		m_Data.height = properties.height;

		Logger::CoreInfo("Creating window {0} ({1}, {2})", properties.title, properties.width, properties.height);

		if (!sm_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			//HZ_CORE_ASSERT(success, "Could not initialize GLFW!");

			glfwSetErrorCallback([](int error, const char* description)
			{
				Logger::CoreError("GLFW error ({0}): {1}", error, description);
			});

			sm_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)properties.width, (int)properties.height, m_Data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			EventBus::Instance().QueueEvent(std::move(std::make_unique<WindowResizeEvent>(static_cast<unsigned int>(width), static_cast<unsigned int>(height))));
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			EventBus::Instance().QueueEvent(std::move(std::make_unique<WindowCloseEvent>()));
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			EventBus& eventBus = EventBus::Instance();
			switch (action)
			{
			case GLFW_PRESS:
			{
				eventBus.QueueEvent(std::move(std::make_unique<KeyPressedEvent>(key, false)));
				break;
			}
			case GLFW_RELEASE:
			{
				eventBus.QueueEvent(std::move(std::make_unique<KeyReleasedEvent>(key)));
				break;
			}
			case GLFW_REPEAT:
			{
				eventBus.QueueEvent(std::move(std::make_unique<KeyPressedEvent>(key, true)));
				break;
			}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			EventBus& eventBus = EventBus::Instance();
			switch (action)
			{
			case GLFW_PRESS:
			{
				eventBus.QueueEvent(std::move(std::make_unique<MouseButtonPressedEvent>(button)));
				break;
			}
			case GLFW_RELEASE:
			{
				eventBus.QueueEvent(std::move(std::make_unique<MouseButtonReleasedEvent>(button)));
				break;
			}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			EventBus::Instance().QueueEvent(std::move(std::make_unique<MouseScrolledEvent>(xOffset, yOffset)));
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			EventBus::Instance().QueueEvent(std::move(std::make_unique<MouseMovedEvent>(xPos, yPos)));
		});
	}

	WindowsWindow::~WindowsWindow()
	{
		CleanUp();
	}

	void WindowsWindow::CleanUp()
	{
		glfwDestroyWindow(m_Window);

		// Need this to not have memory leaks
		//glfwTerminate();
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		m_Data.VSync = enabled;

		if (enabled)
		{
			glfwSwapInterval(1);
			return;
		}

		glfwSwapInterval(0);
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}