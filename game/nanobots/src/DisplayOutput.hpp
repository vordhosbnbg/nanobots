#ifndef DISPLAY_OUTPUT_HPP
#define DISPLAY_OUTPUT_HPP

#include <irrlicht.h>
#include <string>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;

#define getDisp DisplayOutput::getInstance()

class DisplayOutput
{
public:
    static DisplayOutput& getInstance();
    ~DisplayOutput();

    bool SetMode();
    void SetResolution(unsigned int hRes, unsigned int vRes){ m_hRes = hRes; m_vRes = vRes; }
    void EnableFullscreen(){ m_Fullscreen = true; }
    void DisableFullscreen(){ m_Fullscreen = false; }
    void EnableVsync(){ m_Vsync = true; }
    void DisableVsync(){ m_Vsync = false; }
    void SetWindowTitle(const wchar_t * title) { m_WindowCaption = title; }
private:
    DisplayOutput();
    DisplayOutput(DisplayOutput const&);    // Don't Implement
    void operator=(DisplayOutput const&);   // Don't implement

    bool m_Vsync;
    bool m_Fullscreen;
    unsigned int m_hRes;
    unsigned int m_vRes;
    wstring m_WindowCaption;
    IrrlichtDevice *device;
};

#endif