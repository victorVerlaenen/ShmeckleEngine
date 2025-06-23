#include "shmpch.h"
#include "Window.h"
#include "Logger.h"
#include "Events\Event.h"
#include "Events\WindowEvent.h"

namespace Shmeckle
{

	Window::Window(const std::string& title, unsigned int width, unsigned int height)
		:hInstance_{ GetModuleHandle(nullptr) }	// Retrieve the instance handle of the current process
		, title_{ std::wstring{title.begin(), title.end()} }
		, width_{ width }
		, height_{ height }
	{
		Logger::WarningCore("Creating window {} ({}, {})", "title", width_, height_);

		RegisterWindowClassEx(CLASS_NAME_);
		MakeWindow();

		ShowWindow(hWindow_, SW_SHOW);
	}

	Window::~Window()
	{
		UnregisterClass(CLASS_NAME_, hInstance_);
	}

	void Window::ProcessMessages()
	{
		MSG message{};

		// Retrieve messages without blocking (non-blocking loop)
		while (PeekMessage(&message, nullptr, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&message);	// Translate keystrokes into characters
			DispatchMessage(&message);	// Send the message to the appropriate WindowProc
		}
	}

	LRESULT Window::WindowProc(HWND hWindow, UINT uMessage, WPARAM wParameter, LPARAM lParameter)
	{
		if (uMessage == WM_NCCREATE)
		{
			// During creation: store the pointer to the Window instance in user data
			CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParameter);
			Window* pWindow = static_cast<Window*>(pCreate->lpCreateParams);
			pWindow->hWindow_ = hWindow; // Store HWND in the Window class instance
			SetWindowLongPtr(hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
		}

		// Retrieve the Window instance from the window's user data
		Window* pWindow = reinterpret_cast<Window*>(GetWindowLongPtr(hWindow, GWLP_USERDATA));

		if (pWindow)
		{
			// Call the instance version of the message handler
			return pWindow->HandleMessage(uMessage, wParameter, lParameter);
		}

		return DefWindowProc(hWindow, uMessage, wParameter, lParameter);
	}

	LRESULT Window::HandleMessage(UINT uMessage, WPARAM wParameter, LPARAM lParameter)
	{
		switch (uMessage)
		{
		case WM_CLOSE:
			DestroyWindow(hWindow_);	// Destroy the window when the user clicks the close button
			EventBus::Instance().Dispatch(std::make_unique<WindowCloseEvent>());
			break;
		case WM_DESTROY:
			PostQuitMessage(0);			// Notify Windows that the application can quit
			return 0;
		case WM_SIZE:
			EventBus::Instance().Dispatch(std::make_unique<WindowResizeEvent>(LOWORD(lParameter), HIWORD(lParameter)));
			break;
		}

		return DefWindowProc(hWindow_, uMessage, wParameter, lParameter);
	}

	void Window::RegisterWindowClassEx(LPCWSTR ClassName) const
	{
		WNDCLASSEX windowClass = {};
		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW;					// Redraw on resize
		windowClass.cbClsExtra = NULL;									// No extra class data
		windowClass.cbWndExtra = sizeof(LONG_PTR);						// Reserve space for a pointer in the window's extra memory

		windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);			// Use the standard mouse cursor
		windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); /*(HBRUSH)GetStockObject(NULL_BRUSH); */// No background painting (engine will render everything)

		windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);				// Standard Windows logo as the icon
		windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);				// Small icon (e.g. in the taskbar)

		windowClass.lpszClassName = ClassName;							// Name of the window class
		windowClass.lpszMenuName = nullptr;								// No menu
		windowClass.hInstance = hInstance_;								// Instance handle of the application
		windowClass.lpfnWndProc = WindowProc;							// Callback function for handling messages (must be static)

		if (!RegisterClassEx(&windowClass))
		{
			MessageBox(NULL, L"Call to RegisterClassEx failed!", NULL, NULL);
			return;
		}
	}

	void Window::MakeWindow()
	{
		hWindow_ = CreateWindow(
			CLASS_NAME_,								// Class name (must match exactly with the registered name)
			title_.c_str(),									// Title that appears on the window's title bar
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_SIZEBOX,	// Window style
			CW_USEDEFAULT, CW_USEDEFAULT,				// Use default screen position
			width_, height_,							// Desired window size
			nullptr,									// No parent window
			nullptr,									// No menu
			hInstance_,									// Application instance handle
			this										// Pointer to this Window object (retrieved in WM_NCCREATE)
		);

		if (!hWindow_)
		{
			DWORD errorCode = GetLastError();
			wchar_t buffer[256];
			swprintf(buffer, 256, L"CreateWindow failed with error code %lu", errorCode);
			MessageBox(NULL, buffer, L"Error", MB_OK);
		}
	}

}