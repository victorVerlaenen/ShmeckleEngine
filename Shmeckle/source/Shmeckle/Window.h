#pragma once

#include "smpch.h"
#include "Core.h"
#include "Events/Event.h"

namespace shmeckle
{
	struct WindowProperties
	{
		WindowProperties(const std::string& title = "Shmeckle", unsigned int width = 1280, unsigned int height = 720)
			:title{ title }
			, width{ width }
			, height{ height }
		{

		}

		unsigned int width;
		unsigned int height;
		std::string title;
	};

	class SHMECKLE_API Window
	{
	public:
		virtual ~Window() = default;

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static std::unique_ptr<Window> Create(const WindowProperties& properties = WindowProperties());
	protected:
		Window() = default;

		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;
		Window(Window&& other) = delete;
		Window& operator=(Window&& other) = delete;

		static bool sm_GLFWInitialized;
	};
}