#pragma once
#include "Shmeckle\Window.h"
//#include <GLFW\glfw3.h>

namespace Shmeckle
{

	class WindowsWindowGLFW : public Window
	{
	public:
		WindowsWindowGLFW(const std::string& title = "Untitled window", unsigned int width = 1280, unsigned int height = 720);
		virtual ~WindowsWindowGLFW();

		void Update() override;

		inline unsigned int GetWidth() const override { return data_.width; }
		inline unsigned int GetHeight() const override { return data_.height; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return data_.vSync; }

	private:
		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			bool vSync;

			WindowData(const std::string& title, unsigned int width, unsigned int height)
				:title{title},
				width{width},
				height{height},
				vSync{true}
			{

			}
		};

		WindowData data_;

		//GLFWwindow* pWindow_;
	};

}