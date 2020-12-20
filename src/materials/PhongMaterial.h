//
// Created by Joseph Paavola on 12/20/20.
//

#ifndef PARTICLESIMULATOR_PHONGMATERIAL_H
#define PARTICLESIMULATOR_PHONGMATERIAL_H


#include "Material.h"

class PhongMaterial : public Material {
private:
    glm::vec3 ambient;
    glm::vec3 specular;
    float shininess;
public:
    PhongMaterial(glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular, float shininess, Shader *shader);

    void use() override;
};


#endif //PARTICLESIMULATOR_PHONGMATERIAL_H
