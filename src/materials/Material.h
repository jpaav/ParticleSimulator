//
// Created by Joseph Paavola on 12/20/20.
//

#ifndef PARTICLESIMULATOR_MATERIAL_H
#define PARTICLESIMULATOR_MATERIAL_H


#include "Shader.h"

class Material {
public:
    glm::vec3 color;

    Material(glm::vec3 color, Shader *shader);

    virtual void use();

    Shader *shader;
};


#endif //PARTICLESIMULATOR_MATERIAL_H
