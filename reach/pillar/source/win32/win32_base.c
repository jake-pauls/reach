#include "PCH.h"
#include "pillar/win32/win32_base.h"

#include "pillar/pillar_app.h"
#include "pillar/win32/win32_window.h"

static const wchar_t* const window_class_name = TEXT("Reach - DX11");
static const LONG viewport_width = 640;
static const LONG viewport_height = 480;

i32 win32_base_bootstrap(HINSTANCE h_instance, i32 n_cmd_show, PillarAppLifecycleHook* lifecycle_hook)
{
	PillarApp pillar_app = {
		.dx11_renderer = NULL,
		.lifecycle_hook = lifecycle_hook,
	};

	Win32Window window = {
		.hwnd = NULL,
		.h_instance = h_instance,
		.n_cmd_show = n_cmd_show,
		.lp_param = &pillar_app,
	};

	Win32WindowDesc desc = {
		.class_name = window_class_name,
		.width = viewport_width,
		.height = viewport_height,
	};

	win32_window_create(&window, &desc);
	win32_window_show(&window);
	lifecycle_hook->init();

	MSG msg = { NULL };
	while (msg.message != WM_QUIT)
	{
		win32_window_peek(&msg);
	}

	lifecycle_hook->destroy();
	win32_window_destroy(&window, desc.class_name);

	return (i32)msg.wParam;
}