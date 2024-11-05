#pragma once

#include <Windows.h>

namespace pillar
{
	class App;

	class Win32Base
	{
	public:
		Win32Base() = default;
		~Win32Base() = default;

		int Bootstrap(App* app, HINSTANCE hInstance, int nCmdShow) const;
	};
}