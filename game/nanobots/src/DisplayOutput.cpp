#include "DisplayOutput.hpp"
#include <irrlicht.h>

DisplayOutput::DisplayOutput() : 
    m_hRes(640), 
    m_vRes(480), 
    m_Fullscreen(false), 
    m_Vsync(false), 
    m_device(NULL), 
    m_driver(NULL), 
    m_smgr(NULL), 
    m_guienv(NULL)
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

    m_device = createDevice(video::EDT_OPENGL, dimension2d<u32>(m_hRes, m_vRes), 32, m_Fullscreen, false, m_Vsync, NULL);
    if (m_device)
    {
        retVal = true;

        m_device->setWindowCaption(m_WindowCaption.c_str()); // set windows title
        m_driver = m_device->getVideoDriver();
        m_smgr = m_device->getSceneManager();
        m_guienv = m_device->getGUIEnvironment();

    }
        
    return retVal;
};