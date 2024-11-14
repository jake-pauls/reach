#pragma once

#include <windows.h>

/// @brief Bootstraps an application in a Win32 window.
/// @param app Pointer to the application instance.
/// @param h_instance Handle for the currently running instance.
/// @param n_cmd_show Display code for the window being spawned.
i32 win32_base_bootstrap(HINSTANCE h_instance, i32 n_cmd_show);