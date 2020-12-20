//
// Created by Joseph Paavola on 12/20/20.
//

#ifndef PARTICLESIMULATOR_LIGHT_H
#define PARTICLESIMULATOR_LIGHT_H


#include <glm/glm.hpp>

// TODO: create multiple types of light that inherit from this one
class Light {
public:
    Light();
    glm::vec3 position;
    glm::vec3 color;
    float intensity;
};


#endif //PARTICLESIMULATOR_LIGHT_H
