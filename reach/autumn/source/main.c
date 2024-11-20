#include "PCH.h"

#include "autumn/autumn_app.h"
#include "pillar/pillar_app.h"
#include "pillar/pillar_base.h"

#define SDL_MAIN_HANDLED
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[])
{
    PillarAppLifecycleHook lifecycle_hook = {
        .init = &autumn_app_init,
        .update = &autumn_app_update,
        .destroy = &autumn_app_destroy,
    };

    return pillar_base_bootstrap(&lifecycle_hook);
}


#ifdef WIN32
_Use_decl_annotations_
int WINAPI WinMain(_In_ HINSTANCE h_instance, 
    _In_opt_ HINSTANCE h_prev_instance, 
    _In_ LPSTR lp_cmd_line, 
    _In_ i32 n_cmd_show)
{
    return main(__argc, __argv);
}
#else
#endif