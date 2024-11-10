#pragma once

#include <windows.h>

namespace pillar
{
	class App;

	class Win32Base
	{
	public:
		Win32Base() = default;
		~Win32Base() = default;

		/// @brief Bootstraps an application in a Win32 window.
		/// @param app Pointer to the application instance.
		/// @param hInstance Handle for the currently running instance.
		/// @param nCmdShow Display code for the window being spawned.
		i32 Bootstrap(App* app, HINSTANCE hInstance, i32 nCmdShow) const;
	};
}