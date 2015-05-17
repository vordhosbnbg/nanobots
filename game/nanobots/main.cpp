#include <irrlicht.h>
#include "DisplayOutput.hpp"
#include "VisibleObject.hpp"

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
    getDisp.SetResolution(1920, 1080);
    getDisp.EnableFullscreen();
    getDisp.EnableVsync();
    getDisp.SetWindowTitle(L"Nanobots Game");
    getDisp.SetMode();


    VisibleObject cube;
    cube.LoadMesh("../res/models/pivot_cube.obj");
    cube.AddObjectToScene();
    cube.LoadTexture("../res/textures/metal_texture_71.jpg");
    getDisp.GetSceneManager()->addCameraSceneNode(0, vector3df(0, 300, -400), vector3df(0, 5, 0));

    while (getDisp.GetDevice()->run())
    {
        /*
        Anything can be drawn between a beginScene() and an endScene()
        call. The beginScene() call clears the screen with a color and
        the depth buffer, if desired. Then we let the Scene Manager and
        the GUI Environment draw their content. With the endScene()
        call everything is presented on the screen.
        */
        getDisp.GetVideoDriver()->beginScene(true, true, SColor(255, 100, 101, 140));

        getDisp.GetSceneManager()->drawAll();
        getDisp.GetGUI()->drawAll();

        getDisp.GetVideoDriver()->endScene();
    }

    return 0;
}

