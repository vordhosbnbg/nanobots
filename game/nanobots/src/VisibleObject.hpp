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
    bool AddObjectToScene();

private:
    IAnimatedMesh* m_mesh;
    IAnimatedMeshSceneNode* m_sceneNode;
    bool m_lightningEnabled;
};