//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_OBJECT_H
#define PARTICLESIMULATOR_OBJECT_H

#include "GLFW/glfw3.h"
#include <glm/glm.hpp>

class Object {
public:
    Object();
    virtual void draw() = 0;
    glm::vec3 position;
    glm::vec4 rotation;
    glm::vec3 scale;
};


#endif //PARTICLESIMULATOR_OBJECT_H
