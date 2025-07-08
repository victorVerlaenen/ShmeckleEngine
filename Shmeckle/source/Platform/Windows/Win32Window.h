#pragma once
#include <Windows.h>
#include <string>
#include <memory>

#include "Shmeckle\Core.h"
#include "Shmeckle\Window.h"

namespace Shmeckle
{

	class Win32Window : public Window
	{
	public:
		Win32Window(const std::string& title = "Untitled window", unsigned int width = 1280, unsigned int height = 720);
		~Win32Window();

		void Update() override;

		inline unsigned int GetWidth() const override { return width_; }
		inline unsigned int GetHeight() const override { return height_; }

		void SetVSync(bool enabled);
		bool IsVSync() const { return false; }

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