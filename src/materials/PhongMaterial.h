//
// Created by Joseph Paavola on 12/20/20.
//

#ifndef PARTICLESIMULATOR_PHONGMATERIAL_H
#define PARTICLESIMULATOR_PHONGMATERIAL_H


#include "Material.h"

class PhongMaterial : public Material {
public:
    explicit PhongMaterial(glm::vec3 color, Shader *shader);

    void use() override;
};


#endif //PARTICLESIMULATOR_PHONGMATERIAL_H
