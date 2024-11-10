#include "PCH.h"
#include "Win32/Win32Base.h"

#include "Pillar/App.h"
#include "Win32/Win32Window.h"

i32 pillar::Win32Base::Bootstrap(App* app, HINSTANCE hInstance, i32 nCmdShow) const
{
	Win32Window* window = new Win32Window();

	window->Init(app, hInstance, nCmdShow);
	app->Init();

	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		window->Peek(&msg);
	}

	app->Teardown();
	window->Teardown();

	delete window;

	return static_cast<i32>(msg.wParam);
}