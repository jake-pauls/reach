#include "PCH.h"

#include <iostream>
#include <windows.h>

#ifdef WIN32
_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    std::cout << "[reach] welcome to reach!" << std::endl;
    return 0;
}
#else
int main(int argc, char* argv[])
{
    std::cout < "[reach] platform not supported!" << std::endl;
    return 0;
}
#endif