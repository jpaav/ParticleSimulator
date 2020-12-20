//
// Created by Joseph Paavola on 12/20/20.
//

#include "Material.h"

Material::Material(glm::vec3 color, Shader *shader) : color(color), shader(shader) {}

void Material::use() {
    shader->use();
    shader->setVec3("objectColor", color);
}
