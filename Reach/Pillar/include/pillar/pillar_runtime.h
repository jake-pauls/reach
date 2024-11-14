#pragma once

struct DX11Renderer;

void pillar_runtime_init();
void pillar_runtime_update();
void pillar_runtime_draw(struct DX11Renderer* renderer);
void pillar_runtime_teardown();
