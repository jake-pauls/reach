#pragma once

typedef struct Win32Window {
	HWND hwnd;
	HINSTANCE h_instance;
	i32 n_cmd_show;
} Win32Window;

/// @brief Initializes a Win32 window.
/// @param window Pointer to the window struct for the window instance being created
/// @param class_name Class name for the window being created, used when registering the window
/// @param width The width of the window being created
/// @param height The height of the window being created
void win32_window_create(Win32Window* const window, const wchar_t* const class_name, const LONG width, const LONG height);

/// @brief Displays a Win32 window on the screen.
/// @param window Pointer to the window struct for the window instance being shown
void win32_window_show(const Win32Window* const window);

/// @brief Peeks the next message in the command queue.
/// @param msg Reference to a message to peek, translate, and dispatch
void win32_window_peek(LPMSG msg);

/// @brief Destroys the active window.
/// @param window Pointer to the window struct for the window instance being torn down
/// @param title The title/class name for
void win32_window_teardown(Win32Window* const window, const wchar_t* const title);

/// @brief De facto window proc for the Win32Window
LRESULT CALLBACK win32_window_wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
