//
// Created by Joseph Paavola on 12/20/20.
//

#include "PhongMaterial.h"


void PhongMaterial::use() {
    shader->use();
    shader->setVec3("material.diffuse", color);
    shader->setVec3("material.specular", specular);
    shader->setVec3("material.ambient", ambient);
    shader->setFloat("material.shininess", shininess);
}

PhongMaterial::PhongMaterial(glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular, float shininess,
                             Shader *shader) : Material(diffuse, shader), ambient(ambient), specular(specular),
                                               shininess(shininess) {

}
