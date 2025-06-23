#pragma once
#include <Windows.h>
#include <string>

#include "Core.h"

namespace Shmeckle
{

	class Window
	{
	public:
		SHM_API Window(const std::string& title = "Untitled window", unsigned int width = 1280, unsigned int height = 720);
		SHM_API ~Window();

		Window(const Window& other) = delete;
		Window(Window&& other) = delete;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) = delete;

		SHM_API void ProcessMessages();

		SHM_API inline unsigned int GetWidth() const { return width_; }
		SHM_API inline unsigned int GetHeight() const { return height_; }

		SHM_API void SetVSync(bool enabled);
		SHM_API bool IsVSync() const;

	private:
		void RegisterWindowClassEx(LPCWSTR ClassName) const;
		void MakeWindow();

		static LRESULT CALLBACK WindowProc(HWND hWindow, UINT uMessage, WPARAM wParameter, LPARAM lParameter);
		LRESULT HandleMessage(UINT uMessage, WPARAM wParameter, LPARAM lParameter);

		HINSTANCE hInstance_;	// Handle to the application instance (used for registration and window creation)
		HWND hWindow_;			// Handle to the created window

		static constexpr const wchar_t* CLASS_NAME_ = L"Shmeckle window"; // Name used for the window class
		unsigned int width_;
		unsigned int height_;
		const std::wstring title_;
	};

}