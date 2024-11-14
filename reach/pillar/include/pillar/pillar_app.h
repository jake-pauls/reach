#pragma once

typedef struct PillarApp 
{
#ifdef WIN32
	struct DX11Renderer* dx11_renderer;
#endif
	struct PillarAppLifecycleHook* lifecycle_hook;
} PillarApp;

typedef struct PillarAppLifecycleHook 
{
	void (*init)();
	void (*update)();
	void (*destroy)();
} PillarAppLifecycleHook;

void pillar_app_init();
void pillar_app_update();
void pillar_app_draw(PillarApp* pillar_app);
void pillar_app_destroy();
