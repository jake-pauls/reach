#include "PCH.h"
#include "pillar_runtime.h"

#ifdef WIN32
#include "win32/win32_window.h"
#include "dx11/dx11_renderer.h"
#endif

void pillar_runtime_init()
{
}

void pillar_runtime_update()
{
}

void pillar_runtime_draw(DX11Renderer* renderer)
{
	dx11_renderer_draw(renderer);
}

void pillar_runtime_teardown()
{
}
