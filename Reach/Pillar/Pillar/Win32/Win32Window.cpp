#include "PCH.h"
#include "Win32/Win32Window.h"

#include "Pillar/App.h"

namespace
{
	HINSTANCE HInstance;
	wchar_t const* WindowClassName = TEXT("Reach - DirectX11");

	const u32 ViewportWidth = 800;
	const u32 ViewportHeight = 600;
}

void pillar::Win32Window::Init(App* app, HINSTANCE hInstance, i32 nCmdShow)
{
	HInstance = hInstance;

	WNDCLASS windowClass = {};
	windowClass.lpfnWndProc = WindowProc;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = WindowClassName;

	RegisterClass(&windowClass);

	RECT windowRect = { 0, 0, static_cast<LONG>(ViewportWidth), static_cast<LONG>(ViewportHeight) };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	m_Hwnd = CreateWindowEx(0,
		WindowClassName,
		WindowClassName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		NULL,
		NULL,
		hInstance,
		app);

	ShowWindow(m_Hwnd, nCmdShow);
}

void pillar::Win32Window::Peek(LPMSG msg) const
{
	if (PeekMessage(msg, NULL, 0, 0, PM_REMOVE))
	{ 
		TranslateMessage(msg);
		DispatchMessage(msg);
	}
}

void pillar::Win32Window::Teardown()
{
	DestroyWindow(m_Hwnd);
	m_Hwnd = nullptr;

	UnregisterClass(WindowClassName, HInstance);
	HInstance = nullptr;
}

LRESULT CALLBACK pillar::Win32Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	App* app = reinterpret_cast<App*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	switch (message)
	{
	case WM_CREATE:
	{
		LPCREATESTRUCT createStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(createStruct->lpCreateParams));
	}
	break;
	case WM_PAINT:
	{
		if (!app)
		{
			break;
		}

		app->Update();
		app->Draw();
	}
	break;
	case WM_DESTROY:
		[[fallthrough]];
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		// Handle other window events if we don't do anything
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}