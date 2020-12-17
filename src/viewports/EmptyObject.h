//
// Created by Joseph Paavola on 12/14/20.
//

#ifndef PARTICLESIMULATOR_EMPTYOBJECT_H
#define PARTICLESIMULATOR_EMPTYOBJECT_H

#include "Object.h"
#include "Shader.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

class EmptyObject : public Object {
public:
    EmptyObject();

    void draw(glm::mat4 &cameraMatrix, Shader *shader) override;

private:
    constexpr static const float axisVertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };
};


#endif //PARTICLESIMULATOR_EMPTYOBJECT_H
