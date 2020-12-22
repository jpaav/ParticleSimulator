//
// Created by Joseph Paavola on 12/20/20.
//

#include "PhysicsViewport.h"

glm::vec3 exampleField(float x, float y, float z) {
    return glm::vec3(x * y * z);
}

void PhysicsViewport::render() {
    renderSetup();
    // Draw a basic vector field
    drawVectorField(5, 1.0, exampleField);
    renderObjects();
    renderTeardown();
}

void PhysicsViewport::drawVectorField(int stepCount, float stepSize, glm::vec3 (*vectorField)(float, float, float)) {
    auto outputVertices = std::vector<glm::vec3>();
    auto startPosition = glm::vec3(-(float(stepCount) * stepSize) / 2);
    glm::vec3 input;
    for (int xIndex = 0; xIndex < stepCount; xIndex++) {
        for (int yIndex = 0; yIndex < stepCount; yIndex++) {
            for (int zIndex = 0; zIndex < stepCount; zIndex++) {
                input = glm::vec3(startPosition.x + xIndex * stepSize, startPosition.y + yIndex * stepSize, startPosition.z + zIndex * stepSize);
                glm::vec3 outputVector = glm::normalize(vectorField(input.x, input.y, input.z));
                outputVertices.push_back(input);
                outputVertices.push_back(input+outputVector);
            }
        }
    }
    this->getShader("simple")->use();
    this->getShader("simple")->setMatrix("model", glm::translate(glm::vec3(0)));
    this->getShader("simple")->setMatrix("camera", this->getCameraMatrix());
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, outputVertices.size() * sizeof(glm::vec3), outputVertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,          // Attribute 0. must match shader layout
            3,          // size
            GL_FLOAT,   // type
            GL_FALSE,   // normalized?
            0,          // stride
            (void *) 0  // array buffer offset
    );
    glDrawArrays(GL_LINES, 0, outputVertices.size());

    glDisableVertexAttribArray(0);
    glDeleteBuffers(1, &buffer);
}

PhysicsViewport::PhysicsViewport(const char *name, int width, int height) : Viewport(name, width, height) {

}
