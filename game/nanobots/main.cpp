#include <irrlicht.h>
#include "IrrlichtEngine.hpp"
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
    getEng.SetResolution(1024, 768);
    getEng.DisableFullscreen();
    getEng.EnableVsync();
    getEng.SetWindowTitle(L"Nanobots Game");
    getEng.SetMode();


    VisibleObject cube;
    cube.LoadMesh("../res/models/pivot_cube.obj");
    cube.AddObjectToScene();
    cube.LoadTexture("../res/textures/metal_texture_71.jpg");
    cube.EnableLightning(true);

    VisibleObject crystal;
    crystal.LoadMesh("../res/models/crystal.obj");
    crystal.SetPosition(vector3df(155, 155, 155));
    crystal.SetScale(vector3df(100, 100, 100));
    crystal.AddObjectToScene();
    crystal.LoadTexture("../res/textures/amethyst.jpg");
    crystal.EnableLightning(true);

    getEng.GetSceneManager()->addCameraSceneNodeMaya(); //0, vector3df(0, 300, -400), vector3df(0, 5, 0)
    getEng.GetSceneManager()->addLightSceneNode(0, vector3df(100,200,300));
    //getEng.GetSceneManager()->setAmbientLight(SColorf(0xFFFFFFFF));

    while (getEng.GetDevice()->run())
    {
        /*
        Anything can be drawn between a beginScene() and an endScene()
        call. The beginScene() call clears the screen with a color and
        the depth buffer, if desired. Then we let the Scene Manager and
        the GUI Environment draw their content. With the endScene()
        call everything is presented on the screen.
        */
        getEng.GetVideoDriver()->beginScene(true, true, SColor(255, 50, 50, 50));

        getEng.GetSceneManager()->drawAll();
        getEng.GetGUI()->drawAll();

        getEng.GetVideoDriver()->endScene();
    }

    return 0;
}

