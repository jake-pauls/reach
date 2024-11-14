#include "PCH.h"

#include "autumn_app.h"

#ifdef WIN32
#include <pillar/pillar_app.h>
#include <pillar/win32/win32_base.h>

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE h_instance, HINSTANCE h_prev_instance, LPSTR lp_cmd_line, i32 n_cmd_show)
{
    PillarAppLifecycleHook lifecycle_hook = {
        .init = &autumn_app_init,
        .update = &autumn_app_update,
        .destroy = &autumn_app_destroy,
    };

    win32_base_bootstrap(h_instance, n_cmd_show, &lifecycle_hook);

    return 0;
}
#else
int main(int argc, char* argv[])
{
    std::cout << "[reach] platform not supported!" << std::endl;
    return 0;
}
#endif