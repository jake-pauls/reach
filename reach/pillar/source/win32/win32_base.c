#include "PCH.h"
#include "win32/win32_base.h"

#include "pillar_runtime.h"
#include "win32/win32_window.h"

i32 win32_base_bootstrap(HINSTANCE h_instance, i32 n_cmd_show)
{
	Win32Window window = {
		.hwnd = NULL,
		.h_instance = h_instance,
		.n_cmd_show = n_cmd_show,
	};

	const wchar_t* const class_name = TEXT("Reach - DirectX 11");
	const LONG width = 800;
	const LONG height = 600;

	win32_window_create(&window, class_name, width, height);
	pillar_runtime_init();

	win32_window_show(&window);

	MSG msg = { NULL };
	while (msg.message != WM_QUIT)
	{
		win32_window_peek(&msg);
	}

	pillar_runtime_teardown();
	win32_window_teardown(&window, class_name);

	return (i32)msg.wParam;
}