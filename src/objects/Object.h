//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_OBJECT_H
#define PARTICLESIMULATOR_OBJECT_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <vector>

#include "../viewports/Shader.h"
#include "../viewports/Viewport.fwd.h"
#include "../viewports/Viewport.h"

class Object {
public:
    Object();
    virtual ~Object();
    virtual void draw(Viewport *viewport) = 0;
    glm::vec3 position;
    glm::vec4 rotation;
    glm::vec3 scale;
protected:
    GLuint vertexBuffer;
    std::vector<glm::vec3> vertices;
    glm::mat4 getModelMatrix();
};


#endif //PARTICLESIMULATOR_OBJECT_H
