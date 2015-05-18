#include "VisibleObject.hpp"
#include "IrrlichtEngine.hpp"

VisibleObject::VisibleObject():
    m_mesh(NULL),
    m_sceneNode(NULL),
    m_lightningEnabled(false),
    m_pos(0.0, 0.0, 0.0),
    m_rot(0.0, 0.0, 0.0),
    m_scl(1.0, 1.0, 1.0)
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


bool VisibleObject::AddObjectToScene(VisibleObject * parent)
{
    bool retVal = false;
    if (!m_sceneNode)
    {
        if (m_mesh)
        {
            if (parent)
            {
                m_sceneNode = getEng.GetSceneManager()->addAnimatedMeshSceneNode(m_mesh, parent->m_sceneNode, -1, m_pos, m_rot, m_scl);
            }
            else
            {
                m_sceneNode = getEng.GetSceneManager()->addAnimatedMeshSceneNode(m_mesh, NULL, -1, m_pos, m_rot, m_scl);
            }
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


void VisibleObject::SetPosition(vector3df pos)
{
    m_pos = pos;
}

void VisibleObject::SetRotation(vector3df rot)
{
    m_rot = rot;
}

void VisibleObject::SetScale(vector3df scl)
{
    m_scl = scl;
}
