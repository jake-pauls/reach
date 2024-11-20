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

/// @brief Initializes the pillar application.
void pillar_app_init();

/// @brief Update loop for the pillar application.
void pillar_app_update();

/// @brief Draw call for the pillar application.
/// @param pillar_app Pointer to the application. 
void pillar_app_draw(PillarApp* pillar_app);

/// @brief Destroys the pillar application.
void pillar_app_destroy();
