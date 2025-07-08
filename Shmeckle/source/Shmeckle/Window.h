#pragma once
#include <memory>
#include <string>

#include "Core.h"

namespace Shmeckle
{

	class SHM_API Window
	{
	public:
		virtual ~Window() = default;

		Window(const Window& other) = delete;
		Window(Window&& other) = delete;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) = delete;

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static std::unique_ptr<Window> Create(const std::string& title = "Untitled window", unsigned int width = 1280, unsigned int height = 720);

	protected:
		Window() = default;
	};

}