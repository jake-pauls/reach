#include "PCH.h"
#include "pillar/pillar_base.h"

#include "pillar/pillar_app.h"

#include <SDL3/SDL.h>

static const char* window_name = "Reach - DirectX11";
static const i32 window_width = 640;
static const i32 window_height = 480;

i32 pillar_base_bootstrap(PillarAppLifecycleHook* lifecycle_hook)
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        RERROR("[SDL_Init] %s", SDL_GetError());
        return 1;
    }

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
    SDL_Window* window = SDL_CreateWindow(window_name, window_width, window_height, window_flags);
    if (window == NULL)
    {
        RERROR("[SDL_CreateWindow] %s", SDL_GetError());
        return 1;
    }

#ifdef WIN32
    // https://github.com/libsdl-org/SDL/blob/main/docs/README-migration.md#sdl_syswmh
    HWND hwnd = (HWND)SDL_GetPointerProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_WIN32_HWND_POINTER, NULL);
    if (hwnd == NULL) 
    {
        RERROR("[SDL_GetWindowProperties] %s", SDL_GetError());
        return 1;
    }
#endif

    PillarApp app = {
        .dx11_renderer = NULL,
        .lifecycle_hook = lifecycle_hook,
    };

    app.lifecycle_hook->init();

    bool is_running = true;
    while (is_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                is_running = false;
            }
        }

        app.lifecycle_hook->update();
        pillar_app_draw(&app);
    }
    
    app.lifecycle_hook->destroy();

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}