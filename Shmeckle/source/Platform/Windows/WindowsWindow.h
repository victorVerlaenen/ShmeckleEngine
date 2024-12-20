#pragma once
#include "Shmeckle/Window.h"
#include "GLFW/glfw3.h"

namespace shmeckle
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		void Update() override;

		inline virtual unsigned int GetWidth() const override { return m_Data.width; }
		inline virtual unsigned int GetHeight() const override { return m_Data.height; }

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		struct WindowData
		{
			unsigned int width;
			unsigned int height;
			std::string title;
			bool VSync;
		};

		virtual void Initialize(const WindowProperties& properties);
		virtual void CleanUp();

		GLFWwindow* m_Window{ nullptr };
		WindowData m_Data;
	};
}