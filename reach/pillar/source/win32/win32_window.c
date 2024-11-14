#include "PCH.h"
#include "win32/win32_window.h"

#include "pillar_app.h"

void win32_window_create(Win32Window* const window, const Win32WindowDesc* const desc)
{
	const WNDCLASS window_class = {
		.lpfnWndProc = win32_window_wndproc,
		.hInstance = window->h_instance,
		.lpszClassName = desc->class_name
	};

	RegisterClass(&window_class);

	RECT window_rect = {
		.bottom = desc->width,
		.left = 0,
		.right = desc->height,
		.top = 0,
	};
	AdjustWindowRect(&window_rect, WS_OVERLAPPEDWINDOW, FALSE);

	window->hwnd = CreateWindowEx(0,
		desc->class_name,
		desc->class_name,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		desc->width,
		desc->height,
		NULL,
		NULL,
		window->h_instance,
		window->lp_param);
}

void win32_window_show(const Win32Window* const window)
{
	ShowWindow(window->hwnd, window->n_cmd_show);
}

void win32_window_peek(LPMSG msg)
{
	if (PeekMessage(msg, NULL, 0, 0, PM_REMOVE))
	{ 
		TranslateMessage(msg);
		DispatchMessage(msg);
	}
}

void win32_window_destroy(Win32Window* const window, const wchar_t* const class_name)
{
	DestroyWindow(window->hwnd);
	window->hwnd = NULL;

	UnregisterClass(class_name, window->h_instance);
	window->h_instance = NULL;
}

LRESULT CALLBACK win32_window_wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	PillarApp* app = (PillarApp*)(GetWindowLongPtr(hwnd, GWLP_USERDATA));

	switch (message)
	{
	case WM_CREATE:
	{
		LPCREATESTRUCT create_struct = (LPCREATESTRUCT)lparam;
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)create_struct->lpCreateParams);
		break;
	}
	case WM_PAINT:
	{
		if (app)
		{
			app->lifecycle_hook->update();
		}
		break;
	} 
	case WM_DESTROY:
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default:
	{
		// Handle other window events if we don't do anything
		return DefWindowProc(hwnd, message, wparam, lparam);
	}
	}

	return 0;
}