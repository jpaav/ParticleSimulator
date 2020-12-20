//
// Created by Joseph Paavola on 12/14/20.
//

#ifndef PARTICLESIMULATOR_EMPTYOBJECT_H
#define PARTICLESIMULATOR_EMPTYOBJECT_H

#include "Object.h"
#include "../viewports/Shader.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

class EmptyObject : public Object {
public:
    EmptyObject();

    void draw(Viewport *viewport) override;

private:
    constexpr static const float axisVertices[] = {
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, 1.0f,
            -1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };
    static const int vertexCount = 18;
};


#endif //PARTICLESIMULATOR_EMPTYOBJECT_H
