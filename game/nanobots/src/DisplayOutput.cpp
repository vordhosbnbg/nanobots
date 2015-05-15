#include "DisplayOutput.hpp"
#include <irrlicht.h>

DisplayOutput::DisplayOutput() : m_hRes(640), m_vRes(480), m_Fullscreen(false), m_Vsync(false)
{
    //Constructor
}

DisplayOutput::~DisplayOutput()
{
    //Destructor
}


DisplayOutput& DisplayOutput::getInstance()
{
    static DisplayOutput instance;

    return instance;
}


bool DisplayOutput::SetMode()
{
    bool retVal = false;

    device = createDevice(video::EDT_OPENGL, dimension2d<u32>(m_hRes, m_vRes), 32, m_Fullscreen, false, m_Vsync, NULL);
    if (device)
    {
        retVal = true;
    }
        
    return retVal;
};