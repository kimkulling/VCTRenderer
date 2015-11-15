#pragma once
#include "camera.h"
#include "light.h"
#include "material.h"
#include "mesh.h"
#include "texture.h"
#include "node.h"

class Scene : public SingleActive<Scene>
{
    protected:
        std::string filepath;
        std::string directory;
    public:
        std::vector<std::shared_ptr<OGLMesh>> meshes;
        std::vector<std::shared_ptr<OGLTexture2D>> textures;
        std::vector<std::shared_ptr<OGLMaterial>> materials;

        std::vector<std::shared_ptr<Camera>> cameras;
        std::vector<std::shared_ptr<Light>> lights;

        Node rootNode;

        Scene();

        std::string GetFilepath() const { return filepath; }
        std::string GetDirectory() const { return directory; }
    private:
        // friends with
        friend class SceneImporter;
};

