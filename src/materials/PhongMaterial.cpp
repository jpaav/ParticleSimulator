//
// Created by Joseph Paavola on 12/20/20.
//

#include "PhongMaterial.h"

PhongMaterial::PhongMaterial(glm::vec3 color, Shader *shader) : Material(color, shader) {}

void PhongMaterial::use() {
    shader->use();
    shader->setVec3("objectColor", color);
}
