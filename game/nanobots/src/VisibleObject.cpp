#include "VisibleObject.hpp"
#include "IrrlichtEngine.hpp"

VisibleObject::VisibleObject():
    m_mesh(NULL),
    m_sceneNode(NULL),
    m_lightningEnabled(false)
{

}

VisibleObject::~VisibleObject()
{
}

bool VisibleObject::LoadMesh(const char * pathToMesh)
{
    bool retVal = false;
    if (!m_mesh)
    {
        m_mesh = getEng.GetSceneManager()->getMesh(pathToMesh);
        if (m_mesh)
        {
            retVal = true;
        }
    }

    return retVal;
}

bool VisibleObject::LoadTexture(const char * pathToTexture)
{
    bool retVal = false;
    if (m_sceneNode)
    {
        m_sceneNode->setMaterialTexture(0, getEng.GetVideoDriver()->getTexture(pathToTexture));
    }
    return retVal;
}


bool VisibleObject::AddObjectToScene()
{
    bool retVal = false;
    if (!m_sceneNode)
    {
        if (m_mesh)
        {
            m_sceneNode = getEng.GetSceneManager()->addAnimatedMeshSceneNode(m_mesh);
            if (m_sceneNode)
            {
                m_sceneNode->setMaterialFlag(EMF_LIGHTING, m_lightningEnabled);
                retVal = true;
            }
        }
    }

    return retVal;
}

void VisibleObject::EnableLightning(bool value)
{
    m_lightningEnabled = value;
}
