#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class VisibleObject
{
public:
    VisibleObject();
    ~VisibleObject();

    bool LoadMesh(const char * pathToMesh);
    bool LoadTexture(const char * pathToTexture);
    bool AddObjectToScene(VisibleObject * parent = NULL);
    void EnableLightning(bool value);
    void SetPosition(vector3df pos);
    void SetRotation(vector3df rot);
    void SetScale(vector3df scl);

private:
    IAnimatedMesh* m_mesh;
    IAnimatedMeshSceneNode* m_sceneNode;
    bool m_lightningEnabled;
    vector3df m_pos;
    vector3df m_rot;
    vector3df m_scl;
};