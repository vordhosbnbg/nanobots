#include <irrlicht.h>
#include "DisplayOutput.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;



#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
    getDisp.SetResolution(1024, 768);
    getDisp.DisableFullscreen();
    getDisp.EnableVsync();
    getDisp.SetWindowTitle(L"Nanobots Game");
    getDisp.SetMode();
    while (1);

    return 0;
}

