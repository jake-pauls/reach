#pragma once

typedef struct DX11Renderer 
{
	void* _;
} DX11Renderer;

/// @brief Draw loop for the DX11Renderer.
/// @param renderer Pointer to the DX11Renderer
void dx11_renderer_draw(DX11Renderer* renderer);
