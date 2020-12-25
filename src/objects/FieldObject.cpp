//
// Created by Joseph Paavola on 12/24/20.
//

#include "FieldObject.h"
#include "../utility.h"

glm::vec3 exampleField(glm::vec3 input) {
//    return glm::vec3(input.x * input.y, input.y * input.z, input.z * input.x);
    return glm::vec3(input.x, input.y, glm::sin(input.z));
}

FieldObject::FieldObject(int stepCount, float stepSize, int iterationCount, bool drawArrowHeads) : FieldObject(stepCount, stepSize, iterationCount) {
    this->drawArrowHeads = drawArrowHeads;
}

FieldObject::FieldObject(int stepCount, float stepSize, int iterationCount)
        : Object(), stepCount(stepCount), stepSize(stepSize),
          iterationCount(iterationCount), drawArrowHeads(false) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    vertices = std::vector<glm::vec3>();
    glBufferData(GL_ARRAY_BUFFER, 0, vertices.data(), GL_DYNAMIC_DRAW);
}

void FieldObject::draw(Viewport *viewport) {
    compute();
    viewport->getShader("simple")->use();
    viewport->getShader("simple")->setMatrix("model", glm::translate(glm::vec3(0)));
    viewport->getShader("simple")->setMatrix("camera", viewport->getCameraMatrix());
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,          // Attribute 0. must match shader layout
            3,          // size
            GL_FLOAT,   // type
            GL_FALSE,   // normalized?
            0,          // stride
            (void *) 0  // array buffer offset
    );
    glDrawArrays(GL_LINES, 0, vertices.size());

    glDisableVertexAttribArray(0);
}

void FieldObject::compute() {
    vertices.clear();
    auto startPosition = glm::vec3(-(float(stepCount) * stepSize) / 2);
    glm::vec3 input, output;
    for (int xIndex = 0; xIndex < stepCount; xIndex++) {
        for (int yIndex = 0; yIndex < stepCount; yIndex++) {
            for (int zIndex = 0; zIndex < stepCount; zIndex++) {
                input = glm::vec3(startPosition.x + xIndex * stepSize,
                                  startPosition.y + yIndex * stepSize,
                                  startPosition.z + zIndex * stepSize
                );
                if (iterationCount > 0) {
                    for (int iterationIndex = 0; iterationIndex < iterationCount; iterationIndex++) {
                        output = glm::normalize(derivative(input, exampleField, SMALL_H)) * stepSize;
                        // Line vertices
                        vertices.push_back(input);
                        vertices.push_back(input + output);
                        // Arrow head vertices
                        if (drawArrowHeads) {
                            glm::vec3 arrowHeadPoint = interpolate(input + output, input, 0.8f);
                            glm::vec3 normal = glm::normalize(
                                    glm::cross(arrowHeadPoint, arrowHeadPoint * glm::vec3(1.0f, 2.0f, 3.0f))
                            );
                            vertices.push_back(arrowHeadPoint + 0.2f * normal);
                            vertices.push_back(input + output);
                            vertices.push_back(arrowHeadPoint - 0.2f * normal);
                            vertices.push_back(input + output);
                        }
                        input = glm::vec3(input + output);
                    }
                } else {
                    output = glm::normalize(exampleField(input)) * stepSize;
                    // Line vertices
                    vertices.push_back(input);
                    vertices.push_back(input + output);
                    // Arrow head vertices
                    if (drawArrowHeads) {
                        glm::vec3 arrowHeadPoint = input + (output * 0.8f);
                        glm::vec3 normal = glm::normalize(
                                glm::cross(arrowHeadPoint, arrowHeadPoint * glm::vec3(1.0f, 2.0f, 3.0f))
                        );
                        vertices.push_back(arrowHeadPoint + 0.2f * normal);
                        vertices.push_back(input + output);
                        vertices.push_back(arrowHeadPoint - 0.2f * normal);
                        vertices.push_back(input + output);
                    }
                }
            }
        }
    }
}

glm::vec3 FieldObject::derivative(glm::vec3 x, glm::vec3 (*f)(glm::vec3), float h) {
    return (f(x + h) - f(x-h)) / (2.0f * h);
}
