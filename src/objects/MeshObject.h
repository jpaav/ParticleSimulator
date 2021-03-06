//
// Created by Joseph Paavola on 12/19/20.
//

#ifndef PARTICLESIMULATOR_MESHOBJECT_H
#define PARTICLESIMULATOR_MESHOBJECT_H


#include "Object.h"

class MeshObject : public Object {
public:
    explicit MeshObject(const char *objPath, Material *material);
    ~MeshObject();
    void draw(Viewport *viewport) override;
protected:
    GLuint uvBuffer;
    GLuint normalBuffer;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    Material *material;

    void loadObj(const char *objPath);
};


#endif //PARTICLESIMULATOR_MESHOBJECT_H
