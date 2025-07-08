#include "shmpch.h"
#include "WindowsWindowGLFW.h"
#include "Shmeckle\Logger.h"

namespace Shmeckle
{
	static bool sGLFWInitialized = false;

	#ifdef SHM_USE_GLFW

	std::unique_ptr<Window> Window::Create(const std::string& title, unsigned int width, unsigned int height)
	{
		return std::make_unique<WindowsWindowGLFW>(title, width, height);
	}

	#endif // SHM_USE_GLFW

	Shmeckle::WindowsWindowGLFW::WindowsWindowGLFW(const std::string& title, unsigned int width, unsigned int height)
		:data_{ title, width, height }
	{
		//Logger::InfoCore("Creating GLFW window {} ({}, {})", data_.title, data_.width, data_.height);

		if (!sGLFWInitialized)
		{
			//int result = glfwInit();
			//if (!result)
			{
				//Logger::ErrorCore("Could not initialize GLFW");
			}
			sGLFWInitialized = true;
		}

		//pWindow_ = glfwCreateWindow(data_.width, data_.height, data_.title.c_str(), nullptr, nullptr);
		//glfwMakeContextCurrent(pWindow_);
		//glfwSetWindowUserPointer(pWindow_, &data_);
		SetVSync(true);
	}

	Shmeckle::WindowsWindowGLFW::~WindowsWindowGLFW()
	{
		//glfwDestroyWindow(pWindow_);
	}

	void Shmeckle::WindowsWindowGLFW::Update()
	{
		//glfwPollEvents();
		//glfwSwapBuffers(pWindow_);
	}

	void Shmeckle::WindowsWindowGLFW::SetVSync(bool enabled)
	{
		//glfwSwapInterval(enabled);

		data_.vSync = enabled;
	}

}