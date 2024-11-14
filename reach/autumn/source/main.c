#include "PCH.h"

#include "autumn_runtime.h"

#ifdef WIN32
#include <pillar/win32/win32_base.h>

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE h_instance, HINSTANCE h_prev_instance, LPSTR lp_cmd_line, i32 n_cmd_show)
{
    //const pillar::Win32Base* const base = new pillar::Win32Base();
    //autumn::App* app = new autumn::App();

    //base->Bootstrap(app, hInstance, nCmdShow);

    //delete base;
    //delete app;

    win32_base_bootstrap(h_instance, n_cmd_show);

    return 0;
}
#else
int main(int argc, char* argv[])
{
    std::cout << "[reach] platform not supported!" << std::endl;
    return 0;
}
#endif