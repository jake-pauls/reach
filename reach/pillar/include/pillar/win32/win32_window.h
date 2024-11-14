#pragma once

typedef struct Win32Window 
{
	HWND hwnd;
	HINSTANCE h_instance;
	i32 n_cmd_show;
	LPVOID lp_param;
} Win32Window;

typedef struct Win32WindowDesc
{
	const wchar_t* const class_name;
	const LONG width;
	const LONG height;
} Win32WindowDesc;

/// @brief Initializes a Win32 window.
/// @param window Pointer to the window struct for the window instance being created
/// @param desc Descriptor struct containing the information for the window
void win32_window_create(Win32Window* const window, const Win32WindowDesc* const desc);

/// @brief Displays a Win32 window on the screen.
/// @param window Pointer to the window struct for the window instance being shown
void win32_window_show(const Win32Window* const window);

/// @brief Peeks the next message in the command queue.
/// @param msg Reference to a message to peek, translate, and dispatch
void win32_window_peek(LPMSG msg);

/// @brief Destroys the active window.
/// @param window Pointer to the window struct for the window instance being destroyed
/// @param title The title/class name for
void win32_window_destroy(Win32Window* const window, const wchar_t* const class_name);

/// @brief De facto window proc for the Win32Window
LRESULT CALLBACK win32_window_wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
