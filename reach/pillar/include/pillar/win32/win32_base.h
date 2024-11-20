#pragma once

#include <windows.h>

/// @brief Bootstraps an application in a Win32 window.
/// @param h_instance Handle for the currently running instance
/// @param n_cmd_show Display code for the window being spawned
/// @param lifecycle_hook Collection of function pointers that are called throughout the engine's lifecycle
i32 win32_base_bootstrap(HINSTANCE h_instance, i32 n_cmd_show, struct PillarAppLifecycleHook* lifecycle_hook);