#ifndef IRRLICHT_ENGINE_HPP
#define IRRLICHT_ENGINE_HPP

#include <irrlicht.h>
#include <string>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;

#define getEng IrrlichtEngine::getInstance()

class IrrlichtEngine
{
public:
    static IrrlichtEngine& getInstance();
    ~IrrlichtEngine();

    bool SetMode();
    void SetResolution(unsigned int hRes, unsigned int vRes){ m_hRes = hRes; m_vRes = vRes; }
    void EnableFullscreen(){ m_Fullscreen = true; }
    void DisableFullscreen(){ m_Fullscreen = false; }
    void EnableVsync(){ m_Vsync = true; }
    void DisableVsync(){ m_Vsync = false; }
    void SetWindowTitle(const wchar_t * title) { m_WindowCaption = title; }
    inline IrrlichtDevice* GetDevice(){ return m_device; }
    inline IVideoDriver* GetVideoDriver(){ return m_driver; }
    inline ISceneManager* GetSceneManager(){ return m_smgr; }
    inline IGUIEnvironment* GetGUI(){ return m_guienv; }
private:
    IrrlichtEngine();
    IrrlichtEngine(IrrlichtEngine const&);    // Don't Implement
    void operator=(IrrlichtEngine const&);   // Don't implement

    bool m_Vsync;
    bool m_Fullscreen;
    unsigned int m_hRes;
    unsigned int m_vRes;
    wstring m_WindowCaption;
    IrrlichtDevice* m_device;
    IVideoDriver* m_driver;
    ISceneManager* m_smgr;
    IGUIEnvironment* m_guienv;
};

#endif