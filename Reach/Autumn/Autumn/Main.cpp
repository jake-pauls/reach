#include "PCH.h"

#include "App.h"

#include <iostream>

#ifdef WIN32
#include <Pillar/Win32/Win32Base.h>

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, i32 nCmdShow)
{
    const pillar::Win32Base* const base = new pillar::Win32Base();
    autumn::App* app = new autumn::App();

    base->Bootstrap(app, hInstance, nCmdShow);

    delete base;
    delete app;

    return 0;
}
#else
int main(int argc, char* argv[])
{
    std::cout << "[reach] platform not supported!" << std::endl;
    return 0;
}
#endif