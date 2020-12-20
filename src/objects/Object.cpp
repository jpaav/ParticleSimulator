//
// Created by Joseph Paavola on 12/13/20.
//

#include "Object.h"

Object::Object() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
    rotation = glm::vec4(0.0f,0.0f,0.0f,0.0f);

    glGenBuffers(1, &vertexBuffer);
}

Object::~Object() {
    glDeleteBuffers(1, &vertexBuffer);
}

glm::mat4 Object::getModelMatrix() {
    return glm::translate(position) * glm::scale(scale);
}
