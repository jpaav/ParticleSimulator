//
// Created by Joseph Paavola on 12/13/20.
//

#include "Object.h"

Object::Object() : position(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f), rotation(0.0f, 0.0f, 0.0f, 0.0f) {
    glGenBuffers(1, &vertexBuffer);
}

Object::~Object() {
    glDeleteBuffers(1, &vertexBuffer);
}

glm::mat4 Object::getModelMatrix() const {
    return glm::translate(position) * glm::scale(scale);
}
